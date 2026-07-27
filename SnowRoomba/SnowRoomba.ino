//pins for the light and button
const int buttonPin = 11;
const int onPin = 12;
const int offPin = 13;
int buttonState = 0;

//pins for right side motors
const int PWMAR = 3;
const int AIN1R = 33;
const int AIN2R = 35;
const int BIN1R = 37;
const int BIN2R = 39;
const int PWMA2R = 2;

//pins for left side motors
const int PWMAL = 5;
const int AIN1L = 32;
const int AIN2L = 34;
const int BIN1L = 36;
const int BIN2L = 38;
const int PWMA2L = 4;


void setup() {
  // put your setup code here, to run once:
  //pin modes for the light and button
  pinMode(onPin, OUTPUT);
  pinMode(offPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  //right side motor pins
  pinMode(AIN1R, OUTPUT);
  pinMode(AIN2R, OUTPUT);
  pinMode(PWMAR, OUTPUT);
  pinMode(BIN1R, OUTPUT);
  pinMode(BIN2R, OUTPUT);
  pinMode(PWMA2R, OUTPUT);

  //left side motor pins
  pinMode(AIN1L, OUTPUT);
  pinMode(AIN2L, OUTPUT);
  pinMode(PWMAL, OUTPUT);
  pinMode(BIN1L, OUTPUT);
  pinMode(BIN2L, OUTPUT);
  pinMode(PWMA2L, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(onPin, HIGH);
    digitalWrite(offPin, LOW);

  //move motors forward
  moveForward();
  delay(4200);
  //moves right then left
  stop();
  moveRight();
  moveLeft();
  moveLeft();
  moveRight();
  stop();
  delay(2000);
  //moves backwards
  moveBackward();
  delay(4500);
  stop();
  

  } else {
    // turn LED off:
    digitalWrite(onPin, LOW);
    digitalWrite(offPin, HIGH);

    //stop motor
    stop();
  
  }
}

// int debounceButton (boolean state){
//   int currentState = digitalRead(buttonPin);

//   if(state != currentState){
//     delay(10);
//     currentState = digitalRead(buttonPin);
//   }

//   return currentState;
// }

void moveForward(){
  //right side pins
  digitalWrite(AIN1R, HIGH);
  digitalWrite(AIN2R, LOW);
  digitalWrite(BIN1R, HIGH);
  digitalWrite(BIN2R, LOW);
  analogWrite(PWMAR, 185);
  analogWrite(PWMA2R, 185);

  //left side pins
  digitalWrite(AIN1L, HIGH);
  digitalWrite(AIN2L, LOW);
  digitalWrite(BIN1L, HIGH);
  digitalWrite(BIN2L, LOW);
  analogWrite(PWMAL, 185);
  analogWrite(PWMA2L, 185);

}

void moveBackward() {
  //right side pins
  digitalWrite(AIN1R, LOW);
  digitalWrite(AIN2R, HIGH);
  digitalWrite(BIN1R, LOW);
  digitalWrite(BIN2R, HIGH);
  analogWrite(PWMAR, 100);
  analogWrite(PWMA2R, 100);

  //left side pinds  
  digitalWrite(AIN1L, LOW);
  digitalWrite(AIN2L, HIGH);
  digitalWrite(BIN1L, LOW);
  digitalWrite(BIN2L, HIGH);
  analogWrite(PWMAL, 100);
  analogWrite(PWMA2L, 100);
  
}

void stop (){
  //right side pins
  digitalWrite(AIN1R, LOW);
  digitalWrite(AIN2R, LOW);
  digitalWrite(BIN1R, LOW);
  digitalWrite(BIN2R, LOW);
  analogWrite(PWMAR, 0);
  analogWrite(PWMA2R, 0);

  //left side pins
  digitalWrite(AIN1L, LOW);
  digitalWrite(AIN2L, LOW);
  digitalWrite(BIN1L, LOW);
  digitalWrite(BIN2L, LOW);
  analogWrite(PWMAL, 0);
  analogWrite(PWMA2L, 0);
}

void moveRight(){
  //stops left side pins
  digitalWrite(AIN1L, LOW);
  digitalWrite(AIN2L, LOW);
  digitalWrite(BIN1L, LOW);
  digitalWrite(BIN2L, LOW);
  analogWrite(PWMAL, 0);
  analogWrite(PWMA2L, 0);

  //powers right side pins for a set time
  digitalWrite(AIN1R, HIGH);
  digitalWrite(AIN2R, LOW);
  digitalWrite(BIN1R, HIGH);
  digitalWrite(BIN2R, LOW);
  analogWrite(PWMAR, 185);
  analogWrite(PWMA2R, 185);
  //pauses for 2.5 seconds  
  delay(1640);

  //stops right side pins
  digitalWrite(AIN1R, LOW);
  digitalWrite(AIN2R, LOW);
  digitalWrite(BIN1R, LOW);
  digitalWrite(BIN2R, LOW);
  analogWrite(PWMAR, 0);
  analogWrite(PWMA2R, 0);

}

void moveLeft(){
  //stops right side pins
  digitalWrite(AIN1R, LOW);
  digitalWrite(AIN2R, LOW);
  digitalWrite(BIN1R, LOW);
  digitalWrite(BIN2R, LOW);
  analogWrite(PWMAR, 0);
  analogWrite(PWMA2R, 0);

  //powers left side pins for a set time
  digitalWrite(AIN1L, HIGH);
  digitalWrite(AIN2L, LOW);
  digitalWrite(BIN1L, HIGH);
  digitalWrite(BIN2L, LOW);
  analogWrite(PWMAL, 185);
  analogWrite(PWMA2L, 185);
  //pauses for 2.5 seconds  
  delay(1640);

  //stops left side pins
  digitalWrite(AIN1L, LOW);
  digitalWrite(AIN2L, LOW);
  digitalWrite(BIN1L, LOW);
  digitalWrite(BIN2L, LOW);
  analogWrite(PWMAL, 0);
  analogWrite(PWMA2L, 0);

}