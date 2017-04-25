#include "common.h"

#ifndef __RAM__

	#define __RAM__

//
//	Allocate Random accessible memory (RAM)
//	
//  @param entry_instruct: first instruction to execute.
//  @param sz: memory size.
//	
//  @return: address of memory entry point.
//
RAM* ra_mem_alloc(instruct_t entry, uint32_t sz);

//
//	Deallocate Random accessible memory (RAM)
//	
//	@param mem: ptr to RAM block to be deallocated.
//	@param sz: memory size.
//
//	@return: void
//
void ra_mem_dealloc(RAM *mem, uint32_t sz);

#endif __RAM__

#ifndef __STACK__
	
	#define __STACK__

//
//	Allocate a Linked list (Stack)
//
//  @param data: data to push to first memory element.
//  @param addr: address of next element.
//	
//  @return: address of memory entry point.
//
List* mem_alloc(uint32_t data, List* addr);

//
//	Remove an existing element out of the stack (pop)
//
//  @param stack: list target.
//  @param sz: amount of data to pop off the stack.
//	
//  @return: void
//
void pop(List* stack, uint32_t sz);

//
//	Add a new element onto the stack (push)
//
//  @param stack: list target.
//  @param data: data to push onto the stack.
//	
//  @return: void
//
void push(List* stack, uint32_t data);

#endif __STACK__