void keyboardMode() {
  // checkLeds_KEYBOARD_MODE();
  // checkChannelLeds_KEYBOARD_MODE();
  checkStepButton_KEYBOARD_MODE();
  // checkChannelButton_KEYBOARD_MODE();
}

void checkLeds_KEYBOARD_MODE() {
  for (int i = 0; i <= 7; i++) {
    if (lastButtonState[i] == LOW and buttonState[i] == HIGH) {
      // analogWrite(ledPins[i], 100);
    } else if (lastButtonState[i] == HIGH and buttonState[i] == LOW) {
      // analogWrite(ledPins[i], 0);
    }
  }
}


// void checkChannelLeds_KEYBOARD_MODE() {
//   for (int i = 0; i <= 2; i++) {
//     if (buttonOn[i][currentStep] == HIGH) {
//       analogWrite(channelLedPins[i], 100);
//     }else {
//       analogWrite(channelLedPins[i], 0);
//     }
//   }
// }

void checkStepButton_KEYBOARD_MODE() {
  for (int j = 0; j <= 7; j++) {
    lastButtonState[j] = buttonState[j];
    buttonState[j] = digitalRead(buttonPins[j]);
    if (lastButtonState[j] == LOW and buttonState[j] == HIGH) {
      usbMIDI.sendNoteOn(60 + majorScale[j], 127, 2);
      // set a int major scale of {0, 2, 4, 5, 7, 9, 11, 12} and perhaps minor scale instead of setting this j
      delay(5);
    } else if (lastButtonState[j] == HIGH and buttonState[j] == LOW) {
      usbMIDI.sendNoteOff(60 + j, 0, 2);
      delay(5);
    }
  }
}

// void checkChannelButton_KEYBOARD_MODE() {
//   Serial.println(channelDisplayed);
//   lastChannelButtonState = channelButtonState;
//   channelButtonState = digitalRead(35);
//   if (lastChannelButtonState == LOW and channelButtonState == HIGH) {
//     channelDisplayed = channelDisplayed + 1;
//     if (channelDisplayed > 2) {
//       channelDisplayed = 0;
//     }
//     delay(5);
//   } else if (lastChannelButtonState == HIGH and channelButtonState == LOW) {
//     delay(5);
//   }
// }