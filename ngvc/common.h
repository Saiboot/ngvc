#ifndef __COMMON_H
#define __COMMON_H

#include "kernel.h"

// Kernel */
//
#define kmain main

/* CPU operations (op-codes) */

// RAM => register
#define CPU_LOAD_A 1	///	 ( RAM addr )
#define CPU_LOAD_B 2	///	 ( RAM addr )
#define CPU_LOAD_C 3	///	 ( RAM addr )
#define CPU_LOAD_D 4	///	 ( RAM addr )

// Register => RAM
#define CPU_STORE_A	5	///	 ( RAM addr )
#define CPU_STORE_B	6	///	 ( RAM addr )	
#define CPU_STORE_C	7	///	 ( RAM addr )	
#define CPU_STORE_D	8	///	 ( RAM addr )	

// Arithmetics
#define CPU_ADD	9		/// Add two registers:	2-bit IDs:	( register x, register y )
#define CPU_SUB	10		/// Subtract two registers:			( register x, register y )

#define CPU_CMP 11		///	Compare two register's values	( register x, register y )

#define CPU_JMP	12		/// Jump to RAM address [unconditionally]:			( RAM addr )
#define CPU_JNE	13		/// CPU: Zero Flag [0] => Jump to RAM address:		( RAM addr )
#define CPU_JE 14		///	CPU: Zero Flag [1] => Jump to RAM address:		( RAM addr )

// Interrupts
#define CPU_HALT 15		/// Program done, halt computer

// Graphics 
#define VideoMemory 16	/// Video memory address

// Register 2-bit IDs
#define CPU_Register_a 0	///	Binary ID: [00]
#define CPU_Register_b 1	///	Binary ID: [01]
#define CPU_Register_c 2	///	Binary ID: [10]
#define CPU_Register_d 3	///	Binary ID: [11]

// CPU flag collection offsets
#define CPU_ZF 0		/// Zero 
#define CPU_OF 1		/// Overflow 
#define CPU_SF 2		/// Sign 
#define CPU_CF 3		/// Carry

#define CPU_FLAGS 4

#define FLAG_ON 1
#define FLAG_OFF 0

#if defined(__NGVC8__)
/* Instruction Masks */

						///	0 = cleared bit, x = untouched bit.
#define RAM_OP 240		///	[0000xxxx]
#define RAM_ARG 15		///	[xxxx0000]

	// Argument segments
	#define RAM_ARG1 12		///	[00xx]
	#define RAM_ARG2 3		///	[xx00]

typedef unsigned __int8 register_t;
typedef unsigned __int8 instruct_t;
#endif

#if defined (__NGVC16__)
/* Instruction Masks */

///	0 = cleared bit, x = untouched bit.
#define RAM_OP ...		///	[00000000][xxxxxxxx]
#define RAM_ARG ..		///	[xxxxxxxx][00000000]

	// Argument segments
	#define RAM_ARG1 ..		///	[0000xxxx]
	#define RAM_ARG2 .		///	[xxxx0000]

typedef unsigned __int16 register_t;
typedef unsigned __int16 instruct_t;
#endif

typedef bool flag_t;

typedef struct RAM {
	instruct_t instruction;

} RAM_t;

typedef struct List {
	__int32 data;
	List* next;

} List_t;

typedef struct tag {
	char *string;			//					( 1 byte )
	uint16_t address;		//					( 2 bytes )

	tag(char* s, uint16_t addr) {
		string = s;
		address = addr;
	}

} tag;
#endif // !__COMMON_H
