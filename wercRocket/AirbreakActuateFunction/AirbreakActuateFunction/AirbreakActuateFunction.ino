void setup() {
  // put your setup code here, to run once:
int deployPin=5;//use these the arduino as they give 980HZ PWNM
int retractPin=6;//others will only give 490Hz which may cause problems
}

void loop() {
  // put your main code here, to run repeatedly:

}

void actuateAir(double amount)//takes and input -1<->1 where -1 is retract asap and +1 is deploy asap
{

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

