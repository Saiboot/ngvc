#include "CPU.h"

using namespace nglib_utilities;	// Buffer attribute manipulation

CPU::CPU(RAM* RAMptr, unsigned int RAM_sz)
	:m_InstructAddr(0),
	 m_InstructErr(0),
	 m_pRAM(0x0),
	 m_pRegPlex(0x0)
{
	m_pRAM = RAMptr;
	m_pRegPlex = new RegisterMultiplexer(m_pRAM, &m_InstructAddr, &m_FlagCollection, RAM_sz);

	ClearFlags();
}


void CPU::Tick(instruct_t instruct)
{
	m_InstructErr = false;

	if (!m_pRegPlex->operate(instruct)) m_InstructErr = true;
	++m_InstructAddr;
}


void CPU::ClearFlags()
{
	clearAttrib(&m_FlagCollection, CPU_FLAGS);
}


bool CPU::recentFlagSwap()
{
	if (peekAttrib(m_FlagCollection, CPU_ZF) ||		// Zero
		peekAttrib(m_FlagCollection, CPU_OF) ||		// Overflow
		peekAttrib(m_FlagCollection, CPU_SF) ||		// Sign
		peekAttrib(m_FlagCollection, CPU_CF))		// Carry
		return true;
}


CPU::~CPU()
{
}
