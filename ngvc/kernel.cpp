#include <iostream>

#include "common.h"
#include "CPU.h"
#include "memory.h"

int kmain() {
		
	__int8 RAM_size = 1024;
	RAM_t *Memory = ra_mem_alloc(NULL, RAM_size);
	CPU *Processor = new CPU(Memory, RAM_size);

	instruct_t n;

	while (true)
	{
		n = Processor->getInstructionID();			/// get next Instruction in queue
		Processor->Tick(Memory[n].instruction);		/// process the Instruction

		if(!Processor->recentFlagSwap())		/// Clear _old_ CPU flag states
			Processor->ClearFlags();
	}

	return 0;
}