



typedef struct Leaf {
	uint64_t b[8];
} Leaf;


// cube
typedef struct Bitfield {
	int edgeSize; // in bits
	int allocSize; // in bytes
	int bitsPerCell;
	
	uint8_t b[0];
} Bitfield;


