// Sam Bonnell
// Final
int Mic = A0;
int Mic2 = A1;
int volume = 0;
int MicrophoneValue1 = 0;
int MicrophoneValue2 = 0;

int mic1constant = 0;
int mic2constant = 0;

// Vibrate sensor
int Vibrate1 = 3;

// First audio sensor/////
int laser1 = 2;
int laser2 = 4;
int laser3 = 5;
int laser4 = 6;
int laser5 = 7;

// Second audio sensor/////
int Led1 = 8;
int Led2 = 9;
int Led3 = 10;


// Vibrate sensor fans
int fan1 = 11;
int fan2 = 12;
int fan3 = 13;



void setup() {
  pinMode(Mic, INPUT);
  pinMode(Mic2, INPUT);

  pinMode(Vibrate1, INPUT);
  // pinMode(Vibrate2, INPUT);
  // pinMode(Vibrate3, INPUT);

  // First audio sensor/////
  pinMode(laser1, OUTPUT);
  pinMode(laser2, OUTPUT);
  pinMode(laser3, OUTPUT);
  pinMode(laser4, OUTPUT);
  pinMode(laser5, OUTPUT);

  // Second audio sensor/////
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);

  // Vibrate sensor/////
  pinMode(fan1, OUTPUT);
  pinMode(fan2, OUTPUT);
  pinMode(fan3, OUTPUT);

  Serial.begin(9600);
}

void loop() {


  long VibrateValue = pulseIn(Vibrate1, LOW);
  // Serial.println(VibrateValue);

  // MIC
  mic1constant = analogRead(Mic);
  delay(1);
  MicrophoneValue1 = analogRead(Mic);
  Serial.println(MicrophoneValue1);
  mic2constant = analogRead(Mic2);
  delay(1);
  MicrophoneValue2 = analogRead(Mic2);

  //Serial.println(MicrophoneValue2);
  //Serial.println(VibrateValue);
  // Testing the Vibration ///////

  if (VibrateValue > 0 && VibrateValue < 1000) {
    digitalWrite(fan1, HIGH);
    delay(100);
  }
  else {
    if (VibrateValue >= 1000 && VibrateValue < 4000) {
      digitalWrite(fan1, HIGH);
      digitalWrite(fan2, HIGH);
      delay(100);
    }
    else {
      if (VibrateValue >= 4000) {
        digitalWrite(fan1, HIGH);
        digitalWrite(fan2, HIGH);
        digitalWrite(fan3, HIGH);
        delay(100);
      }
      else {
        digitalWrite(fan1, LOW);
        digitalWrite(fan2, LOW);
        digitalWrite(fan3, LOW);
      }
    }
  }



  //////////////////////////////////////////////////////////////////////////////////////////

  // Testing the Audio 1 /////////
  if (MicrophoneValue1 > mic1constant) {
    //one laser
    if (MicrophoneValue1 >= (mic1constant + 2) && MicrophoneValue1 < (mic1constant + 10)) {
      digitalWrite(laser1, HIGH);
      delay(10);
    }
    else {

      //two lasers
      if (MicrophoneValue1 >= (mic1constant + 10) && MicrophoneValue1 < (mic1constant + 20)) {
        digitalWrite(laser1, HIGH);
        digitalWrite(laser2, HIGH);
        delay(10);
      }
      else {

        //three lasers
        if (MicrophoneValue1 >= (mic1constant + 20) && MicrophoneValue1 < (mic1constant + 43)) {
          digitalWrite(laser1, HIGH);
          digitalWrite(laser2, HIGH);
          digitalWrite(laser3, HIGH);
          delay(10);
        }
        else {

          //4 lasers
          if (MicrophoneValue1 >= (mic1constant + 38) && MicrophoneValue1 < (mic1constant + 38)) {
            digitalWrite(laser1, HIGH);
            digitalWrite(laser2, HIGH);
            digitalWrite(laser3, HIGH);
            digitalWrite(laser4, HIGH);
            delay(10);
          }
          else {

            //all lasers
            if (MicrophoneValue1 >= (mic1constant + 75)) {
              digitalWrite(laser1, HIGH);
              digitalWrite(laser2, HIGH);
              digitalWrite(laser3, HIGH);
              digitalWrite(laser4, HIGH);
              digitalWrite(laser5, HIGH);
              delay(10);
            }
            else {
              digitalWrite(laser1, LOW);
              digitalWrite(laser2, LOW);
              digitalWrite(laser3, LOW);
              digitalWrite(laser4, LOW);
              digitalWrite(laser5, LOW);
              delay(10);

            }
          }
        }
      }
    }
  }
  else {
    if (MicrophoneValue1 <= (mic1constant - 2) && MicrophoneValue1 > (mic1constant - 10)) {
      digitalWrite(laser1, HIGH);
      delay(10);
    }
    else {

      //two lasers
      if (MicrophoneValue1 <= (mic1constant - 10) && MicrophoneValue1 > (mic1constant - 20)) {
        digitalWrite(laser1, HIGH);
        digitalWrite(laser2, HIGH);
        delay(10);
      }
      else {

        //three lasers
        if (MicrophoneValue1 <= (mic1constant - 20) && MicrophoneValue1 > (mic1constant - 38)) {
          digitalWrite(laser1, HIGH);
          digitalWrite(laser2, HIGH);
          digitalWrite(laser3, HIGH);
          delay(10);
        }
        else {

          //4 lasers
          if (MicrophoneValue1 <= (mic1constant - 38) && MicrophoneValue1 > (mic1constant - 75)) {
            digitalWrite(laser1, HIGH);
            digitalWrite(laser2, HIGH);
            digitalWrite(laser3, HIGH);
            digitalWrite(laser4, HIGH);
            delay(10);
          }
          else {

            //all lasers
            if (MicrophoneValue1 <= (mic1constant - 75)) {
              digitalWrite(laser1, HIGH);
              digitalWrite(laser2, HIGH);
              digitalWrite(laser3, HIGH);
              digitalWrite(laser4, HIGH);
              digitalWrite(laser5, HIGH);
              delay(10);
            }
            else {
              digitalWrite(laser1, LOW);
              digitalWrite(laser2, LOW);
              digitalWrite(laser3, LOW);
              digitalWrite(laser4, LOW);
              digitalWrite(laser5, LOW);
              delay(10);

            }
          }
        }
      }
    }
  }

  //////////////////////////////////////////////////////////////////////////////////////////



  //  //Second light /////

  if (MicrophoneValue2 > mic2constant) {
    //one light
    if (MicrophoneValue2 >= (mic2constant + 2) && MicrophoneValue2 < (mic2constant + 18)) {
      digitalWrite(Led1, HIGH);
      delay(10);
    }
    else {

      //two lights
      if (MicrophoneValue2 >= (mic2constant + 18) && MicrophoneValue2 < (mic2constant + 40)) {
        digitalWrite(Led1, HIGH);
        digitalWrite(Led2, HIGH);
        delay(10);
      }
      else {

        //all lights
        if (MicrophoneValue2 >= (mic2constant + 40)) {
          digitalWrite(Led1, HIGH);
          digitalWrite(Led2, HIGH);
          digitalWrite(Led3, HIGH);
          delay(10);
        }
        else {
          digitalWrite(Led1, LOW);
          digitalWrite(Led2, LOW);
          digitalWrite(Led3, LOW);
          delay(10);

        }
      }
    }
  }

  else {
    //one light
    if (MicrophoneValue2 <= (mic2constant - 2) && MicrophoneValue2 > (mic2constant - 18)) {
      digitalWrite(Led1, HIGH);
      delay(10);
    }
    else {

      //two lights
      if (MicrophoneValue2 <= (mic2constant - 18) && MicrophoneValue2 > (mic2constant - 40)) {
        digitalWrite(Led1, HIGH);
        digitalWrite(Led2, HIGH);
        delay(10);
      }

      else {

        //all lights
        if (MicrophoneValue2 <= (mic2constant - 40)) {
          digitalWrite(Led1, HIGH);
          digitalWrite(Led2, HIGH);
          digitalWrite(Led3, HIGH);
          delay(10);
        }
        else {
          digitalWrite(Led1, LOW);
          digitalWrite(Led2, LOW);
          digitalWrite(Led3, LOW);
          delay(10);

        }
      }
    }
  }
  
}


