// Sam Bonnell
int Mic = A0;
int Mic2 = A1;
int volume = 0;
int MicrophoneValue1 = 0;
int MicrophoneValue2 = 0;

int mic1constant = 0;
int mic2constant = 0;

// First audio sensor/////
int Audio1Led2 = 6;
int Audio1Led3 = 5;
int Audio1Led4 = 4;
int Audio1Led5 = 2;

// Second audio sensor/////
int Audio2Led1 = 8;
int Audio2Led2 = 9;
int Audio2Led3 = 10;
int Audio2Led4 = 11;

// Vibrate sensor LED
int VibrateLed1 = 7;
int VibrateLed2 = 12;
int VibrateLed3 = 13;

// Vibrate sensor
int Vibrate1 = 3;

void setup() {
  pinMode(Mic, INPUT);
  pinMode(Mic2, INPUT);

  pinMode(Vibrate1, INPUT);

  // First audio sensor/////
  pinMode(Audio1Led2, OUTPUT);
  pinMode(Audio1Led3, OUTPUT);
  pinMode(Audio1Led4, OUTPUT);
  pinMode(Audio1Led5, OUTPUT);
  
  // Second audio sensor/////
  pinMode(Audio2Led1, OUTPUT);
  pinMode(Audio2Led2, OUTPUT);
  pinMode(Audio2Led3, OUTPUT);
  pinMode(Audio2Led4, OUTPUT);

  // Vibrate sensor/////
  pinMode(VibrateLed1, OUTPUT);
  pinMode(VibrateLed2, OUTPUT);
  pinMode(VibrateLed3, OUTPUT);

  Serial.begin(9600);
}

void loop() {

 // Serial.println(mic1constant);
  long VibrateValue = pulseIn(Vibrate1, LOW);
  // Serial.println(VibrateValue);
  mic1constant = analogRead(Mic);
  delay(1);
  MicrophoneValue1 = analogRead(Mic);
  //Serial.println(MicrophoneValue1);
  mic2constant = analogRead(Mic2);
  delay(1);
  MicrophoneValue2 = analogRead(Mic2);

  // Serial.println(MicrophoneValue2);'
  //Serial.println(VibrateValue);
  // Testing the Vibration ///////

  if (VibrateValue > 0) {
    digitalWrite(VibrateLed1, HIGH);
    delay(10);
  }
  else {
    digitalWrite(VibrateLed1, LOW);
  }
  if (VibrateValue >= 20000) {
    digitalWrite(VibrateLed2, HIGH);
    delay(10);
  }
  else {
    digitalWrite(VibrateLed2, LOW);
  }
  if (VibrateValue >= 40000) {
    digitalWrite(VibrateLed3, HIGH);
    delay(10);
  }
  else {
    digitalWrite(VibrateLed3, LOW);
  }





  // Testing the Audio 1 /////////

  //one light
  if (MicrophoneValue1 > (mic1constant + 2)) {
    digitalWrite(Audio1Led2, HIGH);
    delay(10);
  }
  else {
    digitalWrite(Audio1Led2, LOW);
  }

  //two lights
  if (MicrophoneValue1 > (mic1constant + 6)) {

    digitalWrite(Audio1Led3, HIGH);
    delay(10);
  }
  else {

    digitalWrite(Audio1Led3, LOW);
  }

  //three lights
  if (MicrophoneValue1 > (mic1constant + 13)) {
    digitalWrite(Audio1Led4, HIGH);
    delay(10);
  }
  else {
    digitalWrite(Audio1Led4, LOW);
  }

  //all lights
  if (MicrophoneValue1 > (mic1constant + 21)) {
    digitalWrite(Audio1Led5, HIGH);
    delay(10);
  }
  else {
    digitalWrite(Audio1Led5, LOW);
  }

  //Second light (different method?)/////

  if (MicrophoneValue2 < (mic2constant - 1)) {
    digitalWrite(Audio2Led1, HIGH);
    delay(10);
  }
  else {
    digitalWrite(Audio2Led1, LOW);
  }

  if (MicrophoneValue2 < (mic2constant - 3)) {
    digitalWrite(Audio2Led2, HIGH);
    delay(10);
  }
  else {

    digitalWrite(Audio2Led2, LOW);
  }

  if (MicrophoneValue2 < (mic2constant - 5)) {
    digitalWrite(Audio2Led3, HIGH);
    delay(10);
  }
  else {

    digitalWrite(Audio2Led3, LOW);
  }

  if (MicrophoneValue2 < (mic2constant - 10)) {
    digitalWrite(Audio2Led4, HIGH);
    delay(10);
  }
  else {
    digitalWrite(Audio2Led4, LOW);

  }

}


