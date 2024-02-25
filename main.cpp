#include <stdio.h>
#include <stdlib.h>

using Byte = unsigned char; // 8 bit
using Word = unsigned short; // 16 bit

using u32 = unsigned int; // 64 bit

class Memory {
    static constexpr u32 MAX_MEM = 1024 * 64;
    Byte Data[MAX_MEM];

    protected:
    void Initialize(Memory& memory) {
        for(u32 i = 0; i < MAX_MEM; ++i) {
            memory.Data[i] = 0;
        }
    }
};

class CPU : private Memory {

    /* Internal Registers */
    Word SP; // Stack pointer
    Word PC; // Program counter
    Byte IR; // Instruction register

    /* Registers */
    Byte A; // Accumulator
    Word WZ; // Temporary registers
    Word BC, DE, HL; // Registers

    /* Flag register */
    Byte S : 1; // Sign flag 
    Byte Z : 1; // Zero flag
    Byte AC : 1; // Auxiliary Carry flag
    Byte P : 1; // Parity flag
    Byte C : 1; // Carry flag

    /* Signals */
    Word ResetIn : 1; // RESET CPU signal
    Word ResetOut : 1; // RESET acknowledge - Output
    Word HOLD : 1; // HOLD request 
    Word HLDA : 1; // HOLD acknowledge - Output

    /* Interrupts */
    Word INTR : 1; // Interrupt request - Least priority
    Word INTA : 1; // Interrupt acknowledge - Output
    Word RST5_5 : 1; //  002C
    Word RST6_5 : 1; // 0034
    Word RST7_5 : 1; // 003C
    Word TRAP : 1; // 	0024

    public:
    /* Reset routine */
    void Reset(Memory& memory) {
        PC = 0x0000; // No reset vector for 8085
        IR = 0x00; // Default reset routine
        SP = 0x0100; // Starting stack from random memory location

        S = Z = AC = P = C = 0; // Resetting all flags 

        Memory::Initialize( memory ); // Initializing all memory bits to 0
    }

};

int main() {

    CPU cpu;
    Memory memory;

    cpu.Reset( memory );


    return 0;
}