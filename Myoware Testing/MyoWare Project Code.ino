int rawPin = A0;
int rectPin = A1;
int envPin = A2;
int rectVal, rawVal, envVal;
int low = 280;
int high = 360;
int center = 320;
int freq = 115200;
unsigned long threshold = 4000000;
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
const int NUMVALS = 6;
const char* valNames[] = { "low", "high", "center", "raw", "rect", "env" };
int vals[NUMVALS] = { low, high, center };
void setup() {
  // put your setup code here, to run once:
  Serial.begin(freq);
  pinMode(rectPin, INPUT);
  pinMode(rawPin, INPUT);
  pinMode(envPin, INPUT);
  pinMode(beepPin, OUTPUT);
  startOfLoopMillis = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long dt = millis() - startOfLoopMillis;
  startOfLoopMillis = millis();
  rawVal = analogRead(rawPin);
  rectVal = analogRead(rectPin);
  envVal = analogRead(envPin);
  vals[3] = rawVal;
  vals[4] = rectVal;
  vals[5] = envVal;
  for (int i = 0; i < NUMVALS; i++) {
    Serial.print(valNames[i]);
    Serial.print(":");
    Serial.print(vals[i]);
    if (i < NUMVALS - 1) {
      Serial.print(", ");
    }
  }
  Serial.println();
  if (!beeping) {

    if (rectVal > center) {

      iEMG += ((unsigned long)(rectVal - center) * dt) / 1000;  //numerical integration
      if (iEMG % 10000 < 200) {
        Serial.println(iEMG);
      }
    }
    if (iEMG > threshold) {
      iEMG = 0;
      startMillis = millis();
      beeping = true;
      Serial.println("starting beeps");
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
      Serial.println("this part also works");
    }
  }
}
