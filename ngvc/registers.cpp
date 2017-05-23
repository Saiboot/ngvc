#include "registers.h"
#include <iostream>
#include "Assembler utilities\atribuf.h"

bool RegisterMultiplexer::operate(instruct_t op) {
	if (!op)
		return true;

	switch (nglib_utilities::peekAttrib(op, INSTRUCT_OPCODE))
	{
	case CPU_MOV:

		RAM *mem = (RAM*)malloc(sizeof(RAM) * 30);


		break;
	}

	switch (op)
	{

		// FETCH FROM RAM */
		//
	//case CPU_LOAD_A:
	//	m_Register_eax = m_pRAM[op].instruction;
	//	return false;
	//case CPU_LOAD_B:
	//	m_Register_ebx = m_pRAM[op].instruction;
	//	return false;
	//case CPU_LOAD_C:
	//	m_Register_ecx = m_pRAM[op].instruction;
	//	return false;
	//case CPU_LOAD_D:
	//	m_Register_edx = m_pRAM[op].instruction;
	//	return false;

	//	// STORE IN RAM */
	//	//
	//case CPU_STORE_A:
	//	m_pRAM[op].instruction = m_Register_eax;
	//	return false;
	//case CPU_STORE_B:
	//	m_pRAM[op].instruction = m_Register_ebx;
	//	return false;
	//case CPU_STORE_C:
	//	m_pRAM[op].instruction = m_Register_ecx;
	//	return false;
	//case CPU_STORE_D:
	//	m_pRAM[op].instruction = m_Register_edx;
	//	return false;


		// MATHEMATICS */
		//
	case CPU_ADD:
		switch (op)
		{
		case CPU_Register_EAX:
			switch (op)
			{
			case CPU_Register_EAX:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_EBX:
				m_Register_eax += m_Register_ebx;
				return false;
			case CPU_Register_ECX:
				m_Register_eax += m_Register_ecx;
				return false;
			case CPU_Register_EDX:
				m_Register_eax += m_Register_edx;
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_EBX:
			switch (op)
			{
			case CPU_Register_EAX:
				m_Register_ebx += m_Register_eax;
				return false;
			case CPU_Register_EBX:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_ECX:
				m_Register_ebx += m_Register_ecx;
				return false;
			case CPU_Register_EDX:
				m_Register_ebx += m_Register_edx;
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_ECX:
			switch (op)
			{
			case CPU_Register_EAX:
				m_Register_ecx += m_Register_eax;
				return false;
			case CPU_Register_EBX:
				m_Register_ecx += m_Register_ebx;
				return false;
			case CPU_Register_ECX:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_EDX:
				m_Register_ecx += m_Register_edx;
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_EDX:
			switch (op)
			{
			case CPU_Register_EAX:
				m_Register_edx += m_Register_eax;
				return false;
			case CPU_Register_EBX:
				m_Register_edx += m_Register_ebx;
				return false;
			case CPU_Register_ECX:
				m_Register_edx += m_Register_ecx;
				return false;
			case CPU_Register_EDX:	/// error
				m_opErr = op;
				return true;
			default:
				m_opErr = op;
				return true;
			}
			break;
		default:
			m_opErr = op;
			return true;
		}
		break;
	case CPU_SUB:
		switch (op)
		{
		case CPU_Register_EAX:
			switch (op)
			{
			case CPU_Register_EAX:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_EBX:
				m_Register_eax -= m_Register_ebx;
				return false;
			case CPU_Register_ECX:
				m_Register_eax -= m_Register_ecx;
				return false;
			case CPU_Register_EDX:
				m_Register_eax -= m_Register_edx;
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_EBX:
			switch (op)
			{
			case CPU_Register_EAX:
				m_Register_ebx -= m_Register_eax;
				return false;
			case CPU_Register_EBX:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_ECX:
				m_Register_ebx -= m_Register_ecx;
				return false;
			case CPU_Register_EDX:
				m_Register_ebx -= m_Register_edx;
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_ECX:
			switch (op)
			{
			case CPU_Register_EAX:
				m_Register_ecx -= m_Register_eax;
				return false;
			case CPU_Register_EBX:
				m_Register_ecx -= m_Register_ebx;
				return false;
			case CPU_Register_ECX:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_EDX:
				m_Register_ecx -= m_Register_edx;
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_EDX:
			switch (op)
			{
			case CPU_Register_EAX:
				m_Register_edx -= m_Register_eax;
				return false;
			case CPU_Register_EBX:
				m_Register_edx -= m_Register_ebx;
				return false;
			case CPU_Register_ECX:
				m_Register_edx -= m_Register_ecx;
				return false;
			case CPU_Register_EDX:	/// error
				m_opErr = op;
				return true;
			default:
				m_opErr = op;
				return true;
			}
			break;
		default:
			m_opErr = op;
			return true;
		}
		break;
	case CPU_CMP:
		switch (op)
		{
		case CPU_Register_EAX:
			switch (op)
			{
			case CPU_Register_EAX:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_EBX:
				if (m_Register_eax == m_Register_ebx) nglib_utilities::setAttrib(m_pCPUFlags, CPU_ZF);
				return false;
			case CPU_Register_ECX:
				if (m_Register_eax == m_Register_ecx) nglib_utilities::setAttrib(m_pCPUFlags, CPU_ZF);
				return false;
			case CPU_Register_EDX:
				if (m_Register_eax == m_Register_edx) nglib_utilities::setAttrib(m_pCPUFlags, CPU_ZF);
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_EBX:
			switch (op)
			{
			case CPU_Register_EAX:
				if (m_Register_ebx == m_Register_eax) nglib_utilities::setAttrib(m_pCPUFlags, CPU_ZF);
				return false;
			case CPU_Register_EBX:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_ECX:
				if (m_Register_ebx == m_Register_ecx) nglib_utilities::setAttrib(m_pCPUFlags, CPU_ZF);
				return false;
			case CPU_Register_EDX:
				if (m_Register_ebx == m_Register_edx) nglib_utilities::setAttrib(m_pCPUFlags, CPU_ZF);
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_ECX:
			switch (op)
			{
			case CPU_Register_EAX:
				if (m_Register_ecx == m_Register_eax) nglib_utilities::setAttrib(m_pCPUFlags, CPU_ZF);
				return true;
			case CPU_Register_EBX:
				if (m_Register_ecx == m_Register_ebx) nglib_utilities::setAttrib(m_pCPUFlags, CPU_ZF);
				return false;
			case CPU_Register_ECX:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_EDX:
				if (m_Register_ecx == m_Register_edx) nglib_utilities::setAttrib(m_pCPUFlags, CPU_ZF);
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_EDX:
			switch (op)
			{
			case CPU_Register_EAX:
				if (m_Register_edx == m_Register_eax) nglib_utilities::setAttrib(m_pCPUFlags, CPU_ZF);
				return false;
			case CPU_Register_EBX:
				if (m_Register_edx == m_Register_ebx) nglib_utilities::setAttrib(m_pCPUFlags, CPU_ZF);
				return false;
			case CPU_Register_ECX:
				if (m_Register_edx == m_Register_ecx) nglib_utilities::setAttrib(m_pCPUFlags, CPU_ZF);
				return false;
			case CPU_Register_EDX:	/// error
				m_opErr = op;
				return true;
			default:
				m_opErr = op;
				return true;
			}
			break;
		default:
			m_opErr = op;
			return true;
		}
		break;

		// MEMORY JUMPING */
		//
	case CPU_JMP:
		*m_pNextInstruction = op;	///	Next instruction in queue
		return false;
	case CPU_JE:
		if (m_pCPUFlags[CPU_ZF] == FLAG_ON) {
			*m_pNextInstruction = op;			///	Next instruction in queue
			m_pCPUFlags[CPU_ZF] = FLAG_OFF;			/// Reset the flag
		}
		return false;
		// CPU Interrupts */
		//
	case CPU_HALT:
		// *m_pNextInstruction = m_RAM_sz;
		return false;
	default:
		break;
	}
	return true;
}

__int8 RegisterMultiplexer::doop_R(RAM *pRAM, uint8_t reg1, uint8_t reg2, uint8_t reg3, uint8_t shift, uint8_t func)
{



	return 0;
}

__int8 RegisterMultiplexer::doop_I(RAM *pRAM, uint8_t reg1, uint8_t reg2, uint16_t immed)
{



	return 0;
}

__int8 RegisterMultiplexer::doop_J(RAM *pRAM, uint32_t target)
{



	return 0;
}
