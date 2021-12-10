/*
 * RRScanner.cpp
 *
 * Created: 09-12-2021 09:35:00
 *  Author: JensN
 */ 
#include "RFScanner.h"

//Scanner
extern MFRC522 mfrc522;
extern MFRC522::MIFARE_Key key;


String CardReader()// Card reader
{
	
	// Look for new cards, and select one if present
	if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
		return "";
	}
	
	// Dump UID
	String result = "";
	for (byte i = 0; i < mfrc522.uid.size; i++) {
		result += String(mfrc522.uid.uidByte[i], HEX);
	}
	return result;
}
