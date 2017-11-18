int led = 9;
int buttonPin = 2;
int buttonCounter = 0;  // counter for the number of button presses
int state = 0;  // current state of the button
int lastState = 0;  // previous state of the button

void setup() {
  pinMode(buttonPin, INPUT); // initialize the button pin as a input
  Serial.begin(9600); // initialize serial communication
  pinMode(led,OUTPUT);
}

void loop() {
  state = digitalRead(buttonPin); // read the pushbutton input pin
      
  // compare the buttonState to its previous state
  if(state != lastState){
    
    if(state == HIGH){
      buttonCounter++;
      Serial.print(buttonCounter);
      Serial.println("on");
      }
    else{
      
      Serial.print(buttonCounter);
      Serial.println("off");
      }
    if(buttonCounter%2==0){
      Serial.println("LED off");
      digitalWrite(led,LOW);
      }
    else{
      Serial.println("LED on");
      digitalWrite(led,HIGH);
      delay(5000);
      digitalWrite(led,LOW);      
      }
    delay(100);
    
    }
   lastState = state; 
  
  
}    
