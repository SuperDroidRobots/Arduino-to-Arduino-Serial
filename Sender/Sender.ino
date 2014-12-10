// Sender Information
unsigned char START_BYTE = 0x53; // ASCII "S"
unsigned char counterValue = 0;
unsigned char staticValue = 5;
unsigned char checksum = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  // Increment our counter
  counterValue = counterValue + 1;
  
  // Check for overflow, and loop
  if (counterValue > 250)
    counterValue = 0;
    
  // Calculate our checksum
  checksum = counterValue + staticValue;
  
  // Important: Serial.write must be used, not print
  Serial.write(START_BYTE);
  Serial.write(counterValue);
  Serial.write(staticValue);
  Serial.write(checksum);
  
  // We only need to send a packet every 250 ms. 
  // If your code starts to get complicated, 
  // consider using a timer instead of a delay
  delay(250); 
}
