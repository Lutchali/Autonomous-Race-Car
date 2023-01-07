/*Code by github.com/Lutchali*/
/*Disclaimer*/
/*Tis is still under active devellopment.
 * For updates check out my github.*/
/*Disclaimer*/

/*  Verdrahtung NodeMCU:
 *   BME280:
 *      Vcc           3V
 *      Gnd           G
 *      BME_SDA       RX
 *      BME_SCL       TX
*/
   

const char* ssid = "Fritz21EG";              
const char* password = "93595217897658499549";      
                             
#include <Wire.h>
#include <ESP8266WiFi.h>

void setup() {
  WiFi.setMode(WiFi.STATION)
  WiFi.sta.config("SSID","password")  

  WiFi.begin(ssid, password);
  delay(5000);

}

void loop() {   

} 