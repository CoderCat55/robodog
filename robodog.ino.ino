/************************** Spot my version individual leg test code ********************************************/
#include <Servo.h>
Servo sg90;
int pos = 0;

void setup()
{
  sg90.attach(9);
}
/********************************************************************************************************************/
void sifirla(){
  sg90.write(92);
  delay(200);
}
/****************************************************************************************************************************************/
void legup(){
  sg90.write(120);
  delay(200);
}
/********************************************************************************************************************************************/
void legdown(){
  sg90.write(90);
  delay(200);
}
/*********************************************************************************************************************************************/
void legupdown(){
   legup();

   for (pos = 92; pos <= 94; pos += 1){
      sg90.write(pos);
      delay(15);
  }

  for (pos = 94; pos >= 92; pos -= 1){
  sg90.write(pos);
   delay(15);
  }

}
/******************************************************************************************************************************************/
void loop()
{
//sifirla();

legdown();
delay(3000);
legup();
delay(3000);

}