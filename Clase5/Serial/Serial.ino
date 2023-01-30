
#define LED 2

void Ejemplo1(void);
char rx;
void setup() {
 
pinMode(LED,OUTPUT);
Serial.begin(115200);


}

void loop() {


  if (Serial.available() > 0) {
     Serial.println("hola mundo");
    rx = Serial.read();
    if(rx=='A') digitalWrite(LED,HIGH);
    else if(rx=='B') digitalWrite(LED,LOW);

  }
 // delay(450);
}


void Ejemplo1(void){
    
Serial.println("hola mundo");
Serial.print(8572.225);
Serial.println("");
digitalWrite(LED,HIGH);
delay(200);
Serial.println("UMAKER");
Serial.print(8572.225);
Serial.println("");
digitalWrite(LED,LOW);
delay(200);


  
  }
