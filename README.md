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
    - Sets initial value for all internal registers
    - Sets all flags to `0`
    - Sets value in accumulator to `0`
    - Initializes all memory bits to `0`
- `LDA (Address)` [Load Accumulator Immediate] -
    - Fetches value to be loaded into `A` from `Memory[PC]`
    - Loads value into `A`
    - Set status flags accordingly
- `INR A` -
    - Increment `A` by `1`
    - Set status flags accordingly

## Abbreviations - 
- PC - Program Counter
- SP - Stack Pointer
- IR - Instruction Register
- A - Accumulator
- Z - Zero flag
- S - Sign flag
