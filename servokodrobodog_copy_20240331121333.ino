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

void loop() {
  int derece = 90;
  if(servonum>-1 && servonum < 4; servonum++ ){
    setServoPos(servonum,derece);
  }


   for(int i=0; i<4; i++){

    setServoPos(lowerservo[i],92);
    delay(2000);
    setServoPos(lowerservo[i],110);
    delay(2000);

   }
  
  }


  /*for(derece=0;derece<180;derece++){
    setServoPos(servonum,derece);
  }

  delay(500);

  for(derece=179;derece>-1;derece--){
    setServoPos(servonum,derece);
  }

  delay(500);*/
  
