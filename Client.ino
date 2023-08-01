#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "SSIDNAME";
const char* password = "PASSWORD";

WiFiClient wifiClient;

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
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
    HTTPClient http;

    http.begin(wifiClient, "http://192.168.243.1/post"); //Specify request destination
    http.addHeader("Content-Type", "text/plain"); //Specify content-type header

    int httpCode = http.POST("MESSAGE"); //Send the request
    String payload = http.getString(); //Get the response payload

    Serial.println(httpCode); //Print HTTP return code
    Serial.println(payload); //Print request response payload

    http.end(); //Close connection
  }

  delay(1000); //Send a request every second
}
