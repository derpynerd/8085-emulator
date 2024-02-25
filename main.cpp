#include "constants.hpp"
#include "exceptions.hpp"
#include "memory.hpp"
#include "cpu.hpp"

int main() {

    CPU cpu;
    Memory memory;

    cpu.Reset( memory ); // RESET CPU to base state
    memory[0] = 0x3A;
    memory[1] = 0x01;
    cpu.Execute( 2, memory ); // Execute instructions with 2 clock cycles

    return 0;
}