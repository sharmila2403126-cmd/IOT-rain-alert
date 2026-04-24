
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Blynk credentials
char auth[] = "YOUR_BLYNK_AUTH_TOKEN";
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

int rainPin = 34;   // Digital/Analog pin from rain sensor

void setup() {
  Serial.begin(9600);
  pinMode(rainPin, INPUT);

  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();

  int rainValue = digitalRead(rainPin); // 0 = rain, 1 = no rain (depends on module)

  Serial.print("Rain Status: ");
  Serial.println(rainValue);

  if (rainValue == 0) {
    Serial.println("Rain Detected!");

    // Send notification
    Blynk.logEvent("rain_alert", "🌧️ Rain Detected!");

    delay(5000); // Avoid spamming notifications
  }

  delay(1000);
}
