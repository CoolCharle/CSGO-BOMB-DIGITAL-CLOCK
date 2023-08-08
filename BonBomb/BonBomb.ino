// BonBomb Main

// Variables
const int ledPin = 13;
const int buzzerPin = 9;

int currentValue = 0;
int timerValue = 0;
unsigned long stopwatchValue = 0;
int alarmValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(ledPin, LOW); // Turn off the LED initially
}

void flashValueOnScreen(int value) {
  // Flash the value on the LED screen
  for (int i=0; i<4; i++) {
    digitalWrite(ledPin,HIGH); // Turn on the LED
    delay(500); // Keep the LED on for half a second
    digitalWrite(ledPin,LOW); // Turn off the LED
    delay(500);
  }
}

void onFirstStartOrReset() {
  // Flash 4x 0 on screen
  flashValueOnScreen(0);

  // Reset all variables
  currentValue = 0;
  timerValue = 0;
  stopwatchValue = 0;
  alarmValue = 0;
}

void numberbuttonPressed() {
  // Flash the value on the LED screen
  flashValueOnScreen(value);

  // Update the currentValue
  currentValue = value;
}

void enterbuttonPressed() {

  
}

void loop() {
  // put your main code here, to run repeatedly:

}
