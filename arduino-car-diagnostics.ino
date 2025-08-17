#include <WiFi.h>
#include "config.h"

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("Arduino Car Diagnostics - WiFi Connection Test");
  Serial.println("=============================================");
  
  // Connect to WiFi
  setupWiFi();
}

void loop() {
  // Check WiFi connection status every 10 seconds
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WiFi Status: Connected");
    Serial.println("IP Address: " + WiFi.localIP().toString());
    Serial.println("Signal Strength (RSSI): " + String(WiFi.RSSI()) + " dBm");
  } else {
    Serial.println("WiFi Status: Disconnected");
    Serial.println("Attempting to reconnect...");
    setupWiFi();
  }
  
  delay(10000); // Check every 10 seconds
}

void setupWiFi() {
  Serial.println("Connecting to WiFi...");
  Serial.println("SSID: " + String(WIFI_SSID));
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(500);
    Serial.print(".");
    attempts++;
  }
  
  Serial.println();
  
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WiFi connection successful!");
    Serial.println("IP Address: " + WiFi.localIP().toString());
    Serial.println("Gateway: " + WiFi.gatewayIP().toString());
    Serial.println("Subnet: " + WiFi.subnetMask().toString());
    Serial.println("DNS: " + WiFi.dnsIP().toString());
  } else {
    Serial.println("WiFi connection failed!");
    Serial.println("Please check your SSID and password in config.h");
  }
}
