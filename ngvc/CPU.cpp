#include "CPU.h"

CPU::CPU(RAM* RAMptr, unsigned int RAM_sz)
	:m_InstructAddr(0),
	 m_pRAM(0x0),
	 m_pRegPlex(0x0)
{
	m_pRAM = RAMptr;
	m_pRegPlex = new RegisterMultiplexer(m_pRAM, &m_InstructAddr, m_FlagCollection, RAM_sz);

	ClearFlags();
}


void CPU::Tick(instruct_t instruct)
{
	m_pRegPlex->operate(m_pRegPlex, instruct);
	m_InstructAddr++;
}


void CPU::ClearFlags()
{
	for (char i = 0; i < CPU_FLAGS; i++)
	{
		m_FlagCollection[i] = false;
	}
}


bool CPU::recentFlagSwap()
{
	for (char i = 0; i < CPU_FLAGS; i++)
	{
		if (m_FlagCollection[i] == true) 
			return true;
	}
}


CPU::~CPU()
{
}
