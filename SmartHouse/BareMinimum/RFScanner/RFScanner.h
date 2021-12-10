/*
 * RFScanner.h
 *
 * Created: 09-12-2021 09:35:09
 *  Author: JensN
 */ 


#ifndef RFSCANNER_H_
#define RFSCANNER_H_

#include <MFRC522.h>				// Radio frequency scanner library.

//Scanner
#define RST_PIN 5
#define SS_PIN 46
#define MFRCKEY {0x30, 0x55, 0x71, 0xA5}

String CardReader();										// RF card reader

#endif /* RFSCANNER_H_ */