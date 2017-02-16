#include "airDensity.h"
#include "cofDrag.h"
#include "maxHeight.h"
#include "targetHeight.h"

void setup(){
//pins 5 and 6 analog outputs
//pick any for linear potentiometer

// constant variables
const groundPressure;

//variables
int currentHeight;
int currentSpeed;
int actuateAmount;
}

void loop(){
 estCoeffDrag(currentSpeed);
getAirDensity(currentHeight,groundPressure);
maxHeight(currentHeight,estAirDensity,estCoeffDrag,currentSpeed);
targetHeight(currentHeight);
if(maxHeight()>targetHeight())
  actuateAmount=1
else
  actuateAmount = -1
  
  actuateAir(actuateAmount);
}


//actuate airbrake function
void actuateAir(double amount)//takes and input -1<->1 where -1 is retract asap and +1 is deploy asap
{
int deployPin=5;//use these the arduino as they give 980HZ PWNM
int retractPin=6;//others will only give 490Hz which may cause problems

if (amount>0){
  analogWrite(deployPin,(amount*255));
  analogWrite(retractPin,0);}
else if (amount<0){
  analogWrite(deployPin,0);
  analogWrite(retractPin,(amount*255));}
else {
  analogWrite(deployPin,(amount*255));
  analogWrite(retractPin,0);}
}

