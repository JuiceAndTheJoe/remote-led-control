#include "thingProperties.h"

// Define the pin connected to the gate of the NMOS transistor
// const int GatePin = 2; // Change this to the actual pin number you're using

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
  */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  // Set the transistor gate pin as an output
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  ArduinoCloud.update();
  
  // Check the value of the cloud variable 'power' to control the LED strip
  if (power) {
      digitalWrite(LED_BUILTIN, HIGH);
    } else {
      // If power is false, turn off the LED strip
      digitalWrite(LED_BUILTIN, LOW);
  }
}

/*
  Since Led is READ_WRITE variable, onLedChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLedChange() {
  Serial.print("Led status changed:");
  Serial.println(led);
}

/*
  Since Power is READ_WRITE variable, onPowerChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onPowerChange() {
  Serial.print("Power changed:");
  Serial.println(power);
}
