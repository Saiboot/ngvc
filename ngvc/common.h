#ifndef __COMMON_H
#define __COMMON_H

/* CPU operations (op) */

#define kmain main
#define EMPTY 0

#define OP_S1 240
#define OP_S2 15

#define OP_S2_F1 12
#define OP_S2_F2 3

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

#define CPU_JMP	12		/// Jump to RAM address address (unconditionally):	( RAM addr )
#define CPU_JMP___	13	/// 
#define CPU_JE 14		///	CPU: Negative Flag => Jump to RAM address:		( RAM addr )

// Interrupts
#define CPU_HALT 15		/// Program done, halt computer

#define VideoMemory 16	/// Video memory address

// Register 2-bit IDs
#define CPU_Register_a 0	///	Binary ID: [00]
#define CPU_Register_b 1	///	Binary ID: [01]
#define CPU_Register_c 2	///	Binary ID: [10]
#define CPU_Register_d 3	///	Binary ID: [11]

// CPU flag collection offsets
#define CPU_ZF 0		/// Zero Flag
#define CPU_OF 1		/// Overflow Flag

#define CPU_FLAGS 2

#define FLAG_ON 1
#define FLAG_OFF 0

typedef unsigned __int8 register_t;
typedef unsigned __int8 instruct_t;
typedef bool flag_t;

typedef struct RAM {
	const __int8 op_max_sz = 15;
	instruct_t instruction;

} RAM_t;

typedef struct List {
	__int32 data;
	List* next;

} List_t;
#endif // !__COMMON_H