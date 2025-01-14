#include <string>
#include <map>
#include "../temp_libs/json.hpp"
#include "../client.hpp"
#include "../exception.hpp"
#include "../service.hpp"
#include "account.hpp"

using string = std::string;
using json = nlohmann::json;

namespace Appwrite {
/*
 * Get Account
 *
     * Get currently logged in user data as JSON object.
 * @throws AppwriteException
 * @return array
 */
json Account::get() {
    json params = {
    };
    json headers = {
        {"content-type", "application/json"},
    };
    string path = "/account";
    size_t pos;
    string searchString;

    return this->client->call(Client::METHOD_GET, path, headers, params);
}

/*
 * Delete Account
 *
     * Delete a currently logged in user account. Behind the scene, the user
     * record is not deleted but permanently blocked from any access. This is done
     * to avoid deleted accounts being overtaken by new users with the same email
     * address. Any user-related resources like documents or storage files should
     * be deleted separately.
 * @throws AppwriteException
 * @return array
 */
json Account::delete() {
    json params = {
    };
    json headers = {
        {"content-type", "application/json"},
    };
    string path = "/account";
    size_t pos;
    string searchString;

    return this->client->call(Client::METHOD_DELETE, path, headers, params);
}

/*
 * Update Account Email
 *
     * Update currently logged in user account email address. After changing user
     * address, user confirmation status is being reset and a new confirmation
     * mail is sent. For security measures, user password is required to complete
     * this request.
     * This endpoint can also be used to convert an anonymous account to a normal
     * one, by passing an email address and a new password.
 * @param string email
 * @param string password
 * @throws AppwriteException
 * @return array
 */
json Account::updateEmail(string email, string password) {
    json params = {
        {"email", email},
        {"password", password},
    };
    json headers = {
        {"content-type", "application/json"},
    };
    string path = "/account/email";
    size_t pos;
    string searchString;

    return this->client->call(Client::METHOD_PATCH, path, headers, params);
}

/*
 * Get Account Logs
 *
     * Get currently logged in user list of latest security activity logs. Each
     * log returns user IP address, location and date and time of log.
 * @throws AppwriteException
 * @return array
 */
json Account::getLogs() {
    json params = {
    };
    json headers = {
        {"content-type", "application/json"},
    };
    string path = "/account/logs";
    size_t pos;
    string searchString;

    return this->client->call(Client::METHOD_GET, path, headers, params);
}

/*
 * Update Account Name
 *
     * Update currently logged in user account name.
 * @param string name
 * @throws AppwriteException
 * @return array
 */
json Account::updateName(string name) {
    json params = {
        {"name", name},
    };
    json headers = {
        {"content-type", "application/json"},
    };
    string path = "/account/name";
    size_t pos;
    string searchString;

    return this->client->call(Client::METHOD_PATCH, path, headers, params);
}

/*
 * Update Account Password
 *
     * Update currently logged in user password. For validation, user is required
     * to pass in the new password, and the old password. For users created with
     * OAuth and Team Invites, oldPassword is optional.
 * @param string password
 * @param string oldPassword
 * @throws AppwriteException
 * @return array
 */
json Account::updatePassword(string password, string oldPassword) {
    json params = {
        {"password", password},
        {"oldPassword", oldPassword},
    };
    json headers = {
        {"content-type", "application/json"},
    };
    string path = "/account/password";
    size_t pos;
    string searchString;

    return this->client->call(Client::METHOD_PATCH, path, headers, params);
}

/*
 * Get Account Preferences
 *
     * Get currently logged in user preferences as a key-value object.
 * @throws AppwriteException
 * @return array
 */
json Account::getPrefs() {
    json params = {
    };
    json headers = {
        {"content-type", "application/json"},
    };
    string path = "/account/prefs";
    size_t pos;
    string searchString;

    return this->client->call(Client::METHOD_GET, path, headers, params);
}

/*
 * Update Account Preferences
 *
     * Update currently logged in user account preferences. You can pass only the
     * specific settings you wish to update.
 * @param json prefs
 * @throws AppwriteException
 * @return array
 */
json Account::updatePrefs(json prefs) {
    json params = {
        {"prefs", prefs},
    };
    json headers = {
        {"content-type", "application/json"},
    };
    string path = "/account/prefs";
    size_t pos;
    string searchString;

    return this->client->call(Client::METHOD_PATCH, path, headers, params);
}

/*
 * Create Password Recovery
 *
     * Sends the user an email with a temporary secret key for password reset.
     * When the user clicks the confirmation link he is redirected back to your
     * app password reset URL with the secret key and email address values
     * attached to the URL query string. Use the query string params to submit a
     * request to the [PUT
     * /account/recovery](/docs/client/account#accountUpdateRecovery) endpoint to
     * complete the process. The verification link sent to the user's email
     * address is valid for 1 hour.
 * @param string email
 * @param string url
 * @throws AppwriteException
 * @return array
 */
json Account::createRecovery(string email, string url) {
    json params = {
        {"email", email},
        {"url", url},
    };
    json headers = {
        {"content-type", "application/json"},
    };
    string path = "/account/recovery";
    size_t pos;
    string searchString;

    return this->client->call(Client::METHOD_POST, path, headers, params);
}

/*
 * Create Password Recovery (confirmation)
 *
     * Use this endpoint to complete the user account password reset. Both the
     * **userId** and **secret** arguments will be passed as query parameters to
     * the redirect URL you have provided when sending your request to the [POST
     * /account/recovery](/docs/client/account#accountCreateRecovery) endpoint.
     * 
     * Please note that in order to avoid a [Redirect
     * Attack](https://github.com/OWASP/CheatSheetSeries/blob/master/cheatsheets/Unvalidated_Redirects_and_Forwards_Cheat_Sheet.md)
     * the only valid redirect URLs are the ones from domains you have set when
     * adding your platforms in the console interface.
 * @param string userId
 * @param string secret
 * @param string password
 * @param string passwordAgain
 * @throws AppwriteException
 * @return array
 */
json Account::updateRecovery(string userId, string secret, string password, string passwordAgain) {
    json params = {
        {"userId", userId},
        {"secret", secret},
        {"password", password},
        {"passwordAgain", passwordAgain},
    };
    json headers = {
        {"content-type", "application/json"},
    };
    string path = "/account/recovery";
    size_t pos;
    string searchString;

    return this->client->call(Client::METHOD_PUT, path, headers, params);
}

/*
 * Get Account Sessions
 *
     * Get currently logged in user list of active sessions across different
     * devices.
 * @throws AppwriteException
 * @return array
 */
json Account::getSessions() {
    json params = {
    };
    json headers = {
        {"content-type", "application/json"},
    };
    string path = "/account/sessions";
    size_t pos;
    string searchString;

    return this->client->call(Client::METHOD_GET, path, headers, params);
}

/*
 * Delete All Account Sessions
 *
     * Delete all sessions from the user account and remove any sessions cookies
     * from the end client.
 * @throws AppwriteException
 * @return array
 */
json Account::deleteSessions() {
    json params = {
    };
    json headers = {
        {"content-type", "application/json"},
    };
    string path = "/account/sessions";
    size_t pos;
    string searchString;

    return this->client->call(Client::METHOD_DELETE, path, headers, params);
}

/*
 * Get Session By ID
 *
     * Use this endpoint to get a logged in user's session using a Session ID.
     * Inputting 'current' will return the current session being used.
 * @param string sessionId
 * @throws AppwriteException
 * @return array
 */
json Account::getSession(string sessionId) {
    json params = {
    };
    json headers = {
        {"content-type", "application/json"},
    };
    string path = "/account/sessions/{sessionId}";
    size_t pos;
    string searchString;
    searchString = "{sessionId}";
    pos = path.find(searchString);
    if (pos != std::string::npos)
        path = path.replace(pos, searchString.length(), "sessionId");

    return this->client->call(Client::METHOD_GET, path, headers, params);
}

/*
 * Delete Account Session
 *
     * Use this endpoint to log out the currently logged in user from all their
     * account sessions across all of their different devices. When using the
     * option id argument, only the session unique ID provider will be deleted.
 * @param string sessionId
 * @throws AppwriteException
 * @return array
 */
json Account::deleteSession(string sessionId) {
    json params = {
    };
    json headers = {
        {"content-type", "application/json"},
    };
    string path = "/account/sessions/{sessionId}";
    size_t pos;
    string searchString;
    searchString = "{sessionId}";
    pos = path.find(searchString);
    if (pos != std::string::npos)
        path = path.replace(pos, searchString.length(), "sessionId");

    return this->client->call(Client::METHOD_DELETE, path, headers, params);
}

/*
 * Create Email Verification
 *
     * Use this endpoint to send a verification message to your user email address
     * to confirm they are the valid owners of that address. Both the **userId**
     * and **secret** arguments will be passed as query parameters to the URL you
     * have provided to be attached to the verification email. The provided URL
     * should redirect the user back to your app and allow you to complete the
     * verification process by verifying both the **userId** and **secret**
     * parameters. Learn more about how to [complete the verification
     * process](/docs/client/account#accountUpdateVerification). The verification
     * link sent to the user's email address is valid for 7 days.
     * 
     * Please note that in order to avoid a [Redirect
     * Attack](https://github.com/OWASP/CheatSheetSeries/blob/master/cheatsheets/Unvalidated_Redirects_and_Forwards_Cheat_Sheet.md),
     * the only valid redirect URLs are the ones from domains you have set when
     * adding your platforms in the console interface.
     * 
 * @param string url
 * @throws AppwriteException
 * @return array
 */
json Account::createVerification(string url) {
    json params = {
        {"url", url},
    };
    json headers = {
        {"content-type", "application/json"},
    };
    string path = "/account/verification";
    size_t pos;
    string searchString;

    return this->client->call(Client::METHOD_POST, path, headers, params);
}

/*
 * Create Email Verification (confirmation)
 *
     * Use this endpoint to complete the user email verification process. Use both
     * the **userId** and **secret** parameters that were attached to your app URL
     * to verify the user email ownership. If confirmed this route will return a
     * 200 status code.
 * @param string userId
 * @param string secret
 * @throws AppwriteException
 * @return array
 */
json Account::updateVerification(string userId, string secret) {
    json params = {
        {"userId", userId},
        {"secret", secret},
    };
    json headers = {
        {"content-type", "application/json"},
    };
    string path = "/account/verification";
    size_t pos;
    string searchString;

    return this->client->call(Client::METHOD_PUT, path, headers, params);
}
} // namespace Appwrite
