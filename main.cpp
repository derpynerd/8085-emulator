#include "include/constants.hpp"
#include "include/exceptions.hpp"
#include "include/memory.hpp"
#include "include/cpu.hpp"

int main() {

    CPU cpu;
    Memory memory;

    cpu.Reset( memory ); // RESET CPU to base state
    // start - inline testing program

    memory[0] = 0x3A;
    memory[1] = 0x01;
    memory[2] = 0x3C;
    
    // end - inline testing program
    cpu.Execute( 2, memory ); // Execute instructions with 2 clock cycles
    cpu.Execute( 1, memory );

    return 0;
}