# 8085-emulator
Emulating an 8085 processor in C++

## Specifications - 
- 64KB of stack memory (1024 * 64 * 8 bits)

## Functional Overview -
- Reset operation
- Fetch -> Decode -> Execute cycle implementation
    - Fetches current instruction from `Memory[PC]` and stores into the `IR`
    - Decodes fetched instruction via switch-case
    - If decoded instruction is valid, it gets executed

## Abbreviations - 
- PC - Program Counter
- SP - Stack Pointer
- IR - Instruction Register
- A - Accumulator
- Z - Zero flag
- S - Sign flag

## Future Plans -
- Opcode decoder which can read opcodes from a text file and execute them
- Adding on to above point, syntax checker - proper compiler/interpreter perhaps (?)
- ~~Plan: what to do about the clock cycle parameter ?~~ -> removed cycles as a param
- Fix: unable to print memory[Addr] values
- ~~Updated readme will not specify all opcodes (opcode list will be included) but only specify how exactly the opcodes are implemented here (if any changes)~~
- Implementation scope - 
    - Assembly program for 8085 will be loaded into emulator
    - Assembler/Decoder will take care of parsing opcodes and setting program memory according to parameters passed and number of CPU execute calls required based on number of opcodes decoded
    - Hence allowing for the program to be run seamlessly by simply calling the CPU execute function based on number of opcode count  
- Decouple CPU functions and Instruction implementations - write functions to call within instructions to use repeated functionality