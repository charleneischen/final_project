bool buttonState[8] = { LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW };
bool lastButtonState[8] = { LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW };
boolean buttonOn[3][8] = {
  { false, false, false, false, false, false, false, false },
  { false, false, false, false, false, false, false, false },
  { false, false, false, false, false, false, false, false },
};

int buttonPins[8] = { 22, 21, 20, 19, 18, 17, 16, 15 };
// int ledPins[4] = { 0, 1, 2, 3 };
// int notes[8] = { 36, 38, 40, 41, 43, 45, 47, 48 };
// int notes[3] = { 36, 38, 42 };
unsigned long lastStepTime = 0;
int stepLength = 0;
int currentStep = 0;
int totalSteps = 8;
int channelDisplayed = 0;
// int directionSwitch = 33;
// int randomSwitch = 34;
// int channelButtonPin = 35;
// int modeSwitchPin = 36;
// int tempoPotPin = A14;
bool channelButtonState = LOW;
bool lastChannelButtonState = LOW;
// int channelLedPins[3] = { 15, 14, 13 };


void setup() {
  pinMode(buttonPins[0], INPUT);
  pinMode(buttonPins[1], INPUT);
  pinMode(buttonPins[2], INPUT);
  pinMode(buttonPins[3], INPUT);
  pinMode(buttonPins[4], INPUT);
  pinMode(buttonPins[5], INPUT);
  pinMode(buttonPins[6], INPUT);
  pinMode(buttonPins[7], INPUT);
  // pinMode(channelButtonPin, INPUT);
  // pinMode(ledPins[0], OUTPUT);
  // pinMode(ledPins[1], OUTPUT);
  // pinMode(ledPins[2], OUTPUT);
  // pinMode(ledPins[3], OUTPUT);
  // pinMode(channelLedPins[0], OUTPUT);
  // pinMode(channelLedPins[1], OUTPUT);
  // pinMode(channelLedPins[2], OUTPUT);
}

void loop() {
  //  stepLength = analogRead(A14);
  sequence();
  // if (digitalRead(modeSwitchPin) == HIGH) {
  //   sequencerMode();
  // } else if (digitalRead(modeSwitchPin) == LOW) {
  keyboardMode();
  // }
}

void sequence() {
  if (millis() > lastStepTime + stepLength) {
    lastStepTime = millis();
    Serial.println(currentStep);
    // if (digitalRead(randomSwitch) == HIGH) {
    //   randomMode();
    // } else if (digitalRead(directionSwitch) == HIGH) {
    nextStep();
    // } else {
    //   previousStep();
  }
  // for (int j = 0; j <= 7; j++) {
  //   if (buttonOn[j][currentStep] == HIGH) {
  //     usbMIDI.sendNoteOff(notes[j], 0, 1);
  //     usbMIDI.sendNoteOn(notes[j], 127, 1);
  //   }
  // }
}

void nextStep() {
  currentStep = currentStep + 1;
  if (currentStep >= totalSteps) {
    currentStep = 0;
  }
}

void previousStep() {
  currentStep = currentStep - 1;
  if (currentStep < 0) {
    currentStep = 3;
  }
}

void randomMode() {
  currentStep = random(4);
}

