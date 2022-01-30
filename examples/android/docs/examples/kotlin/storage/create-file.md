import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import kotlinx.coroutines.GlobalScope
import kotlinx.coroutines.launch
import io.appwrite.Client
import io.appwrite.services.Storage

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val client = Client(applicationContext)
            .setEndpoint("https://[HOSTNAME_OR_IP]/v1") // Your API Endpoint
            .setProject("5df5acd0d48c2") // Your project ID
            .setKey("919c2d18fb5d4...a2ae413da83346ad2") // Your secret API key

        val storage = Storage(client)

        GlobalScope.launch {
            val response = storage.createFile(
                file = File("./path-to-files/image.jpg"),
            )
            val json = response.body?.string()        
        }
    }
}