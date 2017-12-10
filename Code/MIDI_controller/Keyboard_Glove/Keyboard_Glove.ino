#include <MIDI.h>

/*
  Piezo Keyboard glove
  
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried & Becky Stern for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
  
*/
const int indexFinger = A0; // the piezo is connected to analog pin 9 (aka D9)
const int middleFinger = A2; // the piezo is connected to analog pin 7 (aka D6)
const int thumb = A1; // the piezo is connected to analog pin 10 (aka D10)
const int pinkyFinger = A3; // the piezo is connected to analog pin 11 (aka D12)

const int pins[] = {thumb, indexFinger, middleFinger, pinkyFinger};

boolean currentPressed[] = {false, false, false, false};

const int threshold = 40;  // threshold value to decide when the detected sound is a knock or not

// Created and binds the MIDI interface to the default hardware Serial port
 MIDI_CREATE_DEFAULT_INSTANCE();

void setup()
{
  Serial.begin(115200);
}


void loop()
{ 
  for (int i=0;i<4;i++) {
    delay(1);
    long total1 = 0;
    long start = millis();
    long total =  analogRead(pins[i]);

    // check if we are sensing that a finger is touching
    // and that it wasnt already pressed
    if ((total > threshold) && (! currentPressed[i])) {
      currentPressed[i] = true;
      Serial.println("pressed");
      // Send note 42 with velocity 127 on channel 1
      MIDI.sendNoteOn(42, 127, 1);
    } 
    else if ((total <= threshold) && (currentPressed[i])) {
      currentPressed[i] = false;
      MIDI.sendNoteOff(42, 0, 1);
    }
    
    delay(5);
  }
}
