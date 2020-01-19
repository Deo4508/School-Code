float read_ultrasonic(int trig, int echo)     //this function allows the ultrasonic sensor to read distances
{

  float duration, distance, c=343.0;
  
  //send pulse
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(11);
  digitalWrite(trig, LOW);

  delayMicroseconds(10);

  duration = pulseIn(echo, HIGH);       

  duration *= 1.0e-6;                  
  distance = c*duration/2.0;          
  
  return distance;      
  }
