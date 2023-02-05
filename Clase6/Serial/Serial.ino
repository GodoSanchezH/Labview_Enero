
uint16_t adc1,adc2,adc3,adc4;
uint8_t digi_int0,digi_int1;
char rx_labview;

void setup() {
  /*Definimos nuestas salidas*/
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);

  /*Definimos nuestas entradas*/  
  pinMode(2, INPUT);
  pinMode(3, INPUT);

  /*inicializamos la comunicacion serial*/
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available()>0) {
  
    rx_labview = Serial.read();
      if (rx_labview == 'X') {
        
        adc1=analogRead(0);
        adc2=analogRead(1);
        adc3=analogRead(2);
        adc4=analogRead(3);
      
      
      digi_int0 = digitalRead(2);
      digi_int1 = digitalRead(3);
    /*escribimo la info*/
      Serial.print(adc1);  
      Serial.print("s");
      Serial.print(adc2);
      Serial.print("s");
      Serial.print(adc3);
      Serial.print("s");
      Serial.print(adc4);
      Serial.print("s");
      Serial.print(digi_int0);
      Serial.print("s");
      Serial.print(digi_int1);
     }
    /*salidas digitales*/
    if (rx_labview == 'A') digitalWrite(13,HIGH);
    if (rx_labview == 'B') digitalWrite(13,LOW);
    if (rx_labview == 'C') digitalWrite(12,HIGH);
    if (rx_labview == 'D') digitalWrite(12,LOW);
    if (rx_labview == 'E') digitalWrite(11,HIGH);
    if (rx_labview == 'F') digitalWrite(11,LOW);
    if (rx_labview == 'G') digitalWrite(10,HIGH);
    if (rx_labview == 'H') digitalWrite(10,LOW);;
  }



}
