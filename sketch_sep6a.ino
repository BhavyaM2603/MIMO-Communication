#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(8, 10); // CE, CSN
const byte address[6] = "00001"; // Address must match the transmitter

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address); // Set the address to listen on
  radio.setPALevel(RF24_PA_LOW);     // Set power level (can change to RF24_PA_HIGH if necessary)
  radio.startListening();            // Start the receiver
}

void loop() {
  if (radio.available()) {
    int received_value = 0;
    radio.read(&received_value, sizeof(received_value));  // Read the incoming data

    Serial.print("Signal received: ");
    Serial.println(received_value);  // Print the received data
  } else {
    Serial.println("No signal detected.");
  }

  delay(1000); // Wait for 1 second before checking again
}