
#include "SwipeDetector.h"
#include <Arduino.h>


  SwipeDetector::Swipe SwipeDetector::detect(int left, int right)
 {
    char t = isTriggered(left) * 2 | isTriggered(right);
    return filter(t);
  }



bool SwipeDetector::isTriggered(int distance) {
  if(distance != -1 && distance < 30) {
    return true;
  }
  return false;
}


SwipeDetector::Swipe SwipeDetector::filter(char t) {
  Swipe ret = SWIPE_NONE;
//  if((t == last_t)) {
  if((t == last_t)&&(t == last2_t)) {
    //if(t != 0)

    //Serial.println((int)t);
    ret = stateMachineInternal(t);
  }
  last_t = t;
  last2_t = last_t;

  return ret;
}

SwipeDetector::Swipe SwipeDetector::stateMachineInternal(char t) {

  switch (z) {

      case REST:
        if( t == T01) {
          z = Z1;
  //Serial.println(z);
        }
        if( t == T10) {
          z = Z4;
  //Serial.println(z);
        }
        break;

      case Z1:
        if(t == T00) {
          z = REST;
  //Serial.println(z);
        }
        if(t == T10) {
          z = REST;
  //Serial.println(z);
        }
        if(t == T11) {
          z = Z2;
 // Serial.println(z);
        }
        break;

      case Z2:
        if(t == T00) {
          z = REST;
 // Serial.println(z);
        }
         if(t == T01) {
           z = REST;
  // Serial.println(z);
         }
        if(t == T10) {
          z = Z3;
 // Serial.println(z);
        }
        break;

      case Z3:
        if(t == T01) {
          z = REST;
  //Serial.println("rausrechts");          
  //Serial.println((int)t);
  //Serial.println(z);
        }
        if(t == T10) {
          //z = REST;
  //Serial.println("rauslinks");          
  //Serial.println((int)t);
  //Serial.println(z);
        }
        if(t == T00) {
          
          z = REST;
//  Serial.println(z);
  return SWIPE_LEFT;
        }
        break;

        case Z4:
        if(t == T00) {
          z = REST;
  // Serial.println(z);
        }
        if(t == T01) {
          z = REST;
 // Serial.println(z);
        }
        if(t == T11) {
          z = Z5;
 // Serial.println(z);
        }
        break;

      case Z5:
        if(t == T00) {
          z = REST;
//  Serial.println(z);
        }
         if(t == T10) {
           z = REST;
//   Serial.println(z);
         }
        if(t == T01) {
          z = Z6;
//  Serial.println(z);
        }
        break;
        
      case Z6:
        if(t == T10) {
          z = REST;
  //Serial.println("rauslinks");          
  //Serial.println((int)t);
  //Serial.println(z);
        }
        if(t == T01) {
          //z = REST;
  //Serial.println("rausrechts");          
  //Serial.println((int)t);
  //Serial.println(z);
        }
        if(t == T00) {
          
          z = REST;
//  Serial.println(z);
  return SWIPE_RIGHT;
        }
        break;
  }

  return SWIPE_NONE;
}