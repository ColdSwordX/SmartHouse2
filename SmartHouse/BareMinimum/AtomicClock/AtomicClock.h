
#ifndef ATOMICCLOCK_H_
#define ATOMICCLOCK_H_

#include <DS3231.h>					// Atomic Clock frequency.

DateTime ReadClock();				// Read the time from the Clock
String GetTimeString(DateTime dt);	// Retrieves the time from the atomic clock.
String GetDataString(DateTime dt);	// Retrieves the date from the atomic clock.


#endif /* ATOMICCLOCK_H_ */