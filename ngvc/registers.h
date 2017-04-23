#ifndef __CONFIG_H
#define __CONFIG_H

#include "common.h"

class RegisterMultiplexer
{
public:
	RegisterMultiplexer(RAM *RAM, instruct_t *instructAddr, flag_t flags[CPU_FLAGS], unsigned int RAM_sz)
		:m_pRAM(nullptr),
		 m_pNextInstruction(nullptr),
		 m_paCPUFlags(flags),
		 m_RAM_sz(RAM_sz)

		{ 
			m_pRAM = RAM;
			m_pNextInstruction = instructAddr;
		}

	void operate(RegisterMultiplexer *pReg, instruct_t op);
	
private:

	//						 4-bit		4-bit
	//	8-bit operation: [(operation)(arguments)] 
																		//	4-bits
	inline instruct_t get_op(instruct_t op) { return op & ~(OP_S1); }	//	get the operation of the instruction:	[0000xxxx]
	inline instruct_t get_arg(instruct_t op) { return op & ~(OP_S2); }	//	get the arguments of the instruction:	[xxxx0000]

																						//	2-bits
	inline instruct_t get_arg1(instruct_t op) { return get_arg(op) & ~(OP_S2_F1); }		//	get the first fraction:		[00xx0000]
	inline instruct_t get_arg2(instruct_t op) { return get_arg(op) & ~(OP_S2_F2); }		//	get the second fraction:	[xx000000]


	/* CPU Registers */

	register_t m_Register_a;	///>	A
	register_t m_Register_b;	///>	B
	register_t m_Register_c;	///>	C
	register_t m_Register_d;	///>	D
	
	char m_opErr;	// Error indicator
	
	instruct_t *m_pNextInstruction;		// Instruction Cycle
	flag_t *m_paCPUFlags;				// CPU flags

	RAM *m_pRAM;				// Memory Unit
	unsigned int m_RAM_sz;		// Memory Size
};

#endif // !__CONFIG_H