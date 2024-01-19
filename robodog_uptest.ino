/************************** Spot my version upperleg test code ********************************************/
 #include <Servo.h>
Servo s8;
Servo s9;
Servo s10;
Servo s11;

Servo s7;
Servo s6;
Servo s5;
Servo s4;

int pos = 0;

void setup()
{
  /////uppper leg pins////////
  s8.attach(8);
  s9.attach(9);
  s10.attach(10);
  s11.attach(11);

  /////lower leg pins//////
  s7.attach(7);
  s6.attach(6);
  s5.attach(5);
  s4.attach(4);

}

void loop()
{
  s11.write(0);
  s10.write(0);
  s9.write(0);
  s8.write(0);

  delay(200);

}