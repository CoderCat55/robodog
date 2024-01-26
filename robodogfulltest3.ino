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

int up=92;
int down=110;
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

  s5.write(up);                    //s5  ve s6 sağ taraf (Düz)
  s6.write(up);                   //s4 ve s7 sol taraf (ters)
  s7.write(down);
  s4.write(down);
      delay(500);
  
  s5.write(down);
  s6.write(down);
  s7.write(up);
  s4.write(up);
      delay(500);
  
}