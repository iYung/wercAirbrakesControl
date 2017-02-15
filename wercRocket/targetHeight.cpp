
#include <math.h>
#include <targetHeight.h>
double getTargetHeight (double currentHeight, double burnoutHeight, double initialMax)
{
  //This function runs a declining slope function base on part of a sine wave
  //By reducing the rate of change as the rocket approaches the target, maximum control is achieved
  const double target=3048;//desired apogee
   double overshoot=(initialMax/target)-1;//percent overshoot calculated at burnout
  const double pi=3.141592654;
  double targetAmplitude=-overshoot*target;//distance between max target and final target
  double targetOffset=(overshoot+1.0)*target; //How high the initial target is
  double waveShift=pi/(2*(target-burnoutHeight)); //How the sine wave is shifted
  double goalBallistic=currentHeight-burnoutHeight; //Determines where to start the wave so the airbreaks don't go nuts as soon as burnout occurs
  double objective=(targetAmplitude)*sin(waveShift*goalBallistic)+targetOffset;//calculates the function
  if (currentHeight<target)//returns the calculated target height
  return objective;
  else if (currentHeight>=target)//basically tells the airbreaks to stop everything because we overshot
  return target;  
}
