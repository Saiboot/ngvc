#include <iostream>
#include <string>

#include "common.h"
#include "CPU.h"
#include "memory.h"
#include "Assembler utilities\file.h"
#include "Assembler utilities\format.h"

int kmain() {
		
	int RAM_size = 1024;
	RAM_t *Memory = ra_mem_alloc(NULL, RAM_size);
	CPU *Processor = new CPU(Memory, RAM_size);

	char *aBuf = inspectFile("Text.txt");
	puts(aBuf);

	std::cout << std::endl;
	std::cout << sizeof(aBuf) << std::endl;
	
	/*
	char* token;
	if (strtok(aBuf, ":"))
		std::cout << ">> Found a label!";
	
	while (token != NULL) {
		printf("%s", token);
		token = strtok(NULL, " ");
	}
	*/

	instruct_t n;

	while (true)
	{
		n = Processor->getInstructionID();			/// get next Instruction in queue
		Processor->Tick(Memory[n].instruction);		/// process the Instruction

		if(!Processor->recentFlagSwap())		/// Clear _old_ CPU flag states
			Processor->ClearFlags();
	}

	free(aBuf);
	free(Processor);
	ra_mem_dealloc(Memory, RAM_size);

	return 0;
}