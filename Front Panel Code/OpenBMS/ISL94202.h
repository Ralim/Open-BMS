/*
 * ISL94202.h
 *
 *  Created on: 12 June ,2017
 *      Author: Ben V. Brown
 *
 *      Driver for the ISL94202 BMS IC
 *      Uses i2c.* for handling the I2C communications
 *
 *      Provides access to both live readings and also the ability to change settings on the unit
 *
 */

#ifndef ISL94202_H_
#define ISL94202_H_
#include <stdbool.h>
#include "hardware.h"
#include "i2c.h"
#define ISLADDRESS 0x28
//Update the cell voltage and current readings from the unit
void ISL94202_updateReadings();
//Updates the buffer of the status registers
void ISL94202_updateStatus();

//returns the voltage measured at that cells input in millivolts
uint16_t ISL94202_getCellVoltageMV(uint8_t index);

//Returns the pack current in milliamps
uint16_t ISL94202_getPackCurrentMA();

//Returns a bitmask of the currently balancing cells
uint8_t ISL94202_getBalancingCells();

/////////////////////////////////// SETTINGS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

//Thresholds and releases
void ISL94202_setOVLockout(uint16_t mV);
void ISL94202_setOVThres(uint16_t mV);
void ISL94202_setOVRecovery(uint16_t mV);
void ISL94202_setUVThres(uint16_t mV);
void ISL94202_setUVRecovery(uint16_t mV);
void ISL94202_setUVLockout(uint16_t mV);
void ISL94202_setEOCThreshold(uint16_t mV);

//Current Settings
void ISL94202_setDischargeOC(uint8_t mV, uint16_t time, uint8_t timeBase);
void ISL94202_setChargeOC(uint8_t mV, uint16_t time, uint8_t timeBase);
void ISL94202_setShortCircuit(uint8_t mV, uint16_t time, uint8_t timeBase);

//Cell Balancing
void ISL94202_setCellBalanceTimes(uint8_t onTime, uint8_t offTime,
                                  uint8_t timeBase);
void ISL94202_setCellCountSleepTimes(uint8_t cellCount, uint8_t idleSleep,
                            uint8_t deepsleep);
void ISL94202_setCellBalanceDifference(uint16_t mV);
void ISL94202_setCellBalanceStartV(uint16_t mV);
void ISL94202_setCellBalanceStopV(uint16_t mV);
void ISL94202_setCellBalanceFaultLevel(uint16_t mV);

//Chip Features Control
void ISL94202_setFeature1(bool CellFActivatesPSD, bool XT2Mode, bool TGain,
                 bool PreChargeFETEnabled, bool disableOpenWireScan,
                 bool OpenWireSetsPSD);

void ISL94202_setFeature2(bool CellBalanceDuringDischarge,
                          bool CellbalanceDuringCharge,
                 bool keepDFETonDuringCharge, bool keepCFETonDuringDischarge,
                 bool shutdownOnUVLO, bool enableBalanceAtEOC);

//////////////////////// EEPROM \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void ISL94202_writeUserEEPROM(uint8_t address, uint8_t value);
uint8_t ISL94202_readUserEEPROM(uint8_t address);

//////////////////////// I2C Support  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void ISL94202_writeEEPROM(uint8_t reg, uint8_t value);
void ISL94202_writeEEPROMWord(uint8_t reg, uint16_t value);
void ISL94202_writeEEPROMVoltage(uint8_t add, uint16_t mV,
                                 uint8_t headerFourBits);
void ISL94202_writeEEPROMTimeout(uint8_t add, uint16_t timeout,
                                 uint8_t timeScale,
                        uint8_t headerFourBits);
#endif /* ISL94202_H_ */
