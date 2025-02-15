#include <algorithm>
#include <string>
#include "client.hpp"
#include "temp_libs/json.hpp"

using json = nlohmann::json;
using string = std::string;

namespace Appwrite {

/**
 * SDK constructor.
 */
Client::Client() { }

/**
 * SDK destructor
 */
Client::~Client() {
    // TODO?
}

/**
 * Set Project
 *
 * Your project ID
 *
 * @param string value
 *
 * @return Client
 */
Client& Client::setProject(string value) {
    this->addHeader("X-Appwrite-Project", value);
    return *this;
}

/**
 * Set Key
 *
 * Your secret API key
 *
 * @param string value
 *
 * @return Client
 */
Client& Client::setKey(string value) {
    this->addHeader("X-Appwrite-Key", value);
    return *this;
}

/**
 * Set JWT
 *
 * Your secret JSON Web Token
 *
 * @param string value
 *
 * @return Client
 */
Client& Client::setJWT(string value) {
    this->addHeader("X-Appwrite-JWT", value);
    return *this;
}

/**
 * Set Locale
 *
 * @param string value
 *
 * @return Client
 */
Client& Client::setLocale(string value) {
    this->addHeader("X-Appwrite-Locale", value);
    return *this;
}

/***
 * @param bool status
 * @return *this
 */
Client& Client::setSelfSigned(bool status) {
    this->selfSigned = status;
    return *this;
}

/***
 * @param endpoint
 * @return *this
 */
Client& Client::setEndpoint(string endpoint) {
    this->endpoint = endpoint;
    return *this;
}

/**
 * @param key
 * @param value
 * @return *this
 */
Client& Client::addHeader(string key, string value) {
    string keyLower = key;
    std::transform(keyLower.begin(), keyLower.end(), keyLower.begin(), ::tolower);
    this->headers[keyLower] = value;
    return *this;
}

/**
 * Call
 *
 * Make an API call
 *
 * @param string method
 * @param string path
 * @param array params
 * @param array headers
 * @return array|string  // TODO: Returning JSON (instead of array), but not string.
 * @throws AppwriteException
 */
json Client::call(string method, string path, json headers, json params) {
    return json({{"fake response", "will fix soon (TM)" }});
/*
    ch = curl_init(this->endpoint + path + ((method == self::METHOD_GET && !empty(params)) ? "?" . http_build_query(params) : ""));
    json responseHeaders;
    int responseStatus = -1;
    string responseType;
    string responseBody;

    // Merge header parameters into Client's existing headers, overwriting any collisions
    json call_headers(this->headers);
    call_headers.merge_patch(headers);

    switch (headers["content-type"]) {
        case "application/json":
            query = json_encode(params);
            break;

        case "multipart/form-data":
            query = ((json) params).flatten();
            break;

        default:
            query = http_build_query(params);
            break;
    }

    foreach(headers as i => header) {
        headers[] = i . ":" . header;
        unset(headers[i]);
    }

    curl_setopt(ch, CURLOPT_CUSTOMREQUEST, method);
    curl_setopt(ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt(ch, CURLOPT_USERAGENT, php_uname("s") . "-" . php_uname("r") . ":c++-" . phpversion());
    curl_setopt(ch, CURLOPT_HTTPHEADER, headers);
    curl_setopt(ch, CURLOPT_FOLLOWLOCATION, true);
    curl_setopt(ch, CURLOPT_HEADERFUNCTION, function(curl, header) use (&responseHeaders) {
        len = strlen(header);
        header = explode(":", strtolower(header), 2);

        if (count(header) < 2) { // ignore invalid headers
            return len;
        }

        responseHeaders[strtolower(trim(header[0]))] = trim(header[1]);

        return len;
    });

    if (method != self::METHOD_GET) {
        curl_setopt(ch, CURLOPT_POSTFIELDS, query);
    }

    // Allow self signed certificates
    if (this->selfSigned) {
        curl_setopt(ch, CURLOPT_SSL_VERIFYHOST, false);
        curl_setopt(ch, CURLOPT_SSL_VERIFYPEER, false);
    }

    responseBody   = curl_exec(ch);
    responseType   = responseHeaders["content-type"] ?? "";
    responseStatus = curl_getinfo(ch, CURLINFO_HTTP_CODE);

    switch (substr(responseType, 0, strpos(responseType, ";"))) {
        case "application/json":
            responseBody = json_decode(responseBody, true);
        break;
    }

    if (curl_errno(ch)) {
        throw new AppwriteException(curl_error(ch), responseStatus, responseBody);
    }

    curl_close(ch);

    if (responseStatus >= 400) {
        if (is_array(responseBody)) {
            throw new AppwriteException(responseBody["message"], responseStatus, responseBody);
        } else {
            throw new AppwriteException(responseBody, responseStatus);
        }
    }


    return responseBody;
*/
}
} // namespace Appwrite
