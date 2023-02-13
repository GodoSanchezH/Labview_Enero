#include <WiFi.h>
#include <PubSubClient.h>

WiFiClient espClient;
PubSubClient client(espClient);
char msg[30];
void setup() {
  setup_wifi();
  client.setServer("192.168.18.7", 1883);
  client.setCallback(callback);
  pinMode(2,OUTPUT);
}
void callback(char* topic, byte* payload, unsigned int length)
{
   payload[length]= '\0';
   String val = String((char*)payload);
   Serial.println(val);
   if(val == "a")
    {digitalWrite(2,HIGH);}
   if(val == "b")
    {digitalWrite(2,LOW);}
}
void reconnect()
{
  while (!client.connected())
    {
      if(client.connect("ESP32"))
        {
          Serial.println("Conexión exitosa");
          client.subscribe("data");
        }
      }
}
void loop() {
  if(!client.connected())
    {
      reconnect();
    }
  client.loop();
  client.publish("canal","umaker");
  delay(3000);
}

void setup_wifi()
{
  Serial.begin(115200);
  WiFi.begin("GODO-2.4G", "luis1624");
  while (WiFi.status() != WL_CONNECTED)
  { delay(300);
    Serial.print(".");
  }
  Serial.println();
  Serial.println(WiFi.localIP()); 
}