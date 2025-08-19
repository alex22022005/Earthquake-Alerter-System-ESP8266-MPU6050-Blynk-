#include <Wire.h>
#include <MPU6050.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_TEMPLATE_ID "TMPL3HlB8uRvk"
#define BLYNK_TEMPLATE_NAME "esp"
#define BLYNK_AUTH_TOKEN "an_puTAJS62NFIaSpHLQI5lAl4s0F3p6"

#define BLYNK_PRINT Serial

MPU6050 mpu;

LiquidCrystal_I2C lcd(0x27, 16,2);

#define BUZZER D5
#define LED D6

char ssid[] = "Mr.lonely";
char pass[] = "antony....";

void setup() 
{
  Wire.begin(2,0);
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  mpu.initialize();
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("Earthquake");
  lcd.setCursor(6, 1);
  lcd.print("Alerter");
  delay(2000);
  lcd.clear();
}

void loop() 
{
  Blynk.run();
  int16_t ax, ay, az;
  int16_t gx, gy, gz;
  mpu.getAcceleration(&ax, &ay, &az);
  mpu.getRotation(&gx, &gy, &gz);

  float aX = ax / 16384.0; // Scale factor for +/- 2g
  float aY = ay / 16384.0; // Scale factor for +/- 2g
  float aZ = az / 16384.0; // Scale factor for +/- 2g

  // Calculate the magnitude of acceleration
  float accelerationMagnitude = sqrt(aX * aX + aY * aY + aZ * aZ);

  // Convert raw gyroscope values to degrees/second (use appropriate scale factor)
  float gX = gx / 131.0; // Scale factor for +/- 250 degrees/sec
  float gY = gy / 131.0; // Scale factor for +/- 250 degrees/sec
  float gZ = gz / 131.0; // Scale factor for +/- 250 degrees/sec

  // Calculate the magnitude of rotational velocity
  float rotationMagnitude = sqrt(gX * gX + gY * gY + gZ * gZ);

  // Threshold values to detect significant motion and rotation (adjust as needed)
  float accelerationThreshold = 1.5; // Example threshold value in g
  float rotationThreshold = 30.0;   // Example threshold value in degrees/sec

  Blynk.virtualWrite(V0,DHT.temperature);
  Blynk.virtualWrite(V1,DHT.humidity);
  Blynk.virtualWrite(V2,distance);

    if (accelerationMagnitude > accelerationThreshold) 
    {
      lcd.setCursor(0, 0);
      lcd.print("Alert Detected!");
      lcd.setCursor(0, 1);
      Blynk.logEvent("buglar","Someone has entered your house be alert");
      lcd.print("Earthquake or ");
    }
    if (rotationMagnitude > rotationThreshold) 
    {
      lcd.setCursor(0, 0);
      lcd.print("Alert Detected!");
      lcd.setCursor(0, 1);
      Blynk.logEvent("buglar","Someone has entered your house be alert");
      lcd.print("Rotation Alert!");
    }
    digitalWrite(BUZZER, HIGH); // Turn on the buzzer
    digitalWrite(LED, HIGH);    // Turn on the LED
   else 
  {
    lcd.clear();
    digitalWrite(BUZZER, LOW); // Turn off the buzzer
    digitalWrite(LED, LOW);    // Turn off the LED
  }

  delay(500); // Update every 500 ms
}
