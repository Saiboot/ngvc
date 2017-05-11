#ifndef __FORMAT_H
#define __FORMAT_H

/*	
 *	Alternative way of handling & constructing cpu instructions
 *	32-bit system
 */


typedef unsigned __int32 Instruction_sz;

typedef struct Instruction {
	unsigned __int32 opcode : 6;
	unsigned __int32 reg1	: 5;
	unsigned __int32 reg2	: 5;
	unsigned __int32 reg3	: 5;
	unsigned __int32 shift	: 5;
	unsigned __int32 func	: 6;
};

#define MASK_OP		0x03FFFFFF	// opcode
#define MASK_REG1	0xFC1FFFFF	// register 1
#define MASK_REG2	0xFFE0FFFF	// register 2
#define MASK_REG3	0xFFFF07FF	// register 3
#define MASK_SHIFT	0xFFFFF83F	// Shift
#define MASK_FUNC	0xFFFFFFC0	// Func

unsigned __int32 maskInstructionOperand(unsigned __int32 instruction, unsigned __int32 BIT_MASK) {
	return instruction & ~(BIT_MASK);
}

unsigned __int32 getInstructionOperand(unsigned __int32 instruction, unsigned __int8 operand) {
	return instruction >>= operand;
}


#endif // !__FORMAT_H
