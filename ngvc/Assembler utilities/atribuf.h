#ifndef _NGLIB_ATRIBUF
#define _NGLIB_ATRIBUF

//************************************************//
//	NGLIB                                         //
//	Copyright (c) 2017 Tobias Ljung & Samuel Jos  //
//                                                //
//************************************************//

namespace nglib_utilities {

/* BYTE 1 - [8] */
#define BIT_1 0x1
#define BIT_2 0x2
#define BIT_3 0x4
#define BIT_4 0x8
#define BIT_5 0x10
#define BIT_6 0x20
#define BIT_7 0x40
#define BIT_8 0x80

/* BYTE 2 - [16] */
#define BIT_9  0x100
#define BIT_10 0x200
#define BIT_11 0x400
#define BIT_12 0x800
#define BIT_13 0x1000
#define BIT_14 0x2000
#define BIT_15 0x4000
#define BIT_16 0x8000

/* BYTE 3 - [24] */
#define BIT_17 0x10000
#define BIT_18 0x20000
#define BIT_19 0x40000
#define BIT_20 0x80000
#define BIT_21 0x100000
#define BIT_22 0x200000
#define BIT_23 0x400000
#define BIT_24 0x800000

/* BYTE 4 - [32] */
#define BIT_25 0x1000000
#define BIT_26 0x2000000
#define BIT_27 0x3000000
#define BIT_28 0x4000000
#define BIT_29 0x8000000
#define BIT_30 0x10000000
#define BIT_31 0x20000000
#define BIT_32 0x40000000


	/* Custom attributes */

	void setAttrib(unsigned int *aBuf, const unsigned int atr) {
		*aBuf |= atr;
	}

	void clearAttrib(unsigned int *aBuf, const unsigned int atr) {
		*aBuf &= ~(atr);
	}

	bool peekAttrib(unsigned int aBuf, unsigned int atr) {
		return aBuf &= atr ? true : false;
	}

	/* Buffer injection */

	void clearBit(unsigned int *aBuf, unsigned int mask) {
		*aBuf &= ~(1 << mask);
	}

	void toggleBit(unsigned int *aBuf, unsigned int mask) {
		*aBuf ^= 1 << mask;
	}

	unsigned int peekBit(unsigned int aBuf, unsigned int loc) {
		return aBuf >> loc & 1;
	}
}

#endif //!_NGLIB_ATRIBUF