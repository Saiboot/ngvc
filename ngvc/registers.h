#ifndef __CONFIG_H
#define __CONFIG_H

#include <stdlib.h>
#include "common.h"

class RegisterMultiplexer
{
public:
	RegisterMultiplexer(RAM *RAM, instruct_t *instructAddr, register_t *flags, unsigned int RAM_sz)
		:m_pRAM(nullptr),
		 m_pNextInstruction(nullptr),
		 m_pCPUFlags(flags),
		 m_RAM_sz(RAM_sz),

		m_Register_eax(NULL),
		m_Register_ebx(NULL),
		m_Register_ecx(NULL),
		m_Register_edx(NULL),

		m_Register_ebp(NULL),
		m_Register_esp(NULL),

		m_Register_rsi(NULL),
		m_Register_rdi(NULL)

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


	//									6-bit    5-bit   5-bit   5-bit   5-bit   6-bit
	//	32-bit Instruction structure: [(opcode) (_reg1) (_reg2) (_reg3) (shift) (funct)]

	// TODO: Write this complex function...

	inline unsigned int invertAttrib(unsigned int aBuf, unsigned int atr) {
		//	aBuf:	|00000000|00000000|01000000|00010110|
		//	atr:	|00000000|00000000|00000000|00010100|
		//	ret:	|11111111|11111111|11111111|11101011|
	}

	//	TODO: Add bit push back after Zero-ing non-focused bits
	//	TODO: Write getters for every Instruction operand
																															//	6-bits							   [-        32 bit       -]
	inline instruct_t get_opcode(instruct_t instruct) { return instruct & ~(invertAttrib(instruct, INSTRUCT_OPCODE)); }		//	get the opcode of the instruction: [xxxxxx00][...][...][...]

	///  opcode	->>  operands 
	///  <operation> <dest>, <source>, <source>

	// Shifts & instructs that reference only registers.
	__int8 doop_R(RAM* pRAM, uint8_t reg1, uint8_t reg2, uint8_t reg3, uint8_t shift, uint8_t func);

	// Arithmetic/Logical, Load, store, branches & immediate instructions.
	__int8 doop_I(RAM* pRAM, uint8_t reg1, uint8_t reg2, uint16_t immed);

	// Jump & call instructions.
	__int8 doop_J(RAM* pRAM, uint32_t target);

	/* Dedicated General Purpose CPU Registers */

	register_t m_Register_eax;	///>	A
	register_t m_Register_ebx;	///>	B
	register_t m_Register_ecx;	///>	C
	register_t m_Register_edx;	///>	D

	register_t m_Register_ebp;	///>	Base
	register_t m_Register_esp;	///>	Stack

	register_t m_Register_rsi;	///>	Source
	register_t m_Register_rdi;	///>	Destination

	char m_opErr;	// Error indicator
	
	instruct_t *m_pNextInstruction;		// Instruction Cycle
	register_t *m_pCPUFlags;			// CPU flags

	RAM *m_pRAM;				// Memory Unit
	unsigned int m_RAM_sz;		// Memory Size
};

#endif // !__CONFIG_H