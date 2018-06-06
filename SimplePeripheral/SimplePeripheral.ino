#include <LBLE.h>
#include <LBLEPeriphral.h>

LBLEService ledService("05050465-E8F2-537E-4F6C-D104768A1214");
LBLECharacteristicInt switchCharacteristic("19B10011-E8F2-537E-4F6C-D104768A1214", LBLE_READ | LBLE_WRITE);

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  Serial.begin(9600);

  pinMode(6, INPUT);

  LBLE.begin();
  while (!LBLE.ready()) {
    delay(100);
  }
  Serial.println("BLE ready");

  Serial.print("Device Address = [");
  Serial.print(LBLE.getDeviceAddress());
  Serial.println("]");

  LBLEAdvertisementData advertisement;
  advertisement.configAsConnectableDevice("Jian");

  LBLEPeripheral.setName("Jian");

  ledService.addAttribute(switchCharacteristic);

  LBLEPeripheral.addService(ledService);

  LBLEPeripheral.begin();

  LBLEPeripheral.advertise(advertisement);
}

void loop() {
  delay(1000);

  Serial.print("conected=");
  Serial.println(LBLEPeripheral.connected());

  if (digitalRead(6))
  {
    Serial.println("disconnect all!");
    LBLEPeripheral.disconnectAll();
  }

  if (switchCharacteristic.isWritten()) {
    const char value = switchCharacteristic.getValue();
    switch (value) {
      case 1:
        digitalWrite(LED_BUILTIN, HIGH);
        break;
      case 0:
        digitalWrite(LED_BUILTIN, LOW);
        break;
      default:
        Serial.println("Unknown value written");
        break;
    }
  }
}
