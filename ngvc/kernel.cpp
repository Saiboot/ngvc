#include <iostream>
#include <string>
#include <time.h>

#include "common.h"
#include "CPU.h"
#include "memory.h"
#include "Assembler utilities\file.h"
#include "Assembler utilities\format.h"


int kmain() {
	
	// Initialize Hardware components //

	int RAM_size = 255;
	RAM *Memory = ra_mem_alloc(NULL, RAM_size);
	CPU *Processor = new CPU(Memory, RAM_size);

	// Generate random opcodes for testing //

	srand(time(NULL));
	for (int i = 0; i < RAM_size; i++)
	{
			Memory[i].instruction = rand() % 200;	
	}

	instruct_t n;
	int i = 0;
	while (true)
	{
		n = Processor->getInstructionID();			/// get next Instruction in queue
		Processor->Tick(Memory[n].instruction);		/// process the Instruction
		
		std::cout << "Cycle: " << i << "\tAddress: " << (int)n;
		printf("\tInstruction: %d  /  0x%x", Memory[n].instruction, Memory[n].instruction);

		if (Processor->m_InstructErr)
			printf("\nError code: %d / 0x%x", Processor->getError(), Processor->getError());

		if(!Processor->recentFlagSwap())		/// Clear _old_ CPU flag states
			Processor->ClearFlags();

		i++;
		std::cin.get();
	}

	free(Processor);
	ra_mem_dealloc(Memory, RAM_size);

	return 0;
}