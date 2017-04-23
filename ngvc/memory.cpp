#include <stdlib.h>
#include <iostream>

#include "common.h"
#include "memory.h"

//
//	Allocate Random accessible memory (RAM)
//	
RAM* ra_mem_alloc(instruct_t entry, uint32_t sz) {

	RAM* memory = (RAM*)malloc(sizeof(RAM_t) * sz);

	if (!memory) {
		puts("Error allocating RAM.\n");
		exit(-1);
	}

	memory->instruction = entry;
	return memory;
}

//
//	Allocate a Linked list (Stack)
//
List* mem_alloc(uint32_t data, List* addr) {
	List* list = (List*)malloc(sizeof(uint32_t) + sizeof(void*));
	return list;
}

//
//	Remove an existing element out of the stack (pop)
//
void pop(List* stack, uint32_t sz) {

}

//
//	Add a new element onto the stack (push)
//
void push(List* stack, uint32_t data) {

}