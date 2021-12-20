//
//#include <TinyGPS++.h>
//#include <Adafruit_MLX90614.h>
//#include <LiquidCrystal_I2C.h>
//#include<VarSpeedServo.h>
//#include <SoftwareSerial.h>
//#include <Wire.h>
//#include "MAX30105.h"
//#include "spo2_algorithm.h"
//#include <SoftwareSerial.h>
//
//
//TinyGPSPlus gps;
//MAX30105 particleSensor;
//SoftwareSerial bluetooth(63, 62); // RX, TX (A9, A8)
//VarSpeedServo right_hand, pill_servo;
//LiquidCrystal_I2C lcd(0x27, 20, 4);
//Adafruit_MLX90614 mlx = Adafruit_MLX90614();
//
//
//#define flame_sensor A1  //Fire sensor pin
//#define emergency_button 7
//#define gas_sensor A3 // Gas Sensor pin
////motor pins
//#define FrontMotorLeft 24         // Left Motor pin
//#define FrontMotorRight 25        // Right Motor pin
//#define FrontMotorLeftSpeed 11    // Left motor speed pin
//#define FrontMotorRightSpeed 12
//
//
//#define MAX_BRIGHTNESS 255
//
//#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__)
////Arduino Uno doesn't have enough SRAM to store 100 samples of IR led data and red led data in 32-bit format
////To solve this problem, 16-bit MSB of the sampled data will be truncated. Samples become 16-bit data.
//uint16_t irBuffer[100]; //infrared LED sensor data
//uint16_t redBuffer[100];  //red LED sensor data
//#else
//uint32_t irBuffer[100]; //infrared LED sensor data
//uint32_t redBuffer[100];  //red LED sensor data
//#endif
//
//int32_t bufferLength; //data length
//int32_t spo2; //SPO2 value
//int8_t validSPO2; //indicator to show if the SPO2 calculation is valid
//int32_t heartRate; //heart rate value
//int8_t validHeartRate; //indicator to show if the heart rate calculation is valid
//
//byte pulseLED = 11; //Must be on PWM pin
//byte readLED = 13; //Blinks with each data read
//// The serial connection to the GPS device
////SoftwareSerial gpsSerial(RXPin, TXPin);
//
//uint32_t timer_1;
//void setup() {
//  Serial.begin(9600);
//  bluetooth.begin(9600);
//
//  pinMode(FrontMotorLeft, OUTPUT);        // Left Motor
//  pinMode(FrontMotorRight, OUTPUT);       // Right Motor
//  pinMode(FrontMotorLeftSpeed, OUTPUT);      // Left Motor Speed
//  pinMode(FrontMotorRightSpeed, OUTPUT);     // Right Motor Speed
//
//  lcd.begin(20, 4);
//  lcd.init();
//  lcd.backlight();
//
//  mlx.begin();
//  pinMode(emergency_button, INPUT_PULLUP);
//
//  right_hand.attach(9);
//  pill_servo.attach(10);
//  pill_servo.write(0);
///*
//  pinMode(pulseLED, OUTPUT);
//  pinMode(readLED, OUTPUT);
//
//  // Initialize sensor
//  if (!particleSensor.begin()) //Use default I2C port, 400kHz speed
//  {
//    Serial.println(F("MAX30105 was not found. Please check wiring/power."));
//    //while (1);
//  }
//
//  Serial.println(F("Attach sensor to finger with rubber band. Press any key to start conversion"));
//  //while (Serial.available() == 0) ; //wait until user presses a key
//  //Serial.read();
//
//  byte ledBrightness = 60; //Options: 0=Off to 255=50mA
//  byte sampleAverage = 4; //Options: 1, 2, 4, 8, 16, 32
//  byte ledMode = 2; //Options: 1 = Red only, 2 = Red + IR, 3 = Red + IR + Green
//  byte sampleRate = 100; //Options: 50, 100, 200, 400, 800, 1000, 1600, 3200
//  int pulseWidth = 411; //Options: 69, 118, 215, 411
//  int adcRange = 4096; //Options: 2048, 4096, 8192, 16384
//
//  particleSensor.setup(ledBrightness, sampleAverage, ledMode, sampleRate, pulseWidth, adcRange); //Configure sensor with these settings
//  */
//}
//
//void loop() {
//  Display_Temp();
//  fire_detection();
//  //GPS_System();
//  Gas_Checker();
//  motor();
////  if (millis() - timer_1 > 50 && !bluetooth.available() > 0)
////  {
////    pulse_and_oximeter();
////    timer_1 = millis();
////  }
//}
//char cmmd;
//void motor()
//{
//  if (bluetooth.available() > 0) {
//    cmmd = bluetooth.read();
//    Serial.println(cmmd);
//
//    if (cmmd == 'F') go_forward();
//    else if (cmmd == 'B') stop_motors();
//    else if (cmmd == 'L') go_left();
//    else if (cmmd == 'R') go_right();
//    else if (cmmd == 'D') {
//      right_hand.write(90, 40, true);
//      delay(1000);
//    }
//    else if (cmmd == 'U') {
//      right_hand.write(18, 40, true);
//      delay(1000);
//    }
//    else if (cmmd == 'N') {
//      right_hand.write(0, 40, true);
//      delay(1000);
//    }
//    else if (cmmd == 'G') {
//      pill_servo.write(50, 200, true);
//      delay(1000);
//      pill_servo.write(0, 200, true);
//      delay(1000);
//    }
//    else {
//      stop_motors();
//    }
//  }
//}
