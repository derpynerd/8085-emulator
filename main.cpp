#include "include/constants.hpp"
#include "include/exceptions.hpp"
#include "include/memory.hpp"
#include "include/cpu.hpp"

int main() {

    CPU cpu;
    Memory memory;

    cpu.Reset( memory ); // RESET CPU to base state
    // start - inline testing program
    
    memory[0] = OPCODE::MVI_A_DAT;
    memory[1] = 0x24;
    memory[2] = OPCODE::CPI_DAT;
    memory[3] = 0x23;
    
    // end - inline testing program
    
    cpu.Execute( memory );
    cpu.Execute( memory ); 

    return 0;
}