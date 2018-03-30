int twinkleLoops = 10;
int backAndForthLoops = 3;
int counter = 0;


int timer = 100;           // The higher the number, the slower the timing.
int startPin = 22;
int endPin = 47;
int incAmount = 25;
int fastest = 25;
int slowest = 100;
boolean  firstRun = true;

int led1;
int led2;
int led3;
int led4;
int led5;
int led6;
int led7;

void setup() {
  // use a for loop to initialize each pin as an output:
  for (int thisPin = startPin; thisPin <= endPin; thisPin++)  {
    pinMode(thisPin, OUTPUT);      
  }
  
}

void loop() {
  
  // Turn all LEDs on for the Twinkle Mode:
  for (int thisPin = startPin; thisPin <= endPin; thisPin++) { 
    digitalWrite(thisPin, HIGH);   
  }
  
  // Twinkle for a bit:
  while ( counter <= twinkleLoops ){
    twinkle();
    counter++;
  }
  
  doReset();
  
  
  // Back And Forth for a bit:
  while ( counter <= backAndForthLoops ){
    backAndForth();
    counter++;
  }
  
  doReset();
  
  spell();
  
  doReset();
  
}

void doReset(){
   // Reset and turn all the LEDs off:
  // Turn all LEDs off for the next mode:
  counter = 0;
  timer = slowest;
  firstRun = true;
  incAmount = 25;
  for (int thisPin = startPin; thisPin <= endPin; thisPin++) { 
    digitalWrite(thisPin, LOW);   
  } 
}


////////////////////////////////////////////////////
// back and forth with speed up:
////////////////////////////////////////////////////
void backAndForth(){

  // loop from the lowest pin to the highest:
  for (int thisPin = startPin; thisPin <= endPin; thisPin++) { 
    // turn the pin on:
    digitalWrite(thisPin, HIGH);   
    delay(timer);                  
    // turn the pin off:
    digitalWrite(thisPin, LOW);    
  }

  // loop from the highest pin to the lowest:
  for (int thisPin = endPin; thisPin >= startPin; thisPin--) { 
    // turn the pin on:
    digitalWrite(thisPin, HIGH);
    delay(timer);
    // turn the pin off:
    digitalWrite(thisPin, LOW);
  }
  
  if ( timer == fastest || ( !firstRun && timer == slowest) ) {
    // switch direction:
    incAmount = -incAmount;
  } 
  
  timer = timer - incAmount;
  
  firstRun = false;
}


////////////////////////////////////////////////////
// Twinkles:
//    - Pick 5 random lights and turn them off
////////////////////////////////////////////////////
void twinkle() {
 
  // Pick Random pins:
  led1 = random( startPin, endPin + 1);
  led2 = random( startPin, endPin + 1);
  led3 = random( startPin, endPin + 1);
  led4 = random( startPin, endPin + 1);
  led5 = random( startPin, endPin + 1);  
  led6 = random( startPin, endPin + 1);
  led7 = random( startPin, endPin + 1); 
  
  // Turn them off:
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  
  // Wait for some time:
  delay( random(750, 2500) );  
  
  // Turn them back on:
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  
}

////////////////////////////////////////////////////
// Spells "happy halloween"
////////////////////////////////////////////////////
void spell() {
  
  int charPins[] = { 29, 22, 37, 37, 46, 29, 22, 33, 33, 36, 44, 26, 26, 35 };
  int charCount = 14;
  
  for (int i=0; i < charCount; i++){
      digitalWrite( charPins[i], HIGH);
      delay(1250);
      digitalWrite( charPins[i], LOW);
      delay(120);
   } 
   
   delay(1000);
  
  
}
