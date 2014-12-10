// Sender Information
unsigned char START_BYTE = 0x53; // ASCII "S"
unsigned char counterValue = 0;
unsigned char staticValue = 0;
unsigned char checksum = 0;

// Sync Byte flag
boolean syncByteFound = 0;

void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);
}

void loop() {
  
  unsigned char rxByte = 0;
  unsigned char calculatedChecksum = 0;
  
  // Check to see if there's something to read
  if (Serial2.available() > 0 ) {
    
    // If we're waiting for a new packet, check for the sync byte
    if (syncByteFound == 0) {
      rxByte = Serial2.read();
      if (rxByte == 0x53)
        syncByteFound = 1;
    }
    
    // If we've found our sync byte, check for expected number of bytes
    if (Serial2.available() > 2) {
      counterValue = Serial2.read();
      staticValue = Serial2.read();
      checksum = Serial2.read();
        
      calculatedChecksum =  counterValue + staticValue;
      
      // Print out our serial information to debug
      Serial.print("["); Serial.print("S"); Serial.print("]");
      Serial.print("["); Serial.print(counterValue); Serial.print("]");
      Serial.print("["); Serial.print(staticValue); Serial.print("]");
      Serial.print("["); Serial.print(checksum); Serial.print("]");
      
      if (calculatedChecksum == checksum) 
        Serial.println("[Checksum Passed]");

      else
        Serial.println("[Checksum FAILED]");
            
      syncByteFound = 0;
    }
  }
}
