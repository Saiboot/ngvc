#ifndef __COMMON_H
#define __COMMON_H

#include "kernel.h"
#include "Assembler utilities\atribuf.h"

// Kernel */
//
#define kmain main

/* CPU operations (op-codes) */

//	
//	TODO: Generalize LOAD & STORE => MOV
//	8 + 2 opcodes => 1 opcode
//	

// RAM => register

	// #define CPU_LOAD_A 1	///	 ( RAM addr )
	// #define CPU_LOAD_B 2	///	 ( RAM addr )
	// #define CPU_LOAD_C 3	///	 ( RAM addr )
	// #define CPU_LOAD_D 4	///	 ( RAM addr )

	// Register => RAM

	// #define CPU_STORE_A	5	///	 ( RAM addr )
	// #define CPU_STORE_B	6	///	 ( RAM addr )	
	// #define CPU_STORE_C	7	///	 ( RAM addr )	
	// #define CPU_STORE_D	8	///	 ( RAM addr )	

#define CPU_MOV	1		///	 ( dest, source )

// Arithmetics
#define CPU_ADD	9		/// Add two registers:         ( register x, register y )
#define CPU_SUB	10		/// Subtract  two registers:   ( register x, register y )
#define CPU_DIV			/// Divide two registers:      ( register x, register y )
#define CPU_MUL			/// Multiply  two registers:   ( register x, register y )

#define CPU_CMP 11		///	Compare two register's values	 ( register x, register y )
						/// ==> Update CPU - Flag registers

#define CPU_JMP	12		/// Jump to RAM address [unconditionally]:			( RAM addr )
#define CPU_JNE	13		/// CPU: Zero Flag [0] => Jump to RAM address:		( RAM addr )
#define CPU_JE 14		///	CPU: Zero Flag [1] => Jump to RAM address:		( RAM addr )
						
// Interrupts
#define CPU_HALT  15		/// Program done, halt computer

// NOTE: VM Interface: OPENGL
//
// Graphics 
#define VideoMemory 16	/// Video memory address

// Register 2-bit IDs
#define CPU_Register_EAX 0	///	Binary ID: [00]
#define CPU_Register_EBX 1	///	Binary ID: [01]
#define CPU_Register_ECX 2	///	Binary ID: [10]
#define CPU_Register_EDX 3	///	Binary ID: [11]

// CPU flag collection offsets
#define CPU_ZF BIT_1			/// Zero 
#define CPU_OF BIT_2			/// Overflow 
#define CPU_SF BIT_3			/// Sign 
#define CPU_CF BIT_4			/// Carry

#define CPU_FLAGS			CPU_ZF | CPU_OF | CPU_SF | CPU_CF		/// Flag buffer prototype

#define FLAG_ON 1
#define FLAG_OFF 0

// System architecture */
#if defined(__NGVC8__)		// 8-bit
/* Instruction Masks */

						///	0 = cleared bit, x = untouched bit.
#define RAM_OP 240		///	[0000xxxx]
#define RAM_ARG 15		///	[xxxx0000]

	// Argument segments
	#define RAM_ARG1 12		///	[00xx]
	#define RAM_ARG2 3		///	[xx00]

typedef unsigned __int8 register_t;
typedef unsigned __int8 instruct_t;
#elif defined (__NGVC32__)	// 32-bit

typedef unsigned __int32 instruct_t;

// Instruction Masks
#define INSTRUCT_OPCODE		BIT_27 | BIT_28 | BIT_29 | BIT_30 | BIT_31 | BIT_32		// 6-bit
#define INSTRUCT_REG_1		BIT_22 | BIT_23 | BIT_24 | BIT_25 | BIT_26				// 5-bit
#define INSTRUCT_REG_2		BIT_17 | BIT_18 | BIT_19 | BIT_20 | BIT_21				// 5-bit
#define INSTRUCT_REG_3		BIT_12 | BIT_13 | BIT_14 | BIT_15 | BIT_16				// 5-bit
#define INSTRUCT_SHIFT		BIT_7  | BIT_8  | BIT_9  | BIT_10 | BIT_11				// 5-bit
#define INSTRUCT_FUNC		BIT_1  | BIT_2  | BIT_3  | BIT_4  | BIT_5  | BIT_6		// 6-bit

typedef unsigned __int32 register_t;

// Register segments
#define REG_X 0xFFFF	/// 16 bit 
#define REG_H 0xFF00	/// 8 bit -High
#define REG_L 0xFF		/// 8 bit -Low

#endif

//
//	TODO: Place this somewhere close to the assembler
//

typedef struct directive_t {
	char name[UCHAR_MAX];
	__int8 suffix;
} directive_t;

//
//	TODO: Place this somewhere close to the assembler
//	- Assembler utilities/config.h ?
//

const directive_t Directives[4][UCHAR_MAX] = {
	{ ".data",   BIT_1},	
	{ ".text",   BIT_2},	
	{ ".bss",    BIT_3},	
	{ ".global", BIT_4}		
};


typedef unsigned char uint8_t;

// RAM */
// - Random Access Memory element structure
// 
typedef struct RAM {
	instruct_t instruction;

} RAM;

// List */
// - Memory Stack element structure
// 
typedef struct List {
	__int32 data;
	List* next;

} List;

// Label */
// - 
// 
typedef struct label {
	char *id;                   //					( 1 byte  )
	unsigned short address;     //					( 2 bytes )

	label(char* s, unsigned short addr) {
		id = s;
		address = addr;
	}

} tag;

#endif // !__COMMON_H
