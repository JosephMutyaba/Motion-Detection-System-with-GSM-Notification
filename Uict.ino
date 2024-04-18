#include <SoftwareSerial.h>

#define PIR_PIN 6
#define BUZZER_PIN 12
#define GSM_RX_PIN 10
#define GSM_TX_PIN 9

int pirval =0;

// Define GSM module connections (RX, TX)
SoftwareSerial gsmSerial(GSM_TX_PIN, GSM_RX_PIN); //TX, RX

void setup() {
  Serial.begin(9600); // Start serial communication
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  // Initialize GSM module
  gsmSerial.begin(9600);
  Serial.println("GSM module initialized");
  delay(1000); // Wait for GSM module to initialize
}

void loop() {

  pirval = digitalRead(PIR_PIN);
  Serial.println(pirval);
  if (pirval == HIGH) { // If motion is detected
    digitalWrite(BUZZER_PIN, HIGH); // Turn on the buzzer
    sendSMS("+256779259295", "Security Alert! \r\nMotion Detected"); // Replace "+256779259295" with your mobile number
    Serial.println("Motion detected!");
    delay(2000); // Buzzer sound duration (2 seconds)
    digitalWrite(BUZZER_PIN, LOW); // Turn off the buzzer
    Serial.println("Buzzer off");
    delay(10000); // Wait for 10 seconds before rechecking
  }
}

void sendSMS(String number, String message) {
  gsmSerial.println("AT+CMGF=1"); // Set SMS mode to text
  delay(100);
  gsmSerial.print("AT+CMGS=\"");
  gsmSerial.print(number);
  gsmSerial.println("\"");
  delay(100);
  gsmSerial.println(message);
  delay(100);
  gsmSerial.println((char)26); // End SMS transmission
  delay(1000);
  
  // Print feedback from GSM module
  while (gsmSerial.available()) {
    Serial.write(gsmSerial.read());
  }
  Serial.println("SMS sent");
}
