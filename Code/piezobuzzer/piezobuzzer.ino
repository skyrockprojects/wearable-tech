int piezo = A2;
int buzzer = 5;
void setup() {
  // put your setup code here, to run once:
  pinMode(piezo,INPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (analogRead(piezo)>500){
    tone(buzzer,659,300); 
    
//tone(pin, frequency, duration)
//pin: the pin on which to generate the tone
//frequency: the frequency of the tone in hertz - unsigned int
//duration: the duration of the tone in milliseconds (optional) - unsigned long
    
    delay(300);
    noTone(buzzer);
    }

}
