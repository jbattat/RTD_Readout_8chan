#include <Adafruit_MAX31865.h>
#include "SPI.h"
//#include <SoftwareSerial1.h>

// use hardware SPI, just pass in the CS pin
Adafruit_MAX31865 max_1 = Adafruit_MAX31865(7);
Adafruit_MAX31865 max_2= Adafruit_MAX31865(6);
Adafruit_MAX31865 max_3 = Adafruit_MAX31865(8);
Adafruit_MAX31865 max_4= Adafruit_MAX31865(5);
Adafruit_MAX31865 max_5 = Adafruit_MAX31865(9);
Adafruit_MAX31865 max_6= Adafruit_MAX31865(4);
Adafruit_MAX31865 max_7 = Adafruit_MAX31865(10);
Adafruit_MAX31865 max_8= Adafruit_MAX31865(3);

// The value of the Rref resistor. Use 430.0!!
#define RREF 430.0
#define RNOMINAL 100.0


void setup() {
  Serial1.begin(115200);
  Serial.begin(115200);  
  SPI.begin();
  max_1.begin(MAX31865_2WIRE);  // set to 2WIRE or 4WIRE as necessary
  max_2.begin(MAX31865_2WIRE); // set to 2WIRE or 4WIRE as necessary
  max_3.begin(MAX31865_2WIRE);
  max_4.begin(MAX31865_2WIRE);
  max_5.begin(MAX31865_2WIRE);  // set to 2WIRE or 4WIRE as necessary
  max_6.begin(MAX31865_2WIRE); // set to 2WIRE or 4WIRE as necessary
  max_7.begin(MAX31865_2WIRE);
  max_8.begin(MAX31865_2WIRE);
    delay(2000); 
  Serial.println("Teensy ready"); 
  //Serial1.println("test");          


}

void loop() {

  //delay(1000);
  if  (Serial1.available() > 0) { //added
    char receivedChar = Serial1.read();
    Serial.print("Got: ");
    Serial.println(receivedChar);
    if (receivedChar == 't') {
      Serial.println("Sending data"); 
     
  
      String temps = String(max_1.temperature(RNOMINAL, RREF)) + "," +
              String(max_2.temperature(RNOMINAL, RREF)) + "," +
              String(max_3.temperature(RNOMINAL, RREF)) + "," +
              String(max_4.temperature(RNOMINAL, RREF)) + "," +
              String(max_5.temperature(RNOMINAL, RREF)) + "," +
              String(max_6.temperature(RNOMINAL, RREF)) + "," +
              String(max_7.temperature(RNOMINAL, RREF)) + "," +
              String(max_8.temperature(RNOMINAL, RREF)) + ";";

      Serial1.println(temps);

      Serial.println(temps);


      //Serial1.print("Resistance1 = "); Serial1.println(RREFratio1,8);
      //  Serial1.print("Resistance2 = "); Serial1.println(RREFratio2,8);
      //Serial1.print("Resistance3 = "); Serial1.println(RREFratio3,8);
      //  Serial1.print("Resistance4 = "); Serial1.println(RREFratio4,8);

      //Serial1.print("Temperature1 = "); Serial1.println(max_1.temperature(RNOMINAL, RREF));
      //  Serial1.print("Temperature2 = "); Serial1.println(max_2.temperature(RNOMINAL, RREF));
      //Serial1.print("Temperature3 = "); Serial1.println(max_3.temperature(RNOMINAL, RREF));
      //  Serial1.print("Temperature4 = "); Serial1.println(max_4.temperature(RNOMINAL, RREF));

      // Check and print any faults
    //  uint8_t fault1 = max_1.readFault();
    //  uint8_t fault2 = max_2.readFault();
    //  uint8_t fault3 = max_3.readFault();
    //  uint8_t fault4 = max_4.readFault();
    //  uint8_t fault5 = max_5.readFault();
    //  uint8_t fault6 = max_6.readFault();
    //  uint8_t fault7 = max_7.readFault();
    //  uint8_t fault8 = max_8.readFault();
    //   delay(1000);
      }
    //for debugging, prints RTD, ratio, and temp
    if (receivedChar == 'd') {
      uint16_t rtd1 = max_1.readRTD();
      uint16_t rtd2 = max_2.readRTD();
      uint16_t rtd3 = max_3.readRTD();
      uint16_t rtd4 = max_4.readRTD();
      Serial.print(rtd1);
      Serial.print(",");
      Serial.print(rtd2);
      Serial.print(",");
      Serial.print(rtd3);
      Serial.print(",");
      Serial.print(rtd4);
      Serial.print(",");

      // Serial1.print("RTD value1: "); Serial1.println(rtd1);
      //Serial1.print("RTD value2: "); Serial1.println(rtd2);
      //Serial1.print("RTD value3: "); Serial1.println(rtd3);
      //Serial1.print("RTD value4: "); Serial1.println(rtd4);

      float ratio1 = rtd1;
      float ratio2 = rtd2;
      float ratio3 = rtd3;
      float ratio4 = rtd4;
    ratio1 /= 32768;
      ratio2 /= 32768;
      ratio3 /= 32768;
      ratio4 /= 32768;

      //Added this for python
      
      Serial1.print(ratio1,8);
      Serial1.print(",");
      Serial1.print(ratio2,8);
      Serial1.print(",");
      Serial1.print(ratio3,8);
      Serial1.print(",");
      Serial1.print(ratio4,8);
      Serial1.print(",");
      Serial1.print(max_1.temperature(RNOMINAL, RREF));
      Serial1.print(",");
      Serial1.print(max_2.temperature(RNOMINAL, RREF));
      Serial1.print(",");
      Serial1.print(max_3.temperature(RNOMINAL, RREF));
      Serial1.print(",");
      Serial1.print(max_4.temperature(RNOMINAL, RREF));
      Serial1.print(",");

      //Serial1.print("Resistance1 = "); Serial1.println(RREFratio1,8);
      //  Serial1.print("Resistance2 = "); Serial1.println(RREFratio2,8);
      //Serial1.print("Resistance3 = "); Serial1.println(RREFratio3,8);
      //  Serial1.print("Resistance4 = "); Serial1.println(RREFratio4,8);

      //Serial1.print("Temperature1 = "); Serial1.println(max_1.temperature(RNOMINAL, RREF));
      //  Serial1.print("Temperature2 = "); Serial1.println(max_2.temperature(RNOMINAL, RREF));
      //Serial1.print("Temperature3 = "); Serial1.println(max_3.temperature(RNOMINAL, RREF));
      //  Serial1.print("Temperature4 = "); Serial1.println(max_4.temperature(RNOMINAL, RREF));

      // Check and print any faults
      //uint8_t fault1 = max_1.readFault();
      //uint8_t fault2 = max_2.readFault();
      //uint8_t fault3 = max_3.readFault();
      //uint8_t fault4 = max_4.readFault();

    }
  }
}
