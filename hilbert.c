#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "hilbert.h"




Leaf* allocLeaf() {
	
	Leaf* l;
	
	l = calloc(1, sizeof(Leaf));
	
	
	return l;
}


void printLeaf(Leaf* l) {
	
	uint64_t i, j;
	
	
	for(i = 0; i < 8; i++) {
		for(j = 1; j > 0; j <<= 1) {
			//printf("[%lud] ", j);
			putchar(((l->b[i] & j) == j) ? '1' : '0');
		}
		
		printf(" %#lX", l->b[i]);
		
		fputs("\n", stdout);
	}
	
	fputs("\n", stdout);
};



void setBit(Leaf* l, int bit, int val) {
	
	uint64_t i, j, v;
	
	
	i = bit / 64;
	j = bit % 64;
	
	printf(" i: %d, j: %d \n", i,j);
	
	
	v = val & 1;
	
	// some magic from SO
	l->b[i] ^= (-v ^ l->b[i]) & (1UL << j);
}


int getBit(Leaf* l, int bit) {
	
	uint64_t i, j, v;
	
	
	i = bit / 64;
	j = bit % 64;
	
	v = 1UL << j;
	
	// some magic from SO
	return (l->b[i] & v) == v;
}







int main(int argc, char* argv[]) {
	
	
	Leaf* l;
	
	
	l = allocLeaf();
	
	setBit(l, 2, 1);
	setBit(l, 63, 1);
	setBit(l, 511, 1);
	
	printLeaf(l);
	
	printf(" lol: %d\n", getBit(l, 2));
	printf(" lol: %d\n", getBit(l, 3));
	
	
	
	
	return 0;
}



