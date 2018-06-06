#include <LBLE.h>
#include <LBLEPeriphral.h>

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);

  // Initialize BLE subsystem
  Serial.println("BLE begin");
  LBLE.begin();
  while (!LBLE.ready()) {
    delay(100);
  }
  Serial.println("BLE ready");

  LBLEAdvertisementData beaconData;

  LBLEUuid uuid("E2C56DB5-DFFB-48D2-B060-D0F5A71096E0");
  beaconData.configAsIBeacon(uuid, 04, 65, -40);

  Serial.print("Start advertising iBeacon with uuid=");
  Serial.println(uuid);

  LBLEPeripheral.advertise(beaconData);
}

void loop() {

  delay(3000);
}
