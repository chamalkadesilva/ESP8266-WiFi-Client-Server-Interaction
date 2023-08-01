#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80); //Server on port 80

const char* ssid = "SSIDNAME";
const char* password = "PASSWORD";

void handleRoot() {
  server.send(200, "text/plain", "Hello from the ESP8266!");
}

void handlePost() {
  if(server.hasArg("plain")== false){ //Check if body received
    server.send(200, "text/plain", "Body not received");
    return;
  }
  
  String message = server.arg("plain"); //Get the body
  Serial.println(message); //Print the body
  
  server.send(200, "text/plain", "Body received");
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/post", HTTP_POST, handlePost); //Define endpoint for POST method
  server.begin(); //Start server
}

void loop() {
  server.handleClient();
}
