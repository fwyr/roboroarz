#include <smorphi.h>
#include "HUSKYLENS.h"
#include "SoftwareSerial.h"

Smorphi my_robot;
HUSKYLENS huskylens;
SoftwareSerial myHuskySerial(19, 18);

// === CUSTOM VARIABLES ===

#define straightSpeed 55
#define leftSpeed 300
#define rightSpeed 300
#define angV 100
#define speedBoost 100

bool goingStraight = false;
bool goingLeft = false; 
bool goingRight = false;
bool halfTurn = false;
bool goingFast = false;

// === HUSKYLENS INITIALISATION ===

void printResult(HUSKYLENSResult result) {
  if (result.command == COMMAND_RETURN_BLOCK) {
    Serial.println(result.ID);
  }

  else if (result.command == COMMAND_RETURN_ARROW) {
    Serial.println("Wrong mode");
  } else {
    Serial.println("Object unknown!");
  }
}

// === SENSOR INITIALISATION ===

int right_sensor_status = my_robot.module1_sensor_status(6);
int bottom_right_sensor_status = my_robot.module1_sensor_status(4);
int left_sensor_status = my_robot.module1_sensor_status(10);
int bottom_left_sensor_status = my_robot.module1_sensor_status(0);

// === LED FUNCTIONS ===

void red_on() {
  digitalWrite(25, HIGH);
  digitalWrite(26, LOW);
  digitalWrite(27, LOW);
}

void green_on() {
  digitalWrite(25, LOW);
  digitalWrite(26, HIGH);
  digitalWrite(27, LOW);
}

void blue_on() {
  digitalWrite(25, LOW);
  digitalWrite(26, LOW);
  digitalWrite(27, HIGH);
}

void white_on() {
  digitalWrite(25, HIGH);
  digitalWrite(26, HIGH);
  digitalWrite(27, HIGH);
}

void led_off() {
  digitalWrite(25, LOW);
  digitalWrite(26, LOW);
  digitalWrite(27, LOW);
}

// === SETUP & LOOP ===

void setup() {
  Serial.begin(115200);
  my_robot.BeginSmorphi();
  myHuskySerial.begin(9600);
  while (!huskylens.begin(myHuskySerial)) {
    Serial.println(F("Begin failed!"));
    Serial.println(F("1.Please recheck the \"Protocol Type\" in HUSKYLENS (General Settings>>Protocol Type>>Serial 9600)"));
    Serial.println(F("2.Please recheck the connection."));
    delay(100);
  }

  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);

  my_robot.O();
}

void loop() {
  int x = 0;
  if (huskylens.request()) {
    if (huskylens.available()) {
      HUSKYLENSResult result = huskylens.read();
      printResult(result);
      if (result.command == COMMAND_RETURN_BLOCK) {
        x = result.ID;
      }
    }
  } else {
    Serial.println("Error!");
  }

  sensor_initialisation();

  if (x == 1) {
    red_on();
    delay(500);
    led_off();
  } else if (x == 2) {
    green_on();
    delay(500);
    led_off();
  } else if (x == 3) {
    blue_on();
    delay(500);
    led_off();
  } else if (x == 4) {  // LEFT
    goingLeft = true;
    goingRight = false;
    goingStraight = false;
    halfTurn = false;
  } else if (x == 5) {  // STRAIGHT
    goingStraight = true;
    goingLeft = false;
    goingRight = false;
    halfTurn = false;
  } else if (x == 6) {  // RIGHT
    goingRight = true;
    goingLeft = false;
    goingStraight = false;
    halfTurn = false;
  } else if (x == 7) {  // TURN 180 DEGREES
    goingLeft = false;
    goingRight = false;
    goingStraight = false;
    halfTurn = true;
  } else if (x == 9) {  // CHANGE SHAPE
    my_robot.I();
  } 
}