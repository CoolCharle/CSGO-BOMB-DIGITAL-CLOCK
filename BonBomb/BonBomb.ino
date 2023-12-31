// BonBomb Main

// Variables
const int controlButtonPin = 2;  // Control button pin
const int cycleButtonPin = 3;    // Cycle button pin
const int ledPin = 13;
const int buzzerPin = 9;
const int NUM_TABS = 4;

int currentTab = 0;
int currentValue = 0;
int timerValue = 0;
int alarmValue = 0;
unsigned long stopwatchValue = 0;

const unsigned long timerInterval = 1000;  // Timer ticks every 1 second (in milliseconds)
const unsigned long stopwatchInterval = 100; // Stopwatch updates every 0.1 seconds (in milliseconds)
const unsigned long alarmCheckInterval = 60000; // Alarm checks every 1 minute (in milliseconds)

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
  // Update current time variable
  if (currentTab == TAB_CURRENT_TIME) {
    currentValue = timerValue;
  } else if (currentTab == TAB_TIMER) {
    // Update timer value variable
    timerValue = currentValue;
    flashValueOnScreen(timerValue);
  } else if (currentTab == TAB_ALARM) {
    // Update alarm value variable
    alarmValue = currentvalue;
    flashValueOnScreen(alarmValue);
  }
}

void controlButtonPressed() {
  // On Control Button press
  onFirstStartOrReset();
}

// Switch between modes
void cycleButtonPressed() {
  currentTab = (currentTab + 1) % NUM_TABS;
}

void timerTimerTick() {
  if (timerValue > 0) {
    digitalWrite(ledPin, HIGH); // Turn on the LED
    delay(500); // Keep the LED on for half a second
    digitalWrite(ledPin, LOW); // Turn off the LED
    delay(500);
    timerValue--;
  } else {
    digitalWrite(ledPin, LOW); // Turn off the LED if timerValue reaches 0
  }
}

void timerStopwatchTick() {
  // Stopwatch function
  // Use the millis() function to keep track of the elapsed time
  unsigned long elapsedTime = millis() - stopwatchStartTime;
}

void timerAlarmTick() {
  if (hour() == alarmValue) {
    tone(buzzerPin, 1000); // Adjust the frequency as needed
    delay(1000); // Play the sound for 1 second (adjust as needed)
    noTone(buzzerPin); // Turn off the buzzer
  }
}

void loop() {
  // Check for button presses and handle the corresponding functions
  if (digitalRead(controlButtonPin) == HIGH) {
    controlButtonPressed();
    delay(200); // Add a small delay to debounce the button
  }

  if (digitalRead(cycleButtonPin) == HIGH) {
    cycleButtonPressed();
    delay(200);
  }

  // Call timerTimerTick, timerStopwatchTick, and timerAlarmTick based on timing requirements
  unsigned long currentMillis = millis();

  if (currentMillis - previousTimerMillis >= timerInterval) {
    previousTimerMillis = currentMillis;
    timerTimerTick();
  }

  if (currentMillis - previousStopwatchMillis >= stopwatchInterval) {
    previousStopwatchMillis = currentMillis;
    timerStopwatchTick();
  }

  if (currentMillis - previousAlarmMillis >= alarmCheckInterval) {
    previousAlarmMillis = currentMillis;
    timerAlarmTick();
  }
}

