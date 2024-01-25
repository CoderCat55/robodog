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

void up(){
  pos=92;
}

void down(){
  pos=110;
}
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
  

  pos = 92; //up
      s7.write(pos);
      s6.write(pos);
      s5.write(pos);
      s4.write(pos);
      delay(500);
  

 pos = 110; //down
     s7.write(pos);
      s6.write(pos);
      s5.write(pos);
      s4.write(pos);
      delay(500);
  
  

}