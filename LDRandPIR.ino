const int lamp = 7;            //LDR
boolean x = true;             

int ledPin = 13;               //PIR      
int inputPin = 2;             
int pirState = LOW;           
int val = 0;                 

void setup() {
Serial.begin(9600);            //S(LDR)
pinMode(lamp , OUTPUT);

pinMode(ledPin, OUTPUT);       //S(PIR)
pinMode(inputPin, INPUT);                                                 

}

void loop() {
  int c = analogRead(A0);      //L(LDR)   LDR INPUT
  delay(500);
if ( c>300&& x == true){       // IF INPUT HIGHER THAN VALUE
  digitalWrite(7,HIGH);        // TURNS LED ON !
   x = false;                  
   delay(1000);                // DELAYED (1000)
}
else if ( c <300 && x == false){ //IF INPUT LOWER THAN VALUE
x = true;                         
digitalWrite(7,LOW);             // TURNS LED OFF !
delay(6000);                     // DELAYED (6000)
}

val = digitalRead(inputPin);                                 //L(PIR)  PIR INPUT
  if (val == HIGH) {                                         // IF INPUT HIGH
    digitalWrite(ledPin, HIGH);                              // TURNS LED ON !
    if (pirState == LOW) {                                   // we have just turned on
    Serial.println("Motion detected!");                      // We only want to print on the output change, not state
      pirState = HIGH;                                                                         
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");                       // We only want to print on the output change, not state
      pirState = LOW;                                        //L(PIR) ENDS!
    }
  }
}
