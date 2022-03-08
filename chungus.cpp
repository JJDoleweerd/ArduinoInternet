#include "chungus.h"
#include <WString.h>
#include <assert.h>
#include <math.h>
using namespace std;

Chungus* createChungus (unsigned int size) {
	assert(size>0);
	Chungus* chonker = new Chungus;
	chonker->length = size;
	chonker->bytes = new Nibble[size/2];
	memset(chonker->bytes, 0, size/2);
	return chonker;
}

void setChungusDigit(Chungus* chonker, unsigned short int digit, int index){
	assert(index<chonker->length);
	assert(digit<10);
	if (index%2==0) chonker->bytes[index/2].first = (unsigned char)digit;
	else chonker->bytes[index/2].second = (unsigned char)digit;
}	
unsigned short int getChungusDigit(Chungus* chonker, int index) {
	assert(index<chonker->length);
	if (index%2==0) return chonker->bytes[index/2].first;
	else return chonker->bytes[index/2].second;
}
Chungus *MultiplyBigChungi(Chungus *chonker1, struct Chungus *chonker2){
	int maxSize = chonker1->length + chonker2->length;
	Chungus* newChonker = createChungus(maxSize);
	short unsigned int carry = 0;
	short unsigned int digit = 0;
	for (int i=0; i<newChonker->length; i++){
		digit = 0;
		int d1 = i; //Indexes
		int d2 = 0;
		if (d1>fmax(chonker1->length, chonker2->length)-1){
			d1 = fmax(chonker1->length, chonker2->length);
			d2 = i - d1;
		}
		while (d1>=d2) { //squeeze values for multiplication
			bool valueUsed = false;
			if (chonker1->length>d1 && chonker2->length>d2) { //Add multiplied values
				digit += getChungusDigit(chonker1, chonker1->length-d1-1) * getChungusDigit(chonker2, chonker2->length-d2-1);
				valueUsed = true;
			}
			if (chonker1->length>d2 && chonker2->length>d1 && (!valueUsed || d1!=d2)) {
				digit += getChungusDigit(chonker1, chonker1->length-d2-1) * getChungusDigit(chonker2, chonker2->length-d1-1);
			}
			d1--;
			d2++;
		}
		digit += carry;
		setChungusDigit(newChonker, digit%10, newChonker->length-1-i);
		carry = digit/10;
	}
	return newChonker;
}