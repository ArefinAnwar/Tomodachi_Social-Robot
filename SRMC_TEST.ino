//[Dep Starts]
#include <TinyGPS++.h>
#include <Adafruit_MLX90614.h>
#include <LiquidCrystal_I2C.h>
#include<VarSpeedServo.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <MAX30105.h>
#include <spo2_algorithm.h>
#include <SoftwareSerial.h>
//[Dep Starts]

//[Obj Declaration Starts]
TinyGPSPlus gps;
MAX30105 particleSensor;
SoftwareSerial bluetooth(63, 62); // RX, TX (A9, A8)
//#define bluetooth Serial2
//SoftwareSerial excerciseBluetooth(65, 64); // RX, TX (A11, A10)
//SoftwareSerial excerciseBluetooth(); // RX, TX (A11, A10)
VarSpeedServo right_hand, pill_servo, left_hand, mask_servo;
LiquidCrystal_I2C lcd(0x27, 20, 4);
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
//[Obj Declaration End]

int red = 0;
int green = 0;
int blue = 0;
int flag = 0;
int gasFireCheckingMode = 0;
int colourCheckingMode = 0;


//[Colour Sensor Starts]
#define S0 26
#define S1 28
#define S2 34
#define S3 32
#define out 30
#define colourSensorPower 52
//[Colour Sensor Starts]


#define IRSensor 5
#define buzzer 50
#define sound_level_sensor A7
#define flame_sensor A1  //Fire sensor pin
#define emergency_button 7
#define gas_sensor A3 // Gas Sensor pin
//motor pins
#define FrontMotorLeft 24         // Left Motor pin
#define FrontMotorRight 25        // Right Motor pin
#define RearMotorLeft 22         // Left Motor pin
#define RearMotorRight 23        // Right Motor pin
#define FrontMotorLeftSpeed 11    // Left motor speed pin
#define FrontMotorRightSpeed 12
#define led 53

unsigned long timer_1;
void setup() {
  lcd.begin(20, 4);
  lcd.init();
  lcd.backlight();

  Serial.begin(9600);
  //Serial3.begin(9600);
  bluetooth.begin(9600);
  //excerciseBluetooth.begin(9600);

  pinMode(led, OUTPUT);

  pinMode(FrontMotorLeft, OUTPUT);        // Left Motor
  pinMode(FrontMotorRight, OUTPUT);       // Right Motor
  pinMode(FrontMotorLeftSpeed, OUTPUT);      // Left Motor Speed
  pinMode(FrontMotorRightSpeed, OUTPUT);     // Right Motor Speed

  mlx.begin();   // Temperature sensor
  pinMode(emergency_button, INPUT_PULLUP);
  pinMode(colourSensorPower, OUTPUT);

  pinMode(IRSensor, INPUT); // sensor pin INPUT
  right_hand.attach(9);

  left_hand.attach(10);
  pill_servo.attach(8);
  mask_servo.attach(6);
  pill_servo.write(0);
  right_hand.write(0);
  left_hand.write(180);
  mask_servo.write(0);


  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(out, INPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, HIGH);
  digitalWrite(colourSensorPower, LOW);
}

void loop() {
  lcd.setCursor(5, 0);
  lcd.print("Tomodachi");

  emergencySystem();

  if (flag  == 1) {
    Display_Temp();
    gasFireCheckingMode = 0;
    right_hand.write(90, 50, true);
  }

  if (gasFireCheckingMode  == 1) {

    Gas_Checker();
    fire_detection();
  }
  if (colourCheckingMode == 1) {

    colourDetection();
    digitalWrite(colourSensorPower, HIGH);
  }
  else if (colourCheckingMode == 0) {
    digitalWrite(colourSensorPower, LOW);
  }

  motor();
  //excerciseSystem();
  if (millis() - timer_1 > 1000)
  {
    //      pulse_and_oximeter();
    maskSystem();
    timer_1 = millis();
  }

}

void motor()
{
  if (bluetooth.available() > 0) {
    char cmmd = bluetooth.read();
    Serial.println(cmmd);

    if (cmmd == 'F') go_forward();
    else if (cmmd == 'B') stop_motors();
    else if (cmmd == 'A') reverse();
    else if (cmmd == 'L') go_left();
    else if (cmmd == 'R') go_right();
    else if (cmmd == 'D') {
      right_hand.write(90, 40, true);
      delay(1000);
    }
    else if (cmmd == 'U') {
      right_hand.write(180, 40, true);
      delay(1000);
    }
    else if (cmmd == 'N') {
      right_hand.write(0, 40, true);
      delay(1000);
    }
    else if (cmmd == 'C') {
      left_hand.write(90, 60, true);
      delay(1000);
    }
    else if (cmmd == 'X') {
      left_hand.write(0, 60, true);
      delay(1000);
    }
    else if (cmmd == 'Z') {
      left_hand.write(180, 60, true);
      delay(1000);
    }

    else if (cmmd == 'G') {
      pill_servo.write(50, 200, true);
      delay(1000);
      pill_servo.write(0, 200, true);
      delay(1000);
    }

    else if (cmmd == 'P') {
      mask_servo.write(0, 255, true);
      delay(1000);
    }
    else if (cmmd == 'O') {
      mask_servo.write(90, 255, true);
      delay(1000);
    }
    else if (cmmd == 'T') {
      lcd.clear();
      flag = !flag;
      lcd.clear();
    }
    else if (cmmd == 'I') {
      lcd.clear();
      gasFireCheckingMode = !gasFireCheckingMode;
      lcd.clear();
    }
    else if (cmmd == 'E') {
      lcd.clear();
      colourCheckingMode = !colourCheckingMode;
      lcd.clear();
    }
    else if (cmmd == 'Y') {
      right_hand.write(180, 255, true);
      left_hand.write(0, 255, true);
      //delay(300);
      right_hand.write(0, 255, true);

      left_hand.write(180, 255, true);
      //delay(300);
    }
    else {
      stop_motors();
    }
  }
}
