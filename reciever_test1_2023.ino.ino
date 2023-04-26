#include <SPI.h>
#include <RF24.h>
#include <BTLE.h>

RF24 radio(9,10);

BTLE btle(&radio);

void setup() {

  Serial.begin(9600);
  while (!Serial) { }
  Serial.println("BTLE advertisement receiver test 1");

  btle.begin("Reciver");
}

//will run thru each of the channels to check for input and print stuff about the input
void loop() {
    
  Serial.print("Listening... ");
  
  if (btle.listen()) {
    Serial.println("Package found");
    printInfo(btle);
  }
  
  Serial.println("done, hopping channel...");
  delay(5000); //5 seconds
  
  btle.hopChannel();
}


void printInfo(BTLE btle){
    Serial.print("Size of buffer: ");
    Serial.println(btle.buffer.pl_size, DEC); 
    Serial.print("PDU Type: ");
    Serial.println(btle.buffer.pdu_type, DEC);

    Serial.println("The payload of data is:");
    for (uint8_t i = 0; i < (btle.buffer.pl_size); i++) { Serial.print("At this index: "); Serial.println(btle.buffer.payload[i],DEC); Serial.println(" "); }
}
