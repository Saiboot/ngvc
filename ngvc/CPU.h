#include "registers.h"
#include <iostream>
class CPU
{
public:
	CPU(RAM* RAMptr, unsigned int RAM_sz);

	void Tick(instruct_t instruct);
	void ClearFlags();

	inline instruct_t getInstructionID() { return m_InstructAddr; }
	
	//	
	//	Check if there has been a recent flag swap
	//	-
	//	
	//	@return bool: true or false
	//	
	bool recentFlagSwap();

	//	
	//	Aquire latest instruction error
	//	- 
	//	
	//	@return int: error code
	//
	inline int getError() { return (int)m_pRegPlex->getError(); }

	//	
	//	Instruction Error Flag
	//	
	bool m_InstructErr;

	~CPU();
private:
	RegisterMultiplexer *m_pRegPlex;
	instruct_t m_InstructAddr;
	register_t m_FlagCollection;

	RAM* m_pRAM;
};

