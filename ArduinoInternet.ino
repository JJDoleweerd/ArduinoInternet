int numLoops = 0;

void setup()
{
	Serial.begin(9600);
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
	numLoops+=1;
	// Serial.write(45); // send a byte with the value 45
	int bytesSent = Serial.write("hi"); // send the string "hello" and return the length of the string.
	String numLoopsStr = String(numLoops);
	Serial.print(numLoopsStr + "\n"); // send the string "hello" and return the length of the string.
	digitalWrite(LED_BUILTIN, HIGH);
	delay(500);
	digitalWrite(LED_BUILTIN, LOW);
	delay(500);
}