
#include "control.h"


void rotaryEncoder(int& aState, int& aLastState, int outputA, int outputB, int& counter, String axis ) {

  aState = digitalRead(outputA); // Reads the "current" state of the outputA
  // If the previous and the current state of the outputA are different, that means a Pulse has occured
  if (aState != aLastState) {
    // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
    if (digitalRead(outputB) != aState) {
      counter++;
    } else {
      counter--;
    }
    Serial.print("Position" + axis +  " ");
    Serial.println(counter);
  }
  aLastState = aState; // Updates the previous state of the outputA with the current state
  return;
}

bool toggle(int onOff) {
  if (digitalRead(onOff) == LOW) {
    return true;
  } else {
    return false;
  }
}

