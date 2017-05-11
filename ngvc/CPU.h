#include "registers.h"
#include <iostream>
class CPU
{
public:
	CPU(RAM* RAMptr, unsigned int RAM_sz);

	void Tick(instruct_t instruct);
	void ClearFlags();

	inline instruct_t getInstructionID() { return m_InstructAddr; }
	bool recentFlagSwap();

	~CPU();
private:
	RegisterMultiplexer *m_pRegPlex;
	instruct_t m_InstructAddr;
	flag_t m_FlagCollection[CPU_FLAGS];

	RAM* m_pRAM;
};

