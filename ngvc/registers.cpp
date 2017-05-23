#include "registers.h"
#include <iostream>
#include "Assembler utilities\atribuf.h"

bool RegisterMultiplexer::operate(instruct_t op) {
	if (!op)
		return true;

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
		case CPU_Register_a:
			switch (op)
			{
			case CPU_Register_a:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_b:
				m_Register_eax += m_Register_ebx;
				return false;
			case CPU_Register_c:
				m_Register_eax += m_Register_ecx;
				return false;
			case CPU_Register_d:
				m_Register_eax += m_Register_edx;
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_b:
			switch (op)
			{
			case CPU_Register_a:
				m_Register_ebx += m_Register_eax;
				return false;
			case CPU_Register_b:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_c:
				m_Register_ebx += m_Register_ecx;
				return false;
			case CPU_Register_d:
				m_Register_ebx += m_Register_edx;
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_c:
			switch (op)
			{
			case CPU_Register_a:
				m_Register_ecx += m_Register_eax;
				return false;
			case CPU_Register_b:
				m_Register_ecx += m_Register_ebx;
				return false;
			case CPU_Register_c:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_d:
				m_Register_ecx += m_Register_edx;
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_d:
			switch (op)
			{
			case CPU_Register_a:
				m_Register_edx += m_Register_eax;
				return false;
			case CPU_Register_b:
				m_Register_edx += m_Register_ebx;
				return false;
			case CPU_Register_c:
				m_Register_edx += m_Register_ecx;
				return false;
			case CPU_Register_d:	/// error
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
		case CPU_Register_a:
			switch (op)
			{
			case CPU_Register_a:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_b:
				m_Register_eax -= m_Register_ebx;
				return false;
			case CPU_Register_c:
				m_Register_eax -= m_Register_ecx;
				return false;
			case CPU_Register_d:
				m_Register_eax -= m_Register_edx;
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_b:
			switch (op)
			{
			case CPU_Register_a:
				m_Register_ebx -= m_Register_eax;
				return false;
			case CPU_Register_b:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_c:
				m_Register_ebx -= m_Register_ecx;
				return false;
			case CPU_Register_d:
				m_Register_ebx -= m_Register_edx;
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_c:
			switch (op)
			{
			case CPU_Register_a:
				m_Register_ecx -= m_Register_eax;
				return false;
			case CPU_Register_b:
				m_Register_ecx -= m_Register_ebx;
				return false;
			case CPU_Register_c:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_d:
				m_Register_ecx -= m_Register_edx;
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_d:
			switch (op)
			{
			case CPU_Register_a:
				m_Register_edx -= m_Register_eax;
				return false;
			case CPU_Register_b:
				m_Register_edx -= m_Register_ebx;
				return false;
			case CPU_Register_c:
				m_Register_edx -= m_Register_ecx;
				return false;
			case CPU_Register_d:	/// error
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
		case CPU_Register_a:
			switch (op)
			{
			case CPU_Register_a:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_b:
				if (m_Register_eax == m_Register_ebx) nglib_utilities::setAttrib(m_pCPUFlags, CPU_ZF);
				return false;
			case CPU_Register_c:
				if (m_Register_eax == m_Register_ecx) nglib_utilities::setAttrib(m_pCPUFlags, CPU_ZF);
				return false;
			case CPU_Register_d:
				if (m_Register_eax == m_Register_edx) nglib_utilities::setAttrib(m_pCPUFlags, CPU_ZF);
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_b:
			switch (op)
			{
			case CPU_Register_a:
				if (m_Register_ebx == m_Register_eax) nglib_utilities::setAttrib(m_pCPUFlags, CPU_ZF);
				return false;
			case CPU_Register_b:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_c:
				if (m_Register_ebx == m_Register_ecx) nglib_utilities::setAttrib(m_pCPUFlags, CPU_ZF);
				return false;
			case CPU_Register_d:
				if (m_Register_ebx == m_Register_edx) nglib_utilities::setAttrib(m_pCPUFlags, CPU_ZF);
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_c:
			switch (op)
			{
			case CPU_Register_a:
				if (m_Register_ecx == m_Register_eax) nglib_utilities::setAttrib(m_pCPUFlags, CPU_ZF);
				return true;
			case CPU_Register_b:
				if (m_Register_ecx == m_Register_ebx) nglib_utilities::setAttrib(m_pCPUFlags, CPU_ZF);
				return false;
			case CPU_Register_c:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_d:
				if (m_Register_ecx == m_Register_edx) nglib_utilities::setAttrib(m_pCPUFlags, CPU_ZF);
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_d:
			switch (op)
			{
			case CPU_Register_a:
				if (m_Register_edx == m_Register_eax) nglib_utilities::setAttrib(m_pCPUFlags, CPU_ZF);
				return false;
			case CPU_Register_b:
				if (m_Register_edx == m_Register_ebx) nglib_utilities::setAttrib(m_pCPUFlags, CPU_ZF);
				return false;
			case CPU_Register_c:
				if (m_Register_edx == m_Register_ecx) nglib_utilities::setAttrib(m_pCPUFlags, CPU_ZF);
				return false;
			case CPU_Register_d:	/// error
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
