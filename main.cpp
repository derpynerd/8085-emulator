#include "include/constants.hpp"
#include "include/exceptions.hpp"
#include "include/memory.hpp"
#include "include/cpu.hpp"

int main() {

    CPU cpu;
    Memory memory;

    cpu.Reset( memory ); // RESET CPU to base state
    // start - inline testing program
    
    memory[0] = OPCODE::INR_A;
    memory[1] = OPCODE::STA_ADDR;
    memory[2] = 0x05;
    memory[3] = 0x00;
    
    // end - inline testing program
    cpu.Execute( 1, memory ); // Execute instruction
    cpu.Execute( 3, memory );

    return 0;
}