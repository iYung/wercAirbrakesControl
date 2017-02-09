

#include <airDensity.h>
double getAirDensity(double groundTemperature, double groundPressure, double currentHeight){ 
 double groundTemperature=groundTemperature+273.15;
 const double effectiveConst=0.3;//Constant for estimating the effictive average density for drag
 const double lapseRate=0.00649;
 double Temperature=groundTemperature-(lapseRate*currentHeight);
 double TemperatureApo=groundTemperature-(lapseRate*3048);//calculates air temperature at max height, may be calculated once in main()
 const double gasConst=8.3144598;
 const double airMolarMass=28.7484273;//@2% H2O content
 const double thereGoesGravity=9.8;
 double pressureChangeExp=thereGoesGravity*airMolarMass/(gasConst*currentHeight);
 double pressureChangeExpApo=thereGoesGravity*airMolarMass/(gasConst*3048);//calculates pressure exponant at max height, may be calculated once in main()
 double pressure=groundPressure*pow((1-(lapseRate*currentHeight/groundTemperature)),pressureChangeExp);
 double pressureApo=groundPressure*pow((1-(lapseRate*currentHeight/groundTemperature)),pressureChangeExpApo);//calculates pressure at max height, may be calculated once in main()
 double density=pressure*airMolarMass/(gasConst*Temperature);
 double densityApo=pressureApo*airMolarMass/(gasConst*TemperatureApo);//calculates density at max height, may be calculated once in main()
 double effectiveAveDensity=effectiveConst*(density-densityApo)+densityApo;
 return effectiveAveDensity;
}
