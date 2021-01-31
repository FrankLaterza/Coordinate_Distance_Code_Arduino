
/*

  Frank made this codde
  use it how ever you want !!
  
  @breif This code takes Two Lat and Long Coordniates 
  and calcutales this distance between them im METERS!!

  All you gotta do to use it is

  float distance = distanceCoordinates(Current Lat, Current Long, TargetLat, Target Long);
                    ^^^^^^^^^^^^^^^  this function returns the distnace

  
 
*/

#include "math.h"   // make sure to inlcude this!



void setup(){
  Serial.begin(9600);
  
  
}


// this loop is an example of you to use the function!!
void loop(){

  
  //defining variables
  float currentLat, currentLong; // vars for the current lat and long
  float targetLat, targetLong;   // vars for the target  lat and long 
  float distance;                // var for funtion output
  
  
  
  // the function
  distance = distanceCoordinates(currentLat, currentLong, targetLat, targetLong);
  //         ^^^^^^^^^^^^^^^  this function returns the distnace
  
  
  // this should output the distance to the serial monitor.
  Serial.println(distance);
  
  
  
  // THE LOOP WILL RUN EVER 5 SECONDS
  delay(5000); // this pauses for 5 seconds
  
  

  

}




float distanceCoordinates(float flat1, float flon1, float flat2, float flon2) {

    float dist_calc=0, dist_calc2=0;
    float diflat=0, diflon=0;
    float radConvert = 0.0174533;

    // Calculations
    diflat  = radConvert*(flat2-flat1);
    flat1 = radConvert*(flat1);
    flat2 = radConvert*(flat2);
    diflon = radConvert*((flon2)-(flon1));

    dist_calc = (sin(diflat/2.0)*sin(diflat/2.0));
    dist_calc2 = cos(flat1);
    dist_calc2*=cos(flat2);
    dist_calc2*=sin(diflon/2.0);
    dist_calc2*=sin(diflon/2.0);
    dist_calc +=dist_calc2;

    dist_calc=(2*atan2(sqrt(dist_calc),sqrt(1.0-dist_calc)));
    

    dist_calc*=6371000.0; //Converting to meters

    return dist_calc;

}
