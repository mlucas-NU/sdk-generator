FROM composer:2.0 as step0

WORKDIR /usr/local/src/

COPY composer.lock /usr/local/src/
COPY composer.json /usr/local/src/

RUN composer update --ignore-platform-reqs --optimize-autoloader \
    --no-plugins --no-scripts --prefer-dist --no-dev

FROM php:7.4.8-cli-alpine as final

LABEL maintainer="team@appwrite.io"

ENV _APP_SERVER=swoole \
    _APP_ENV=production

RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN \
  apk add htop

RUN docker-php-ext-install curl opcache

WORKDIR /usr/src/code

COPY --from=step0 /usr/local/src/vendor /usr/src/code/vendor

# Add Source Code
COPY ./bin /usr/local/bin
COPY ./src /usr/src/code/src

# Executables
RUN chmod +x /usr/local/bin/help
# RUN chmod +x /usr/local/bin/client
# RUN chmod +x /usr/local/bin/users
# RUN chmod +x /usr/local/bin/storage
# RUN chmod +x /usr/local/bin/functions

CMD [ "php", "help"]