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

## Opcodes Supported -
- `RESET` processor (Gets executed on startup) -
    - Set initial value for all internal registers
    - Set all flags to `0`
    - Set value in accumulator to `0`
    - Initialize all memory bits to `0`
- `LDA (Address)` [Load Accumulator Immediate] -
    - Fetch value to be loaded into `A` from `Memory[PC]`
    - Load value into `A`
    - Set status flags accordingly
- `STA (Address)` [Store Accumulator Immediate] -
    - Fetch address to be stored in -> pre: loaded in `Memory[PC]` + `Memory[PC+1]`
    - Set value of `Memory[Address]` to value of `A`
- `LHLD (Address)` [Load HL Pair Immediate] -
    - Fetch address to load from `Memory[PC]`
    - Load value from `Memory[PC]` into `H`
    - Load value from `Memory[PC+1]` into `L`
- `SHLD (Address)` [Store HL Pair Immediate] -
    - Fetch address to store into -> pre: loaded in `Memory[PC]` & `Memory[PC+1]`
    - Set value of `Memory[PC]` to value of `H`
    - Set value of `Memory[PC+1]` to value of `L`
- `INR A` -
    - Increment `A` by `1`
    - Set status flags accordingly
- `JMP` [Unconditional Jump] -
    - Fetch address to jump to -> pre: loaded in `Memory[PC]` + `Memory[PC+1]`
    - Jump to given address (`PC` = `Address`)

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
- Plan: what to do about the clock cycle parameter ? 
- Fix: unable to print memory[Addr] values