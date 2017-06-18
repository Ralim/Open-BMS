/*
 * main.h
 *
 *  Created on: 11Jun.,2017
 *      Author: Ben V. Brown
 */

#ifndef MAIN_H_
#define MAIN_H_
#include <msp430.h>
#include "hardware.h"
#include "setup.h"
#include "i2c.h"
#include "ISL94202.h"
#ifndef NDEBUG
// If debugger is attached and software breakpoints are enabled, DEBUG_BREAK will pause execution
#define DEBUG_BREAK _op_code(0x4343)
#else
// Strip out DEBUG_BREAKs in final/release builds
#define DEBUG_BREAK
#endif


#endif /* MAIN_H_ */
