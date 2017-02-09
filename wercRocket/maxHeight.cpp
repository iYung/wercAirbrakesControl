

#include "maxHeight.h"
maxHeight(currentHeight,estAirDensity,estCoeffDrag,currentSpeed){
  const double dryMass=10;//dry mass in Kg
  const double thereGoesGravity=9.8;
  const double crossArea=0.014637068;//cross section area in m^2
  double terminalVelocitySquared=(2*dryMass*thereGoesGravity/(estCoeffDrag*crossArea*estAirDensity));//simplified math by not taking the square root here
  double maxHeight=terminalVelocitySquared/(2*thereGoesGravity)*log((pow(currentSpeed,2)+terminalVelocitySquared)/terminalVelocitySquared)+currentHeight;
  return maxHeight;
}
