/*      
 *  
 *  Audio only needs to be triggered once for every 
 *  PIR trigger.  Right now, even setting PINMODE
 *  in SETUP is triggering the audio constantly.
 *  
 */

 // int UNUSED = 11;          // UNUSED PIN
int pirSensor = 12;           // PIR SENSOR DETECT
int pirLed = 13;              // PIR LED 


int audioDelay= 1000;        //Trying audio delay to play audio only once
int audioCnt = 0;


int pirDelay = 2000;          // Delay time to let PIR settle


/// START AUDIO SETUP ==============================
///=================================================
///=================================================

int audioState = 0;

int audio_0 = A0;       // AUDIO TRIGGER PIN A0
int audio_1 = A1;       // AUDIO TRIGGER PIN A1
int audio_2 = A2;       // AUDIO TRIGGER PIN A2
int audio_3 = A3;       // AUDIO TRIGGER PIN A3
int audio_4 = A4;       // AUDIO TRIGGER PIN A4
int audio_5 = A5;       // AUDIO TRIGGER PIN A5
int audio_6 = A6;       // AUDIO TRIGGER PIN A6
int audio_7 = A7;       // AUDIO TRIGGER PIN A7

///=================================================
///=================================================
/// END AUDIO VAR ==================================




/// START LED FLASH VAR ============================
///=================================================
///=================================================

      // USE FEWER PINS TO HAVE SOME FOR THE AUDIO BOARD

            // int pins[] = {2, 11, 8, 3, 6, 10, 4, 7, 12, 5, 9};  // set up the 8 pins to use as outputs - these are for a mega change according to what setup you have
            // int flashTime[] = { 13000, 15000, 19000, 21000, 26000, 5200, 3500, 4000, 7000, 9000, 12000};  // set up the blink time of each LED
            // long int changeTime[] = {1000, 0, 500, 0, 3000, 0, 2000, 0, 1000, 6000, 0};  // array to hold when next to change the state of each LED

int pins[] = {2, 8, 3, 6, 10, 4, 7, 5, 9};  // set up the 8 pins to use as outputs - these are for a mega change according to what setup you have
int flashTime[] = { 13000, 15000, 19000, 21000, 26000, 5200, 7000, 9000, 12000};  // set up the blink time of each LED
long int changeTime[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};  // array to hold when next to change the state of each LED

char serial_char;


void setup() {
  pinMode(pirSensor, INPUT);
  pinMode(pirLed, OUTPUT);  

    Serial.begin(9600);
  Serial.println("start");

/// START AUDIO SETUP ==============================
///=================================================
///=================================================

                          
                                    // THIS IS TRIGGERING THE AUDIO NON STOP
//                          pinMode(audio_0, OUTPUT);       // Set pinMode to output - Man Down
//                          pinMode(audio_1, OUTPUT);       // Set pinMode to output - Younger
//                          pinMode(audio_2, OUTPUT);       // Set pinMode to output - Station 51
//                          pinMode(audio_4, OUTPUT);       // Set pinMode to output - Not hostile
//                          pinMode(audio_5, OUTPUT);       // Set pinMode to output - Talk too much
//                          pinMode(audio_6, OUTPUT);       // Set pinMode to output - nothing
//                          pinMode(audio_7, OUTPUT);       // Set pinMode to output - nothing


          // This is not triggering the audio.  Keep testing from here.
(audio_0, HIGH);           // Turn OFF audio output
(audio_1, HIGH);           // Turn OFF audio output
(audio_2, HIGH);           // Turn OFF audio output
(audio_3, HIGH);           // Turn OFF audio output
(audio_4, HIGH);           // Turn OFF audio output
(audio_5, HIGH);           // Turn OFF audio output
(audio_6, HIGH);           // Turn OFF audio output
(audio_7, HIGH);           // Turn OFF audio output

///=================================================
///=================================================
/// END AUDIO SETUP ================================



/// START LED FLASH SETUP ==========================
///=================================================
///=================================================
  for(int i=0; i<12; i++){
  pinMode(pins[i], OUTPUT);                    // sets the digital pins as output
  changeTime[i] = millis() + flashTime[i];    // set the time for the next change
  }
  

///=================================================
///=================================================
/// END LED FLASH SETUP ============================
}

void loop() {
//
//                Serial.println(audioCnt);
                Serial.println("WTF 1? ");
//                delay(1000);    

                
/// START AUDIO LOOP ===============================
///=================================================
///=================================================

//            int audioState = 1;
//                while(pirSensor=HIGH){
//                                  // F***************************CK
//                          pinMode(audio_3, OUTPUT);       // Set pinMode to output - Labor
//                    digitalWrite(audio_3, LOW);    // Turn ON audio output
//                    delay(500);
//                    digitalWrite(audio_3, HIGH);    // Turn OFF audio output
//                  audioState=0;
//                }
                         audioCnt + 1;

///=================================================
///=================================================
/// END AUDIO LOOP =================================



  int sensorValue = digitalRead(pirSensor);
  if (sensorValue == 1) {
    digitalWrite(pirLed, HIGH); // The LED

// 
//              if(audioCnt == 1){  
//                
//                Serial.println(audioCnt);
//                delay(1000);    
//                     
//                  pinMode(audio_3, OUTPUT);       // Set pinMode to output - Labor
//                    digitalWrite(audio_3, LOW);    // Turn ON audio output
//                    delay(500);
//                    digitalWrite(audio_3, HIGH);    // Turn OFF audio output
//                        audioCnt = audioCnt + 1;
//                Serial.println(audioCnt);
//                delay(1000);    
//               }



/// START LED FLASH LOOP ===========================
///=================================================
///=================================================


  for(int i=0 ; i<12; i++){ // look at each LED timer in turn
    if(millis()>changeTime[i]) {       // it is time to change the state of the LED
        digitalWrite(pins[i], !digitalRead(pins[i]) );  // make the LED the inverse of the current state (it's the ! that inverts)
        changeTime[i] = millis() + flashTime[i];        // set the time to make the next change

                
                    digitalWrite(audio_3, HIGH);    // Turn OFF audio output

        
    }  // end of time to change the state of the LED if statement
  }  // end of for loop looking at all the LEDs

///=================================================
///=================================================
/// END LED FLASH LOOP =============================    
  }
  else{
      digitalWrite(pirLed, LOW);

      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);


/// START AUDIO LOOP ===============================
///=================================================
///=================================================

//                    digitalWrite(audio_3, HIGH);    // Turn OFF audio output
//                  audioState=0;

                      audioCnt=0;



///=================================================
///=================================================
/// END AUDIO LOOP =================================


      
  }



  
}
