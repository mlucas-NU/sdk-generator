import io.appwrite.Client
import io.appwrite.services.Account

suspend fun main() {
    val client = Client(context)
      .setEndpoint("https://[HOSTNAME_OR_IP]/v1") // Your API Endpoint
      .setProject("5df5acd0d48c2") // Your project ID

    val account = Account(client)
    val response = account.updateMagicURLSession(
        userId = "[USER_ID]",
        secret = "[SECRET]"
    )
    val json = response.body?.string()
}