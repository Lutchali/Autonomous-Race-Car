/*Code by github.com/Lutchali*/
/*Disclaimer*/
/*Tis is still under active devellopment.
 * For updates check out my github.*/
/*Disclaimer*/

/*You're free to use any part of my code,
 * but if you want to publish it on the internet
 * and use bigger parts of it,
 * just put my name in somewhere.
 */
/*  Verdrahtung NodeMCU:
 *   BME280:
 *      Vcc           3V
 *      Gnd           G
 *      BME_SDA       RX
 *      BME_SCL       TX
*/
   

const char* ssid = "Fritz21EG";              
const char* password = "93595217897658499549";      

unsigned long channelID = 1363027;
const char*  writeAPIKey = "Q557AE32D8OUAZP7";
                             
#include <BME280I2C.h>
#include <Wire.h>
#include <ThingSpeak.h>
#include <ESP8266WiFi.h>
#include <SPI.h> 
#include <TFT_eSPI.h> 

float Pres, Temp, Hum;

WiFiClient client;

BME280I2C bme;    //defining sensor

void setup() {
  ThingSpeak.begin(client);  

  WiFi.begin(ssid, password);
  delay(5000);

  Wire.begin(3,1);    
              
  while(!bme.begin())   
  {
    delay(1000);
  }

}

void loop() {   
    GetData();
    Upload();
    delay(40000);
} 

void GetData()   
{
   bme.read(Pres, Temp, Hum);  //Get data for sensor
   Pres = Pres/100;
}

void Upload(){
  long rssi = WiFi.RSSI();
  ThingSpeak.setField(1, Temp);  
  ThingSpeak.setField(2, Hum);  
  ThingSpeak.setField(3, Pres);  
  ThingSpeak.setField(4, rssi); 
  int status = ThingSpeak.writeFields(channelID, writeAPIKey); 
  if (status != 200){
     delay(1000);
     ThingSpeak.writeFields(channelID, writeAPIKey); 
  }
}
