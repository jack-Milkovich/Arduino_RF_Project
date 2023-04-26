#include <SPI.h>
#include <RF24.h>
#include <BTLE.h>

RF24 radio(9,10);

BTLE btle(&radio);

void setup() {

  Serial.begin(9600);
  while (!Serial) { }
  Serial.println("BTLE advertisement sender");

  btle.begin("sender");
}

void loop() {
  uint8_t dataType = 0;
  uint8_t *buffer1 = (uint8_t*)malloc(10 * sizeof(uint8_t));
  uint8_t len = 10;

  //populate the buffer to send with data
  for(int i = 0; i < 10; i++){
    buffer1[i] = i;    
  }

  Serial.println("Advertising to a channel");
  btle.advertise(dataType, buffer1, len);
  Serial.println("Advertising done... hopping channel");
  
  btle.hopChannel();
}
