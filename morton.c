

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "hilbert.h"
#include "morton.h"



static uint32_t mortonLUT[3][256];


uint32_t preshift(uint32_t val, int bits) {
	int i;
	uint32_t o;
	
	o = 0;
	for(i = 0; i < 8; i++) {
		o |= (val & (1U << i)) << (i + bits);
	}
	
	return o;
}


void initMortonLUT() {
	int i;
	
	for(i = 0; i < 256; i++) {
		mortonLUT[0][i] = preshift(i, 0);
		mortonLUT[1][i] = preshift(i, 1);
		mortonLUT[2][i] = preshift(i, 2);
	}
}

uint64_t mortonIndex(int x, int y, int z) {
	
	uint64_t o;
	
	
	o  = mortonLUT[0][(x >> 16) & 0xFF] | mortonLUT[1][(y >> 16) & 0xFF] | mortonLUT[2][(z >> 16) & 0xFF]; 
	o <<= 24;
	o |= mortonLUT[0][(x >> 8) & 0xFF] | mortonLUT[1][(y >> 8) & 0xFF] | mortonLUT[2][(z >> 8) & 0xFF]; 
	o <<= 24;
	o |= mortonLUT[0][x & 0xFF] | mortonLUT[1][y & 0xFF] | mortonLUT[2][z & 0xFF]; 
	
	return o;
}




