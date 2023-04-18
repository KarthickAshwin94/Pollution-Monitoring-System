#include "dht.h"
#define dht_apin A2 // Analog Pin sensor is connected to
dht DHT;
int sensorValue;
int digitalValue;
int soundSensorPin = A0;  // Sound sensor analog pin
int ledPin = 11;          // LED pin
int moistureSensorPin = A4;

 
void setup(){
 
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  delay(1000);//Wait before accessing Sensor
   pinMode(13, OUTPUT);
   pinMode(ledPin, OUTPUT); // Set LED pin as output
 
}//end "setup()"
 
void loop(){
  //Start of Program 
 
    DHT.read11(dht_apin);
    Serial.println("DHT11 Humidity & temperature Sensor:\n\n");
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    Serial.println();
    
    delay(2000);//Wait 5 seconds before accessing sensor again.
    sensorValue = analogRead(1); // read analog input pin 1
    Serial.println("The Value Read by MQ135 Sensor is:\n");
  if (sensorValue > 20)
  {
    digitalWrite(13, HIGH);
    Serial.print("The Surrounding Environment is over polluted:");
    Serial.println(sensorValue, DEC);
  }
  else
  {
    digitalWrite(13, LOW);
    Serial.print("The Surrounding Environement is less polluted:");
  Serial.println(sensorValue); // prints the value read
  Serial.println();
  }
  delay(2000); // wait 5seconds for next reading
  int soundLevel = analogRead(soundSensorPin); // Read the sound level                 // Print the sound level to serial monitor

  if (soundLevel >= 45) {  // If the sound level is greater than or equal to 500
    digitalWrite(ledPin, HIGH); // Turn on the LED
     Serial.print("The Environment is subject to a very high noise:");
     Serial.println(soundLevel);
  } else {
    digitalWrite(ledPin, LOW); // Turn off the LED
    Serial.print("The Environment is subject to less noise:");
    Serial.println(soundLevel);
  }
  delay(2000);
   int moistureLevel = analogRead(moistureSensorPin); 
   // Read the moisture level
   Serial.println("The Value read by Soil Moisture Sensor:");
  Serial.print("Moisture level: ");
  Serial.print(moistureLevel); // Print the moisture level to serial monitor
  Serial.println();
    
 
  //Fastest should be once every two seconds.
 
}// end loop()