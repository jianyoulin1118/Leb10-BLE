#include <LBLE.h>
#include <LBLEPeriphral.h>

void setup() {
  Serial.begin(115200);

  Serial.println("BLE begin");
  LBLE.begin();
  while (!LBLE.ready()) {
    delay(100);
  }
  Serial.println("BLE ready");

  LBLEAdvertisementData beaconData;

  beaconData.configAsEddystoneURL(EDDY_HTTPS, "google", EDDY_DOT_COM);

  Serial.print("Start advertising Eddystone-URL");

  LBLEPeripheral.advertiseAsBeacon(beaconData);
}

void loop() {
 
  delay(3000);
}
