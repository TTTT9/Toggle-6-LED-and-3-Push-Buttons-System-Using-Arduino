const int ledPins[] = {5, 6, 7, 8, 9, 10};    // لمبات
const int buttonPins[] = {2, 3, 4};           // أزرار

bool ledStates[] = {false, false, false};     
bool lastButtonStates[] = {HIGH, HIGH, HIGH}; 

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  for (int i = 0; i < 3; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
}

void loop() {
  for (int i = 0; i < 3; i++) {
    bool currentState = digitalRead(buttonPins[i]);

    
    if (lastButtonStates[i] == HIGH && currentState == LOW) {
      ledStates[i] = !ledStates[i]; 
    }

    lastButtonStates[i] = currentState; 

   
    digitalWrite(ledPins[i * 2], ledStates[i] ? HIGH : LOW);
    digitalWrite(ledPins[i * 2 + 1], ledStates[i] ? HIGH : LOW);
  }
}
