/*
  First attempt talking to the IC
  Ben V. Brown <ralim@ralimtek.com>
*/

#include <Wire.h>
#define TIMESCALE_US 0
#define TIMESCALE_MS 1
#define TIMESCALE_S 2
#define TIMESCALE_MIN 3


void setup()
{
  Wire.begin();
  Serial.begin(1000000);
  Serial.println("ISL94202 Test");
  Wire.beginTransmission(0x01);
  Wire.write(00);
  Wire.endTransmission(true);
  //False comms to unlock I2c state machine on the ic if we mess up^
  disableEEPROMAccess();
  writeReg(0x85, 0b00010000);//Set current shunt gain
  Serial.println("Press s to set the default settings to the unit");
  Serial.println("Press r to display one reading");
  Serial.println("Press R to continiously display readings");
  Serial.println("Created by Ben V. Brown");
}

bool continiousReadings = false;
bool continiousPlot = false;
void loop()
{
  if (Serial.available())
  {
    char c = Serial.read();
    if (c == 'r')    {

      Serial.println("Cells : ");
      for (uint8_t i = 0; i < 8; i++)
        Serial.println(readCellV(i));
      Serial.print("Current : ");
      readCurrent();
      Serial.print("Pack V: ");
      Serial.println(readPackV());
      Serial.print("Minimum Cell :");
      Serial.println(minCellV());
      Serial.print("Maximum Cell :");
      Serial.println(maxCellV());
      printStatus();
      Serial.println();
    }
    else if (c == 'R')
    {
      continiousReadings = !continiousReadings;
    }
    else if (c == 'p')
    {
      continiousPlot = !continiousPlot;
    }
    else if (c == 'd')
    {
      Serial.println("Settings");
      //dump settings
      Serial.print("Over Voltage Threshold ");
      Serial.println(OVThreshold());
      Serial.print("Over Voltage Recovery ");
      Serial.println(OVRecovery());
      Serial.print("Under Voltage Threshold ");
      Serial.println(UVThreshold());
      Serial.print("Under Voltage Recovery ");
      Serial.println(UVRecovery());
    } else if (c == 'e')
    {
      //Read EEPROM
      Serial.println(F("Reading User EEPROM"));
      enableEEPROMAccess();
      delay(1);
      for (uint8_t i = 0; i < 4; i++)
        Serial.println(readUserEEPROM(i), HEX);
      disableEEPROMAccess();
    }
    else if (c == 'E')
    {
      Serial.println(F("Writing User EEPROM"));
      Serial.println(writeUserEEPROM(0, millis() % 0xFF));

    } else if (c == 's')
    {
      //Load in the settings
      setOVThres(4250, 1);//Turn off charging the pack at 4.25V
      setOVRecovery(4150);//Turn back on charging once discharged to 4.15V
      setUVThres(3000, 1);//Turn off the pack output when any cell is below 3V
      setUVRecovery(3100);//Turn discharging back on when the lowest cell is above 3.1V
      setOVLockout(4300);//Permanently shutdown the pack if a cell goes above 4.3V
      setUVLockout(2500);//Permanently shutdown the pack if a cell falls below 2.5V
      setEOCThreshold(4200);//Mark End of Charge once any cell is at 4.2V
      setDischargeOverCurrent(32, 500, TIMESCALE_MS);//Set the discharge current limit to 32mV == 16A. Averaged over 0.5S
      setChargeOverCurrent(24, 500, TIMESCALE_MS);//Set the charge current limit to 24mV == 12A. Averaged over 0.5S
      setDischargeShortCircuit(64, 500, TIMESCALE_US);//Set the short circuit protection to 64mV == 32A over 0.5mS
      setCellBalanceOnOffTime(9, TIMESCALE_S, 1, TIMESCALE_S);//Set balance time to 9S on, and 1S off
      setCellCountSleepMode(3, 10, 32);//Set the unit to 3S cell count. 10 minutes to enter lower power modes. 32 minutes to enter deep sleep
      setCellBalanceDifference(10);//Balance cells until they are withing 10mV maximum error
      setCellBalanceMin(3850);//Start the blanacing when the cells are above 3.85V
      setCellBalanceMax(4300);//Stop balancing if the cells are above 4.3V (Set high to disable this feature).
      setFeature1(true, true, false, false, false, true);
      setFeature2(false, true, true, true, true, true);
      Serial.println(F("Please disconnect and reconnect the battery to force an EEPROM reload."));
      delay(10000);
    }
  }
  delay(500);
  if (continiousReadings)
  {
    Serial.print("Current : ");
    readCurrent();
    Serial.print("Pack V: ");
    Serial.println(readPackV());
    Serial.print("Minimum Cell :");
    Serial.println(minCellV());
    Serial.print("Maximum Cell :");
    Serial.println(maxCellV());
    printStatus();
    Serial.println();
  }
  if (continiousPlot)
  {
    uint8_t r2 = readReg(0x8E);
    uint8_t r1 = readReg(0x8F);
    float reading = (((uint16_t)(r2 << 8 | r1)) & 0xFFFF);
    reading *= (1.8);
    reading /= (4095 * 2.89);
    Serial.println(reading);

  }
}
//Settings


void setDischargeOverCurrent(uint8_t threshold, uint16_t count, uint8_t timeScale)
{
  //Threshold 000 is 4mV, each step ={4,8,16,24,32,48,64,96}
  //timescale = {us,ms,s,min}
  //default is 32mV,160ms
  uint8_t thres = 0xFF;
  switch (threshold)
  {
    case 4:
      thres = 0;
      break;
    case 8:
      thres = 1;
      break;
    case 16:
      thres = 2;
      break;
    case 24:
      thres = 3;
      break;
    case 32:
      thres = 4;
      break;
    case 48:
      thres = 5;
      break;
    case 64:
      thres = 6;
      break;
    case 96:
      thres = 7;
      break;
    default:
      thres = 0xFF;
  }
  if (thres == 0xFF)
  {
    Serial.println(F("Invalid threshold"));
    return;
  }
  writeEEPROMTimeout(0x16, count, timeScale, thres);
}
void setChargeOverCurrent(uint8_t threshold, uint16_t count, uint8_t timeScale)
{
  //Threshold 000 is 1mV, each step ={1,2,4,6,8,12,16,24}
  //timescale = {us,ms,s,min}
  //default is 8mV,160ms
  uint8_t thres = 0xFF;
  switch (threshold)
  {
    case 1:
      thres = 0;
      break;
    case 2:
      thres = 1;
      break;
    case 4:
      thres = 2;
      break;
    case 6:
      thres = 3;
      break;
    case 8:
      thres = 4;
      break;
    case 12:
      thres = 5;
      break;
    case 16:
      thres = 6;
      break;
    case 24:
      thres = 7;
      break;
    default:
      thres = 0xFF;
  }
  if (thres == 0xFF)
  {
    Serial.println(F("Invalid threshold"));
    return;
  }
  writeEEPROMTimeout(0x18, count, timeScale, thres);
}
void setDischargeShortCircuit(uint8_t threshold, uint16_t count, uint8_t timeScale)
{
  //Threshold 000 is 16mV, each step ={16,24,32,48,64,96,128,256}
  //timescale = {us,ms,s,min}
  //default is 128mV,200uS
  uint8_t thres = 0xFF;
  switch (threshold)
  {
    case 16:
      thres = 0;
      break;
    case 24:
      thres = 1;
      break;
    case 32:
      thres = 2;
      break;
    case 48:
      thres = 3;
      break;
    case 64:
      thres = 4;
      break;
    case 96:
      thres = 5;
      break;
    case 128:
      thres = 6;
      break;
    case 256:
      thres = 7;
      break;
    default:
      thres = 0xFF;
  }
  if (thres == 0xFF)
  {
    Serial.println(F("Invalid threshold"));
    return;
  }
  writeEEPROMTimeout(0x1A, count, timeScale, thres);
}

//Cell balancing
void setCellBalanceMin(uint16_t mV)
{
  writeEEPROMVoltage(0x1C, mV, 0x00);
}
void setCellBalanceMax(uint16_t mV)
{
  writeEEPROMVoltage(0x1E, mV, 0x00);
}
void setCellBalanceDifference(uint16_t mV)
{
  //If the cells are closer than this the balancing stops
  //defaults to 20mV
  writeEEPROMVoltage(0x20, mV, 0x00);
}

void setCellBalanceFaultLevel(uint16_t mV)
{
  //If the difference is bigger than this its a fault and system gives up
  //default 500mV
  writeEEPROMVoltage(0x22, mV, 0x00);
}
void setCellBalanceOnOffTime(uint16_t onTime, uint8_t onTimeScale, uint16_t offTime, uint8_t offTimeScale)
{
  //Sets on / off time for balancing cycle
  writeEEPROMTimeout(0x24, onTime, onTimeScale, 0);
  writeEEPROMTimeout(0x26, offTime, offTimeScale, 0);

}

void setCellSleepLevel(uint16_t mV)
{
  //Set the voltage at which point the device goes into sleep forcefully
  //default 2.0v
  writeEEPROMVoltage(0x44, mV, 0x00);
}
void setCellCountSleepMode(uint8_t cellCount, uint8_t idleModeTimeout, uint8_t sleepModeTimeout)
{
  //cellCount needs to be turned into the input bitmask
  uint8_t cellMask = 0b10000011;
  if (cellCount == 4)
    cellMask = 0b11000011;
  if (cellCount == 5)
    cellMask = 0b11000111;
  if (cellCount == 6)
    cellMask = 0b11100111;
  if (cellCount == 7)
    cellMask = 0b11101111;
  if (cellCount == 8)
    cellMask = 0b01111111;
  idleModeTimeout = idleModeTimeout & 0x0F;
  sleepModeTimeout = sleepModeTimeout & 0xF0;
  Serial.print("Setting Cell Count to : ");
  Serial.println(cellMask, BIN);
  Serial.print("Setting IDLE/Doze Time to : ");
  Serial.println(idleModeTimeout);
  Serial.print("Setting Sleep Time to : ");
  Serial.println(sleepModeTimeout);
  uint16_t output = cellMask << 8;
  output |= idleModeTimeout;
  output |= sleepModeTimeout;
  writeEEPROMWord(0x48, output);
}
void setOVThres(uint16_t mV, uint8_t ChargeDetectPulseWidth)
{
  writeEEPROMVoltage(0x00, mV, ChargeDetectPulseWidth);
}
void setUVThres(uint16_t mV, uint8_t LoadDetectPulseWidth)
{
  writeEEPROMVoltage(0x04, mV, LoadDetectPulseWidth);
}
void setOVRecovery(uint16_t mV)
{
  writeEEPROMVoltage(0x02, mV, 0x00);
}
void setUVRecovery(uint16_t mV)
{
  writeEEPROMVoltage(0x06, mV, 0x00);
}

void setOVLockout(uint16_t mV)
{
  writeEEPROMVoltage(0x08, mV, 0x00);
}
void setUVLockout(uint16_t mV)
{
  writeEEPROMVoltage(0x0A, mV, 0x00);
}
void setEOCThreshold(uint16_t mV)
{
  writeEEPROMVoltage(0x0C, mV, 0x00);
}
void setLVCThreshold(uint16_t mV)
{
  writeEEPROMVoltage(0x0E, mV, 0x00);
}
//Feature Controls
void setFeature1(bool CellFActivatesPSD, bool XT2Mode, bool TGain, bool PreChargeFETEnabled, bool disableOpenWireScan, bool OpenWireSetsPSD)
{
  uint8_t output = 0;
  output |= CellFActivatesPSD << 7;
  output |= XT2Mode << 5;
  output |= TGain << 4;
  output |= PreChargeFETEnabled << 2;
  output |= disableOpenWireScan << 1;
  output |= OpenWireSetsPSD;

  writeEEPROM(0x4A, output);
  delay(1);
  Serial.print("Feature 1 ");
  Serial.println(readReg(0x4A & 0xFC), HEX);
}
void setFeature2(bool CellBalanceDuringDischarge, bool CellbalanceDuringCharge,
                 bool keepDFETonDuringCharge, bool keepCFETonDuringDischarge, bool shutdownOnUVLO, bool enableBalanceAtEOC)
{
  uint8_t output = 0;
  output |= CellBalanceDuringDischarge ? 1 << 7 : 0;
  output |= CellbalanceDuringCharge ? 1 << 6 : 0;
  output |= keepDFETonDuringCharge ? 1 << 5 : 0;
  output |= keepCFETonDuringDischarge ? 1 << 4 : 0;
  output |= shutdownOnUVLO ? 1 << 3 : 0;
  output |= enableBalanceAtEOC ? 1 : 0;

  writeEEPROM(0x4B, output);
  Serial.print("Feature 2 ");
  Serial.println(readReg(0x4B & 0xFC), HEX);
}
//UserEEPROM
//Interactions with the eeprom for user use.
//Often used for serial number or other settings such as mfg date
uint8_t readUserEEPROM(uint8_t address)
{
  volatile byte r, r2;
  do {
    r = readReg(0x50 + (address & 0x0F));
    delay(1);
    r2 = readReg(0x50 + (address & 0x0F));

  } while (r != r2);
  return r;
}
bool writeUserEEPROM(uint8_t address, uint8_t value)
{
  return writeEEPROM(0x50 + (address & 0x0F), value);
}
uint16_t milliVoltsToVScaleRaw(uint16_t mV)
{
  //float retvalue =((float)mV)*((4095*3)/(1.8*8));
  float retvalue = (((float)mV) / 1000.0) * 853.125;
  return retvalue;
}
void enableEEPROMAccess()
{
  //Set the bit to change to read/write EEPROM
  writeReg(0x89, 0x01);
}
void disableEEPROMAccess()
{
  //Set the bit to change to read/write EEPROM
  writeReg(0x89, 0x00);
}
void writeEEPROMTimeout(uint8_t add, uint16_t timeout, uint8_t timeScale, uint8_t headerFourBits)
{
  uint16_t outputValue = 0;
  outputValue  = headerFourBits << 12;
  outputValue |= (timeout & 0x3FF);
  outputValue |= ((timeScale & 0x03) << 10);
  writeEEPROMWord(add, outputValue);
}
void writeEEPROMVoltage(uint8_t add, uint16_t mV, uint8_t headerFourBits)
{
  uint16_t outputValue = 0;
  outputValue  = headerFourBits << 12;
  uint16_t calcValue = milliVoltsToVScaleRaw(mV);
  if (calcValue > 0x0FFF)
  {
    Serial.println(F("Over Range"));
    return;
  }
  //else we are in range
  outputValue |= (calcValue & 0x0FFF);
  //Write out LSB in lowest address
  float reading = (uint16_t)(outputValue & 0x0FFF);

  reading *= (1.8 * 8);
  reading /= (4.095 * 3);

  Serial.print(F("Setting Voltage To : "));
  Serial.print(reading);
  Serial.println(F(" mV"));
  writeEEPROMWord(add, outputValue);
}

uint8_t readReg(uint8_t reg)
{
  Wire.beginTransmission(0x28);
  Wire.write(reg);
  Wire.endTransmission(false);
  Wire.requestFrom(0x28, 1);
  //while (!Wire.available());
  byte slaveByte2 = Wire.read();
  //Wire.endTransmission();
  return slaveByte2;
}
bool writeEEPROMWord(uint8_t reg, uint16_t value)
{
  if ((reg > 0x58 && reg < 0x7F) || reg > 0xAB)
    return false;
  enableEEPROMAccess();
  //^These are reserved areas for factory cal etc
  uint8_t buffer[4];//We need to write in pages
  uint8_t base = reg & 0xFC;
  buffer[0] = readReg(base);
  delay(1);//delay to allow EEPROM refresh
  Wire.beginTransmission(0x28);
  Wire.write(base);
  Wire.endTransmission(false);
  Wire.requestFrom(0x28, 4);
  for (byte i = 0; i < 4; i++) {
    while (!Wire.available());
    buffer[i] = Wire.read();
  }
  Wire.endTransmission();
  //We have read in the buffer

  //Update the buffer
  buffer[reg & 0x03] = value & 0xFF;
  buffer[(reg & 0x03) + 1] = value >> 8;


  Wire.beginTransmission(0x28);
  Wire.write(base);
  Wire.write(buffer[0]);
  Wire.endTransmission();
  delay(60);//pause for EEPROM write

  //^Special case for first byte causing EEPROM reload
  for (uint8_t i = 0; i < 4; i++)
  {
    Wire.beginTransmission(0x28);
    Wire.write(base + i);
    Wire.write(buffer[i]);
    Wire.endTransmission();
    delay(35);//pause for EEPROM write
  }
  delay(50);
  disableEEPROMAccess();

  return value == readReg(reg);
  //return true if the value was changed sucsessfully
}
bool writeEEPROM(uint8_t reg, uint8_t value)
{
  if ((reg > 0x58 && reg < 0x7F) || reg > 0xAB)
    return false;
  enableEEPROMAccess();
  //^These are reserved areas for factory cal etc
  uint8_t buffer[4];//We need to write in pages
  uint8_t base = reg & 0xFC;
  buffer[0] = readReg(base);
  delay(1);//delay to allow EEPROM refresh
  Wire.beginTransmission(0x28);
  Wire.write(base);
  Wire.endTransmission(false);
  Wire.requestFrom(0x28, 4);
  for (byte i = 0; i < 4; i++) {
    while (!Wire.available());
    buffer[i] = Wire.read();
  }
  Wire.endTransmission();
  //We have read in the buffer
  //Update the buffer
  buffer[reg & 0x03] = value;

  Wire.beginTransmission(0x28);
  Wire.write(base );
  Wire.write(buffer[0]);
  Wire.endTransmission();
  delay(50);//pause for EEPROM write

  //^Special case for first byte causing EEPROM reload
  for (uint8_t i = 0; i < 4; i++)
  {
    Wire.beginTransmission(0x28);
    Wire.write(base + i);
    Wire.write(buffer[i]);
    Wire.endTransmission();
    delay(35);//pause for EEPROM write
  }
  delay(50);
  disableEEPROMAccess();

  return value == readReg(reg);
  //return true if the value was changed sucsessfully
}
void writeReg(uint8_t reg, uint8_t value)
{
  if ((reg > 0x58 && reg < 0x7F) || reg > 0xAB)
    return false;
  Wire.beginTransmission(0x28);
  Wire.write(reg);
  Wire.write(value);
  Wire.endTransmission();
}

uint16_t readCurrent()
{
  uint8_t r2 = readReg(0x8E);
  uint8_t r1 = readReg(0x8F);
  float reading = (((uint16_t)(r2 << 8 | r1)) & 0xFFFF);
  reading *= (1.8);
  reading /= (4095 * 2.89);
  Serial.println(reading);

  return reading;
}
/// Readings
uint16_t OVThreshold()
{
  return readRegVScale(0x00);
}
uint16_t OVRecovery()
{
  return readRegVScale(0x02);
}
uint16_t UVThreshold()
{
  return readRegVScale(0x04);
}
uint16_t UVRecovery()
{
  return readRegVScale(0x06);
}

void printStatus()
{
  byte stat = readReg(0x80);//get status 1
  if (stat & 0x80)
    Serial.println(F("Charge disabled as its too cold"));
  if (stat & 0x40)
    Serial.println(F("Charge disabled as its too hot"));
  if (stat & 0x20)
    Serial.println(F("Discharge disabled as its too cold"));
  if (stat & 0x10)
    Serial.println(F("Discharge disabled as its too hot"));
  if (stat & 0x08)
    Serial.println(F("UVLO"));
  if (stat & 0x04)
    Serial.println(F("Pack Shutdown - Under Voltage"));
  if (stat & 0x02)
    Serial.println(F("OVLO"));
  if (stat & 0x01)
    Serial.println(F("Pack Shutdown - Over Voltage"));
  //Register 2 - Status
  stat = readReg(0x81);//get status 2
  if (stat & 0x80)
    Serial.println(F("Battery Fully charged"));
  if (stat & 0x20)
    Serial.println(F("Open Circuit on a Balance Lead!"));
  if (stat & 0x10)
    Serial.println(F("Cell failed!!! Battery needs replacement"));
  if (stat & 0x08)
    Serial.println(F("Short circuit tripped. Remove load to reset"));
  if (stat & 0x04)
    Serial.println(F("Overcurrent on dishcarge. Remove load to reset"));
  if (stat & 0x02)
    Serial.println(F("Overcurrent on charge. Remove charger to reset"));
  if (stat & 0x01)
    Serial.println(F("Outputs off. Battery too hot"));
  //Status 3
  stat = readReg(0x82);//get status 2
  if (stat & 0x80)
    Serial.println(F("Low Voltage Pre Charge on"));
  //if (stat & 0x40)
  //  Serial.println(F("Internal Scan is running"));
  if (stat & 0x20)
    Serial.println(F("ECC failed to correct an error in EEPROM"));
  if (stat & 0x10)
    Serial.println(F("ECC used to fix error in EEPROM"));
  if (stat & 0x08)
    Serial.println(F("Current: Discharging"));
  if (stat & 0x04)
    Serial.println(F("Current: Charging"));
  if (stat & 0x02)
    Serial.println(F("Charger Connected"));
  if (stat & 0x01)
    Serial.println(F("Load Connected"));

  //Status 4
  stat = readReg(0x83);//get status 2

  if (stat & 0x40)
    Serial.println(F("Mode: "));
  if (stat & 0x20)
    Serial.println(F("Mode: Doze"));
  if (stat & 0x10)
    Serial.println(F("Mode: Idle"));
  if (stat & 0x08)
    Serial.println(F("Cell Balance wants to run. But cells not charged enough"));
  if (stat & 0x04)
    Serial.println(F("Cell Balance wants to run. But cells charged more than the upper limit"));
  if (stat & 0x02)
    Serial.println(F("Cell Balance wants to run. But cells are too cold"));
  if (stat & 0x01)
    Serial.println(F("Cell Balance wants to run. But cells are too hot"));
  //cell bal status
  stat = readReg(0x84);
  for (byte i = 0; i < 8; i++)
    if (stat & (0x01 << i)) {
      Serial.print("Balancing Cell : ");
      Serial.println(i + 1);
    }
}
uint16_t minCellV()
{
  return readRegVScale(0x8A);
}
uint16_t maxCellV()
{
  return readRegVScale(0x8C);
}
uint16_t readPackV()
{

  uint16_t r1 = readReg(0xA6);
  uint16_t r2 = readReg(0xA6 + 1);
  float reading = (uint16_t)(r2 << 8 | r1);

  reading *= (1.8 * 32);
  reading /= (4.095 );

  return reading;
}
uint16_t readCellV(uint8_t cellNo)
{
  return readRegVScale(0x90 + (2 * cellNo));
}
uint16_t readRegVScale(uint8_t reg)
{
  uint16_t r1 = readReg(reg);
  uint16_t r2 = (readReg(reg + 1)) & 0x0F;
  float reading = (uint16_t)(r2 << 8 | r1);

  reading *= (1.8 * 8);
  reading /= (4.095 * 3);

  return reading;
}

