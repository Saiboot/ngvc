#include <iostream>
#include <string>

#include "common.h"
#include "CPU.h"
#include "memory.h"
#include "Assembler\file.h"

int kmain() {
		
	__int8 RAM_size = 1024;
	RAM_t *Memory = ra_mem_alloc(NULL, RAM_size);
	CPU *Processor = new CPU(Memory, RAM_size);

	instruct_t n;
	
	char *aBuf = inspectFile("Text.txt");
	printf("%d", len);

	for (size_t i = 0; i < len; i++)
	{
		puts(aBuf + i);
	}

	char* token;
	token = strtok(aBuf, " ");

	while (token != NULL) {
		printf("%s", token);
		token = strtok(NULL, " ");
	}
	
	while (true)
	{
		n = Processor->getInstructionID();			/// get next Instruction in queue
		Processor->Tick(Memory[n].instruction);		/// process the Instruction

		if(!Processor->recentFlagSwap())		/// Clear _old_ CPU flag states
			Processor->ClearFlags();
	}

	free(Processor);
	free(Memory);

	return 0;
}