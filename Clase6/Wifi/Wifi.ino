#include <WiFi.h>

WiFiServer server(8000);//escuchar a los clienes en mi puerto

void setup() {

  Serial.begin(115200);
  WiFi.begin("GODO-2.4G","luis1624");
while(WiFi.status() != WL_CONNECTED){
  Serial.println(".");
  delay(1000);
}
Serial.println("Wifi Conectado");
Serial.println(WiFi.localIP());//192.168.18.7

/*Init server*/

server.begin();
pinMode(2, OUTPUT);

}

void loop() {
  WiFiClient client = server.available();

    if (client) {
      Serial.println("Cliente Conectado");
      for(;;){
        while(client.available()){
          char rx = client.read();
            if (rx == 'a') digitalWrite(2, HIGH);
            if (rx == 'b') digitalWrite(2, LOW);
          
        }   
        //break;     
        //Serial.println("Cliente DesConectado");

      }        

    }


  

}
