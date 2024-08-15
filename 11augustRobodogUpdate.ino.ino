/* PCA9685ServoV2
 *  26/12/23
 *  
 * This version of the sketch allows you to set the position in degrees from 0-179
 *  
 * PCA9685 Board with MG90 servo
 * 
 * This sketch only controls a single servo on pca9685 pin 0
 * Moving it from 0 - 180 degrees
 * 
 * 
SDA/SCL connections 
Arduino UNO: A4 (SDA), A5 (SCL) 
Arduino Mega 2560: 20 (SDA), 21 (SCL)  
ESP32: 21(SDA), 22 (SCL)

youtube links 
https://www.youtube.com/watch?v=O_2swSMecB4
https://www.youtube.com/watch?v=4rc8N1xuWvc

 */


#include "Wire.h"
#include "Adafruit_PWMServoDriver.h"

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define USMIN  550 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150 //normally 600
#define USMAX  2390 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600 //normally 2400
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

/*usmın 550  usmax2390  oluyor diğer türlü servo zorlanıyor*/

// upper leg servo numaraları
const int upperservo[] = {0, 1, 2, 3}; // Add or remove servo numbers as needed


// lower leg servo numaraları
const int lowerservo[] = {4, 5, 6, 7};

int servonum=0;



void setup() {
  Serial.begin(9600);
  Serial.println("PCA9685ServoV1");

  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  delay(10);
}


void setServoPos(int servo, int pos){
  //This first bit of code makes sure we are not trying to set the servo outside of limits
  int sendPos;
  if(pos > 179){
    pos = 179;
  }
  if(pos < 0){
    pos = 0;
  }
  sendPos = USMIN + ((USMAX - USMIN)/180 * pos);
  if(servo > -1 && servo < 8){//only try to move valid servo addresses
    pwm.writeMicroseconds(servo, sendPos);
  }
}

void sol1(int servo1,int servo2) {
  setServoPos(servo1,120);
  delay(200);
  setServoPos(servo2,90);
}


void sol2(int servo1,int servo2) {
  setServoPos(servo1,120);
  delay(200);
  setServoPos(servo2,70);
}

void sol3(int servo1,int servo2) {
  setServoPos(servo1,80);
  delay(200);
  setServoPos(servo2,70);
}


void sol4(int servo1,int servo2) {
  setServoPos(servo1,80);
  delay(200);
  setServoPos(servo2,90);
}


void sag1(int servo1,int servo2) {
  setServoPos(servo1,60);
  delay(200);
  setServoPos(servo2,100);
}

void sag2(int servo1,int servo2) {
  setServoPos(servo1,60);
  delay(200);
  setServoPos(servo2,120);
}

void sag3(int servo1,int servo2) {
  setServoPos(servo1,100);
  delay(200);
  setServoPos(servo2,120);
}

void sag4(int servo1,int servo2) {
  setServoPos(servo1,100);
  delay(200);
  setServoPos(servo2,100);
}


void loop() {
  delay(200);
  setServoPos(0,60); //60,100
  delay(1000);
  setServoPos(0,100); //60,100
  delay(1000);
  

  /*
sol1(2,7);
delay(500);
sol2(2,7);
delay(500);
sol3(2,7);
delay(500);
sol4(2,7);
delay(500);
 /* 
 sag1(1,4);
 delay(500);
 sag2(1,4);
 delay(500);
 sag3(1,4);
 delay(500);
 sag4(1,4);
 delay(500);
 */


}