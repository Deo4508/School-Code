/*The robot is a small car that will avoid obstacles while driving.
It does this by gathering information of its surroundings via three ultrasonic sensors attached to the front: one is facing
forward, and the two on the side are facing forward at an angle of 45 degrees to cover the sides of the arduino

To build the arduino: an arduino uno board in combination with two continuous servos and three distance sensors. 
The robot is powered by an external power bank. Cardboard was used as a base. A round piece of cardboard was attached to the base
at the back of the arduino to act as a third "wheel"
 */

int trig1 = 2, echo1 = 3, trig2 = 4, echo2 = 5, trig3 = 6, echo3 = 7; 


#include "read_ultrasonic.h" 
#include "front_alert.h"
#include <Servo.h>
Servo right;
Servo left;


void setup() {
    pinMode(trig1, OUTPUT); 
    pinMode(echo1, INPUT);
    pinMode(trig2, OUTPUT);
    pinMode(echo2, INPUT);
    pinMode(trig3, OUTPUT);
    pinMode(echo3, INPUT);
    
    right.attach(8); 
    left.attach(9);
   
    Serial.begin(9600); 

    delay(5000); 
}


void loop() {
  float distance_l, distance_r, distance_f;
  int i;

    right.write(0); 
    left.write(180);
    
    distance_f = read_ultrasonic(trig1, echo1);     
    distance_l = read_ultrasonic(trig2, echo2);     
    distance_r = read_ultrasonic(trig3, echo3);     
    
   if(distance_f < 0.2){       
    front_alert();  //This function allows the arduino to avoid obstacles directly in front of it        
  }
  if(distance_l <=0.2){ //Allows arduino to avoid any obstacles to the left of it
    while(distance_l <= 0.4){       
     distance_l= read_ultrasonic(trig2, echo2);
     right.write(90);
     left.write(180); 
    }
  }
  
 if(distance_r <=0.2){ //Allows arduino to avoid any obstacles to the right of it
  while(distance_r <= 0.4){ 
    distance_r= read_ultrasonic(trig3, echo3); 
    right.write(0);
    left.write(90);
    }
  }
}
