int rawPin = A0;
int rectPin = A1;
int envPin = A2;
int rectVal, rawVal, envVal;
int low = 280;
int high = 360;
int center = 320;
int freq = 9600;
unsigned long threshold = 6000;
unsigned long iEMG = 0;
int totalBeeps = 5;
int beepPin = 3;
int numBeeps = 0;
unsigned long startMillis;
unsigned long startOfLoopMillis;
unsigned long currentMillis;
bool beeping = false;
int interval = 500;
bool beepState = false;
int value = 6;
const int NUMVALS = 8;
const char* valNames[] = { "low", "high", "center", "raw", "rect", "env", "threshold", "iEMG"};
unsigned long vals[NUMVALS] = { low, high, center };
void setup() {
  Serial.begin(freq);
  pinMode(rectPin, INPUT);
  pinMode(rawPin, INPUT);
  pinMode(envPin, INPUT);
  pinMode(beepPin, OUTPUT);
  startOfLoopMillis = millis();
}

void loop() {
  unsigned long dt = millis() - startOfLoopMillis;
  startOfLoopMillis = millis();
  rawVal = analogRead(rawPin);
  rectVal = analogRead(rectPin);
  envVal = analogRead(envPin);
  vals[3] = rawVal;
  vals[4] = rectVal;
  vals[5] = envVal;
  vals[6] = threshold;
  vals[7] = iEMG;
  for (int i = 0; i < NUMVALS; i++) {
    Serial.print(valNames[i]);
    Serial.print(":");
    Serial.print(vals[i]);
    if (i < NUMVALS - 1) {
      Serial.print("\t");
    }
  }
  Serial.println();
  if (!beeping) {

    if (envVal > center) {

      iEMG += ((unsigned long)(envVal - center) * dt);  //numerical integration
    }
    if (iEMG > threshold) {
      iEMG = 0;
      startMillis = millis();
      beeping = true;
    }
  }

  if (beeping) {
    if (numBeeps < totalBeeps) {
      currentMillis = millis();

      if (currentMillis - startMillis >= interval) {
        beepState = !beepState;
        if (!beepState) {
          numBeeps++;
        }
        digitalWrite(beepPin, beepState);  //true = high, false = low
        startMillis = currentMillis;
      }

    } else {
      beeping = false;
      numBeeps = 0;
      digitalWrite(beepPin, LOW);
    }
  }
}
