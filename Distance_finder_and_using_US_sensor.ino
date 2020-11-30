/*
  This is a distance finder project.

  Hardwares used-  
    Ultrasoninc Sensor HC-SR04
    Arduino
    1602 LCD Module 
*/

/*
    CONNECTION
  For lcd 
    1. SCL - A0
    2. SDA - A1
    3. VCC - 5V
    4. GND - GND
  For Ultrasonic Sensor
    1. ECHO - D2
    2. TRIG - D3
    3. VCC - 5V
    4. GND - GND 
  */

#include <LiquidCrystal_I2C.h>

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04M

LiquidCrystal_I2C lcd(0x27, 16, 2); // lcd Address = 0x27

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
  lcd.init();      // initialize the lcd
  lcd.backlight(); // open the backlight
  
}
void loop() {

  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor and lcd
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.print(distance);
  lcd.println(" cm");
  delay(500);
}
