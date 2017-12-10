#include <Keyboard.h>
const int indexFinger = A0;
const int middleFinger = A1; 
const int thumb = A2; 
const int pinkyFinger = A3; 
const int ringFinger = A6; 

const int pins[] = {thumb, indexFinger, middleFinger, pinkyFinger, ringFinger};

char Keys_a[] =   {'z','x','c','v','b'};
char Keys_b[] =   {'n','m',',','.','/'};
boolean currentPressed_a[] = {false, false, false, false, false};
boolean currentPressed_b[] = {false, false, false, false, false};
const int threshold_a = 200;  // threshold value to decide when the detected sound is a knock or not
const int threshold_b = 800;

void setup()
{
  //while (!Serial)
  Serial.begin(115200);
  Serial.println("start");
}


void loop()                    
{ 
  for (int i=0;i<5;i++) {
    delay(1);
    long total1 = 0;
    long start = millis();
    long total =  analogRead(pins[i]);
    // check if we are sensing that a finger is touching
    // and that it wasnt already pressed
    if ((total > threshold_a && total < threshold_b) && (! currentPressed_a[i])) {
      Serial.print("Key pressed #"); Serial.print(i);
      Serial.print(" ("); Serial.print(Keys_a[i]); Serial.println(")");
      currentPressed_a[i] = true;
      Keyboard.press(Keys_a[i]);
      
    }else if ((total > threshold_b) && (! currentPressed_b[i])){
      Serial.print("Key pressed #"); Serial.print(i);
      Serial.print(" ("); Serial.print(Keys_b[i]); Serial.println(")");
      currentPressed_b[i] = true;
      Keyboard.press(Keys_b[i]);
    }
    else if ((total <= threshold_a || total > threshold_b) && (currentPressed_a[i])) {
      // key was released (no touch, and it was pressed before)
      Serial.print("Key released #"); Serial.print(i);
      Serial.print(" ("); Serial.print(Keys_a[i]); Serial.println(")");
      currentPressed_a[i] = false;
      Keyboard.release(Keys_a[i]);
    }else if ((total <= threshold_b) && (currentPressed_b[i])) {
      // key was released (no touch, and it was pressed before)
      Serial.print("Key released #"); Serial.print(i);
      Serial.print(" ("); Serial.print(Keys_b[i]); Serial.println(")");
      currentPressed_b[i] = false;
      Keyboard.release(Keys_b[i]);
    }
    
    delay(5);
  }
}
