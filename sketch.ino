// Simulating POV LED pattern on Arduino (Wokwi)

const int ledPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};  // 8 LEDs on digital pins

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void POVDisplay(byte pattern) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], (pattern >> i) & 1);
  }
  delay(200);  // Longer delay for visible simulation
}

void loop() {
  POVDisplay(0b00001110);
  POVDisplay(0b00011000);
  POVDisplay(0b10111101);
  POVDisplay(0b01110110);
  POVDisplay(0b00111100);
  POVDisplay(0b00111100);
  POVDisplay(0b00111100);
  POVDisplay(0b01110110);
  POVDisplay(0b10111101);
  POVDisplay(0b00011000);
  POVDisplay(0b00001110);
  clearAll();
  delay(500);
}

void clearAll() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}
