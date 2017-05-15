#ifndef __CONFIG_H
#define __CONFIG_H

#include <stdlib.h>
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

	//	
	//	Operate instruction
	//	- Instruction structure defined within readme
	//
	//	@param op: operation to be executed by the CPU.
	//	
	//	@return bool: true on error
	//	
	bool operate(instruct_t op);
	
	//	
	//	Aquire latest instruction error
	//	- 
	//	
	//	@return instruct_t: error code
	//
	inline instruct_t getError() { return m_opErr; }

private:

	//						 4-bit		4-bit
	//	8-bit operation: [(operation)(arguments)] 
																			//	4-bits
	inline instruct_t get_op(instruct_t op) { return op & ~(RAM_OP); }		//	get the operation of the instruction:	[0000xxxx]
	inline instruct_t get_arg(instruct_t op) { return op & ~(RAM_ARG); }	//	get the arguments of the instruction:	[xxxx0000]

																						//	2-bits
	inline instruct_t get_arg1(instruct_t op) { return get_arg(op) & ~(RAM_ARG1); }		//	get the first fraction:		[00xx0000]
	inline instruct_t get_arg2(instruct_t op) { return get_arg(op) & ~(RAM_ARG2); }		//	get the second fraction:	[xx000000]


	/* CPU Registers */

	register_t m_Register_a = NULL;	///>	A
	register_t m_Register_b = NULL;	///>	B
	register_t m_Register_c = NULL;	///>	C
	register_t m_Register_d = NULL;	///>	D
	
	/* Dedicated registers */

	register_t m_Register_sp = NULL; ///>	Stack
	register_t m_Register_bp = NULL; ///>	Base


	char m_opErr;	// Error indicator
	
	instruct_t *m_pNextInstruction;		// Instruction Cycle
	flag_t *m_paCPUFlags;				// CPU flags

	RAM *m_pRAM;				// Memory Unit
	unsigned int m_RAM_sz;		// Memory Size
};

#endif // !__CONFIG_H