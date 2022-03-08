#include <assert.h>
#include <math.h>
#include <WString.h>
using namespace std;

struct Nibble { 
	unsigned char first:4;
	unsigned char second:4;
} typedef Nibble;

struct Chungus {
	int length;
	Nibble* bytes;
};

Chungus* createChungus (unsigned int size);
void setChungusDigit(Chungus* chonker, unsigned short int digit, int index);
unsigned short int getChungusDigit(Chungus* chonker, int index);
Chungus *MultiplyChungi(Chungus *chonker1, struct Chungus *chonker2);