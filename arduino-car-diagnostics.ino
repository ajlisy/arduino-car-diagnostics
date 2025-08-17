#include <WiFi.h>
#include "config.h"

// Pin definitions for motors
#define IN1 16
#define IN2 17
#define IN3 18
#define IN4 19

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  // Initialize motor pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  Serial.println("Arduino Car Diagnostics - WiFi Connection Test");
  Serial.println("=============================================");
  
  // Connect to WiFi
  setupWiFi();
  
  // Test motors after WiFi connection
  testMotors();
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

void testMotors() {
  Serial.println("\n=== MOTOR TESTING ===");
  
  // Test left wheel (IN1, IN2)
  Serial.println("Testing LEFT wheel for 2 seconds...");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(2000); // 2 seconds
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  Serial.println("Left wheel test complete");
  
  delay(500);
  
  // Test right wheel (IN3, IN4)
  Serial.println("Testing RIGHT wheel for 2 seconds...");
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(2000); // 2 seconds
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("Right wheel test complete");
  
  delay(500);
  
  // Test backward movement
  Serial.println("Testing BACKWARD movement for 2 seconds...");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(2000); // 2 seconds
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("Backward movement test complete");
  
  delay(500);
  
  // Test forward movement
  Serial.println("Testing FORWARD movement for 2 seconds...");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(2000); // 2 seconds
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("Forward movement test complete");
  
  Serial.println("=== MOTOR TESTING COMPLETE ===");
  Serial.println("All motors tested successfully!");
}
