#include "include/constants.hpp"
#include "include/exceptions.hpp"
#include "include/memory.hpp"
#include "include/cpu.hpp"

int main() {

    CPU cpu;
    Memory memory;

    cpu.Reset( memory ); // RESET CPU to base state
    // start - inline testing program

    memory[0] = OPCODE::JMP;
    memory[1] = 0x01;
    memory[2] = 0x3C;
    memory[0x013C] = OPCODE::INR_A;
    
    // end - inline testing program
    cpu.Execute( 3, memory ); // Execute instruction
    cpu.Execute( 1, memory );

    return 0;
}