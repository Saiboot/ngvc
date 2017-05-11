#include "registers.h"
#include <iostream>
bool RegisterMultiplexer::operate(instruct_t op) {
	if (!op)
		return true;

	switch (get_op(op))
	{

		// FETCH FROM RAM */
		//
	case CPU_LOAD_A:
		m_Register_a = m_pRAM[get_arg(op)].instruction;
		return false;
	case CPU_LOAD_B:
		m_Register_b = m_pRAM[get_arg(op)].instruction;
		return false;
	case CPU_LOAD_C:
		m_Register_c = m_pRAM[get_arg(op)].instruction;
		return false;
	case CPU_LOAD_D:
		m_Register_d = m_pRAM[get_arg(op)].instruction;
		return false;

		// STORE IN RAM */
		//
	case CPU_STORE_A:
		m_pRAM[get_arg(op)].instruction = m_Register_a;
		return false;
	case CPU_STORE_B:
		m_pRAM[get_arg(op)].instruction = m_Register_b;
		return false;
	case CPU_STORE_C:
		m_pRAM[get_arg(op)].instruction = m_Register_c;
		return false;
	case CPU_STORE_D:
		m_pRAM[get_arg(op)].instruction = m_Register_d;
		return false;


		// MATHEMATICS */
		//
	case CPU_ADD:
		switch (get_arg1(op))
		{
		case CPU_Register_a:
			switch (get_arg2(op))
			{
			case CPU_Register_a:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_b:
				m_Register_a += m_Register_b;
				return false;
			case CPU_Register_c:
				m_Register_a += m_Register_c;
				return false;
			case CPU_Register_d:
				m_Register_a += m_Register_d;
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_b:
			switch (get_arg2(op))
			{
			case CPU_Register_a:
				m_Register_b += m_Register_a;
				return false;
			case CPU_Register_b:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_c:
				m_Register_b += m_Register_c;
				return false;
			case CPU_Register_d:
				m_Register_b += m_Register_d;
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_c:
			switch (get_arg2(op))
			{
			case CPU_Register_a:
				m_Register_c += m_Register_a;
				return false;
			case CPU_Register_b:
				m_Register_c += m_Register_b;
				return false;
			case CPU_Register_c:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_d:
				m_Register_c += m_Register_d;
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_d:
			switch (get_arg2(op))
			{
			case CPU_Register_a:
				m_Register_d += m_Register_a;
				return false;
			case CPU_Register_b:
				m_Register_d += m_Register_b;
				return false;
			case CPU_Register_c:
				m_Register_d += m_Register_c;
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
		switch (get_arg1(op))
		{
		case CPU_Register_a:
			switch (get_arg2(op))
			{
			case CPU_Register_a:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_b:
				m_Register_a -= m_Register_b;
				return false;
			case CPU_Register_c:
				m_Register_a -= m_Register_c;
				return false;
			case CPU_Register_d:
				m_Register_a -= m_Register_d;
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_b:
			switch (get_arg2(op))
			{
			case CPU_Register_a:
				m_Register_b -= m_Register_a;
				return false;
			case CPU_Register_b:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_c:
				m_Register_b -= m_Register_c;
				return false;
			case CPU_Register_d:
				m_Register_b -= m_Register_d;
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_c:
			switch (get_arg2(op))
			{
			case CPU_Register_a:
				m_Register_c -= m_Register_a;
				return false;
			case CPU_Register_b:
				m_Register_c -= m_Register_b;
				return false;
			case CPU_Register_c:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_d:
				m_Register_c -= m_Register_d;
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_d:
			switch (get_arg2(op))
			{
			case CPU_Register_a:
				m_Register_d -= m_Register_a;
				return false;
			case CPU_Register_b:
				m_Register_d -= m_Register_b;
				return false;
			case CPU_Register_c:
				m_Register_d -= m_Register_c;
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
		switch (get_arg1(op))
		{
		case CPU_Register_a:
			switch (get_arg2(op))
			{
			case CPU_Register_a:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_b:
				if (m_Register_a == m_Register_b) m_paCPUFlags[CPU_ZF] = 1;
				return false;
			case CPU_Register_c:
				if (m_Register_a == m_Register_c) m_paCPUFlags[CPU_ZF] = 1;
				return false;
			case CPU_Register_d:
				if (m_Register_a == m_Register_d) m_paCPUFlags[CPU_ZF] = 1;
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_b:
			switch (get_arg2(op))
			{
			case CPU_Register_a:
				if (m_Register_b == m_Register_a) m_paCPUFlags[CPU_ZF] = 1;
				return false;
			case CPU_Register_b:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_c:
				if (m_Register_b == m_Register_c) m_paCPUFlags[CPU_ZF] = 1;
				return false;
			case CPU_Register_d:
				if (m_Register_b == m_Register_d) m_paCPUFlags[CPU_ZF] = 1;
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_c:
			switch (get_arg2(op))
			{
			case CPU_Register_a:
				if (m_Register_c == m_Register_a) m_paCPUFlags[CPU_ZF] = 1;
				return true;
			case CPU_Register_b:
				if (m_Register_c == m_Register_b) m_paCPUFlags[CPU_ZF] = 1;
				return false;
			case CPU_Register_c:	/// error
				m_opErr = op;
				return true;
			case CPU_Register_d:
				if (m_Register_c == m_Register_d) m_paCPUFlags[CPU_ZF] = 1;
				return false;
			default:
				m_opErr = op;
				return true;
			}
			break;
		case CPU_Register_d:
			switch (get_arg2(op))
			{
			case CPU_Register_a:
				if (m_Register_d == m_Register_a) m_paCPUFlags[CPU_ZF] = 1;
				return false;
			case CPU_Register_b:
				if (m_Register_d == m_Register_b) m_paCPUFlags[CPU_ZF] = 1;
				return false;
			case CPU_Register_c:
				if (m_Register_d == m_Register_c) m_paCPUFlags[CPU_ZF] = 1;
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
		*m_pNextInstruction = get_arg(op);	///	Next instruction in queue
		return false;
	case CPU_JE:
		if (m_paCPUFlags[CPU_ZF] == FLAG_ON) {
			*m_pNextInstruction = get_arg(op);			///	Next instruction in queue
			m_paCPUFlags[CPU_ZF] = FLAG_OFF;			/// Reset the flag
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
