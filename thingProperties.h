#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = "9cd70395-8341-4034-ad77-12c7acffd90a";

const char SSID[] = SECRET_SSID;    // Network SSID (name)
const char PASS[] = SECRET_OPTIONAL_PASS;    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[] = SECRET_DEVICE_KEY;    // Secret device password

void onLedChange();
void onPowerChange();

bool led;
bool power;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(led, READWRITE, ON_CHANGE, onLedChange);
  ArduinoCloud.addProperty(power, READWRITE, ON_CHANGE, onPowerChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
