#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9,10); // CE, CSN pins
const byte address[6] = "00001";

void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  const char text[] = "hi world";
  
  // Check if the message was sent successfully
  bool success = radio.write(&text, sizeof(text));

  // Print "sending message" if the transmission was successful
  if (success) {
    Serial.println("Message sent: hi world");
  } else {
    Serial.println("Failed to send message");
  }
  
  delay(1000); // Adjust delay as needed
}
