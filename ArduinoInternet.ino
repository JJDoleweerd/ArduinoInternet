#include "requests.h"
#include "rsa.h"
#include "chungus.h"
int numLoops = 0;

void setup()
{
	Serial.begin(9600);
	pinMode(LED_BUILTIN, OUTPUT);
	// randomSeed(analogRead(0));
}

void loop()
{
	// Serial.write(45); // send a byte with the value 45
	// int bytesSent = Serial.write("hi"); // send the string "hello" and return the length of the string.
	// String numLoopsStr = createRequest("hi", "there");
		// String(numLoops);
	// String message = createRequest("hi", "there");
	// Serial.print(message);
	// Serial.print(generateLargePrime());
	// Serial.print("\n");
	// Serial.print(numLoopsStr + "\n"); // send the string "hello" and return the length of the string.
	digitalWrite(LED_BUILTIN, HIGH);
	delay(100);
	digitalWrite(LED_BUILTIN, LOW);
	delay(100);
	numLoops+=1;
}