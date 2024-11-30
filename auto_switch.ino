#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

#define FIREBASE_HOST "https://autoswitch-b5b8c-default-rtdb.firebaseio.com/"     // URL from realtime database in the project
#define FIREBASE_AUTH "4PLKK2OsAOk91qWe97KrdvsT7kMu2BFLapLwiVMr"       // AUTHcode of the project
#define WIFI_SSID "GTPL501"        // wifiname
#define WIFI_PASSWORD "mayank12345678"       // wifi password

// Define relay pin
#define RELAY_PIN D1

FirebaseData firebaseData;

void setup() {
  Serial.begin(115200);

  // Initialize relay pin
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Turn off relay initially

  // Connect to Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Connected to Wi-Fi");

  // Connect to Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  // Fetch data from Firebase
  if (Firebase.getJSON(firebaseData, "/laptop_battery")) {
    FirebaseJson json = firebaseData.jsonObject();
    String jsonString;
    json.toString(jsonString, true); // Convert FirebaseJson object to a String
    Serial.println("Firebase Data: " + jsonString);

    // Extract battery level and plugged status
    FirebaseJsonData batteryLevelData;
    FirebaseJsonData isPluggedData;

    if (json.get(batteryLevelData, "/battery_level") && 
        json.get(isPluggedData, "/is_plugged")) {

        // Extract values
        int battery_level = batteryLevelData.intValue;
        bool is_plugged = isPluggedData.boolValue;

        // Log data
        Serial.print("Battery Level: ");
        Serial.println(battery_level);
        Serial.print("Plugged In: ");
        Serial.println(is_plugged);

        // Control relay
        if (battery_level <= 20 && !is_plugged) {
            digitalWrite(RELAY_PIN, LOW); // Turn relay on
            Serial.println("Relay ON - Charging Started");
        } else if (battery_level >= 100) {
            digitalWrite(RELAY_PIN, HIGH); // Turn relay off
            Serial.println("Relay OFF - Charging Stopped");
        }
    } else {
      Serial.println("Failed to retrieve specific data from JSON.");
    }
  } else {
    Serial.println("Failed to fetch data from Firebase");
  }

  delay(10000); // Check every 10 seconds
}
