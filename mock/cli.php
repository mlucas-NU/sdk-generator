<?php

var_dump($argv);


/*

docker run -it --rm \
    --volume "$(pwd)":/source:rw \
    -w /source \
    php:7.4.8-cli-alpine php cli.php --filters

docker run -it --rm \
        --volume "$(pwd)":/code:rw \
    appwrite/cli functions createTag \
        --functionId=5e63e0a61d9c2
        --env=nodejs-14
        --command="node main.js"
        --code=.
 */

if ( !posix_isatty(STDOUT) ) {
    fwrite(STDOUT, "Invalid TTY\n");
    exit(2);
}
fwrite(STDOUT, "Enter you name\n");
$name = fgets(STDIN);
fwrite(STDOUT,"Hello $name\n");
exit(0);