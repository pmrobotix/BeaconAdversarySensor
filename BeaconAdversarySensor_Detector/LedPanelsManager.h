#ifndef _LedPanelsManager_H_
#define _LedPanelsManager_H_


// I2C Soft, see http://playground.arduino.cc/Main/SoftwareI2CLibrary
// put this before #include <SoftI2CMaster.h>
#define SDA_PORT PORTB
#define SDA_PIN 7 // pin 7 of port B = digital pin 13 of Arduino Mega 2560
#define SCL_PORT PORTB
#define SCL_PIN 5 // pin 5 of port B = digital pin 11 of Arduino Mega 2560
#define I2C_TIMEOUT	1000 // ms
#define I2C_NOINTERRUPT 0
#define I2C_SLOWMODE 1
#define FAC 1
#define I2C_CPUFREQ (F_CPU/FAC)


#include "BeaconDetectionModel.h"
#include <Arduino.h>


class LedPanelsManager {
public:
	LedPanelsManager(unsigned long timeBetweenSendToLedPanelsMs);
	void sendDetectedBeaconsIfRequired(BeaconDetectionModel beaconDetectionModel);

private:
	void write(const uint8_t *data, size_t quantity);
	bool isTimeToSend();

	unsigned long timeBetweenSendToLedPanelsMs;
	unsigned long lastSentToLedPanelsMs;
};


#endif //_LedPanelsManager_H_
