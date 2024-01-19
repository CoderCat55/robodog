/************************** Spot my version upperleg test code ********************************************/
 #include <Servo.h>
Servo s8;
Servo s9;
Servo s10;
Servo s11;
                                         
Servo s7;
Servo s6;            /* s7.write(pos); s6.write(pos); s5.write(pos);  s4.write(pos);*/
Servo s5;
Servo s4;

int pos = 0;
int i =0;

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

  for(i<1; i++){
    s7.write(92);
    s6.write(92);
    s5.write(92);
    s4.write(92);
  }

  delay(200);

  for (pos = 92; pos <= 94; pos += 1){
      s7.write(pos);
      s6.write(pos);
      s5.write(pos);
      s4.write(pos);
      delay(15);
  }

  for (pos = 94; pos >= 92; pos -= 1){
     s7.write(pos);
      s6.write(pos);
      s5.write(pos);
      s4.write(pos);
      delay(15);
  }
  

}