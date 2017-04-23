# ngvc
Virtual machine

Central Processor Unit
---
  <i> >> cpu.h </i>
  
    phases: (Fetch >> Decode >> Execute)
    
    Register Multiplexer
    Clock
      Instruction cycle
    ALU
    Flags
    
Random Access Memory 
---
  <i> >> memory.h </i>
  
    Data structure:
      op-code: 4-bits
      arguments: 4-bits
      Address (Index)
      
Stack Multiplexer 
---
Kernel
---
  <i> >> kernel.h </i>
  
Constants & type definitions 
---  
  <i> >> common.h </i>
  
    CPU operation templates (macros)
      ...
    Type definitions:
      register
      instruction
      flag
      RAM
      List (Stack)
