#pragma once

struct LargeInt {
	unsigned char * LInt;
	unsigned int size;
};

struct LargeInt * NEW_LargeInt_from_str(const char * string, unsigned int size);
struct LargeInt * add(struct LargeInt * lia, struct LargeInt * lib);
char * LargeIntToString_Hex(struct LargeInt * lint);
char * LargeIntToString_Dec(struct LargeInt * lint);
struct LargeInt * divideByMultAndBitshift(struct LargeInt * li, struct LargeInt* oT);
struct LargeInt * bitshiftup(struct LargeInt * li, int amount);
struct LargeInt * mult(struct LargeInt * lia, struct LargeInt * lib);
void destructor(struct LargeInt * li);
