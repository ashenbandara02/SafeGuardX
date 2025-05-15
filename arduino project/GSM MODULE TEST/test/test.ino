#include <SoftwareSerial.h>

// Create a SoftwareSerial object to communicate with the SIM800L module
SoftwareSerial mySerial(3, 2); // SIM800L Tx & Rx connected to Arduino pins #3 & #2

void setup() {
  // Initialize serial communication with Arduino and the Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  
  // Initialize serial communication with Arduino and the SIM800L module
  mySerial.begin(9600);
  
  Serial.println("Initializing...");
  delay(1000);
  
  // Send some initial AT commands
  mySerial.println("AT"); // Handshake test
  updateSerial();
  mySerial.println("AT+CSQ"); // Signal quality test
  updateSerial();6666666669
  mySerial.println("AT+CCID"); // Read SIM information
  updateSerial();
  mySerial.println("AT+CREG?"); // Check network registration
  updateSerial();
  
  // Now, let's send an SMS
  sendSMS("+94775631149", "Hello machan ube wahNE KALLAK USSALA WAREN TAGGALA ......... (By GSM MODULE)");
}

void loop() {
  updateSerial();
}

void updateSerial() {
  delay(500);
  while (Serial.available()) {
    mySerial.write(Serial.read()); // Forward data from Serial to Software Serial Port
  }
  while (mySerial.available()) {
    Serial.write(mySerial.read()); // Forward data from Software Serial to Serial Port
  }
}

void sendSMS(String phoneNumber, String message) {
  mySerial.println("AT+CMGF=1"); // Set SMS mode to text
  updateSerial();
  mySerial.print("AT+CMGS=\""); // Prepare to send SMS
  mySerial.print(phoneNumber); // Add recipient's phone number
  mySerial.println("\""); // End the phone number command
  updateSerial();
  
  mySerial.println(message); // Write the SMS message content
  updateSerial();
  mySerial.write(26); // Send the Ctrl+Z character to indicate end of message
  delay(1000); // Wait for a moment to let the message be sent
  updateSerial();
}
