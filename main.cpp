#include "constants.h"
#include "exceptions.h"
#include "memory.h"
#include "cpu.h"

int main() {

    CPU cpu;
    Memory memory;

    cpu.Reset( memory ); // RESET CPU to base state
    memory.setByte( 0, 0x3A );
    memory.setByte( 1, 0b10001000 );
    cpu.Execute( 2, memory ); // Execute instructions with 2 clock cycles

    return 0;
}