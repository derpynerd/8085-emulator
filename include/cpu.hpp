#include "constants.hpp"
#include "memory.hpp"
#pragma once

class CPU {

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
    Byte CY : 1; // Carry flag

    /* Control Signals */
    Byte READY : 1; // Peripheral data transfer => Ready = 1
    Byte RD_ : 1; // Read operation => Read = 0
    Byte WR_ : 1; // Write operation => Write = 0
    Byte ALE : 1; // Address Latch Enabled => Data bus = 0, Address bus = 1

    /* Status Signals */
    Byte S0 : 1; // General status signal
    Byte S1 : 1; // General status signal
    Byte IO_M_ : 1; // I/0 - Memory signal => Memory = 0, I/O = 1
    
    /* DMA Signals */
    Byte HOLD : 1; // HOLD request 
    Byte HLDA : 1; // HOLD acknowledge - Output

    /* Reset Signals */
    Byte RESET_IN_ : 1; // RESET CPU  
    Byte RESET_OUT : 1; // RESET acknowledge - Output

    /* Interrupts */
    Word INTR : 1; // Interrupt request - Least priority
    Word INTA_ : 1; // Interrupt acknowledge - Output
    Word RST5_5 : 1; // 002C
    Word RST6_5 : 1; // 0034
    Word RST7_5 : 1; // 003C
    Word TRAP : 1; // 0024

    /* I/O */
    Byte SID : 1; // Serial input
    Byte S0D : 1; // Serial output
    Word AD_0_7 : 8; // Input address bus AD0 - AD7
    Word AD_8_15 : 8; // Input address bus AD8 - AD15 

    public:
    /* Reset routine */
    void Reset( Memory& memory ) {
        PC = 0x0000; // No reset vector for 8085
        IR = 0x00; // Default reset routine
        SP = 0x0100; // Starting stack from random memory location
        
        S = Z = AC = P = CY = 0; // Resetting all flags 
        A = 0; // Resetting Accumulator

        memory.Initialize(); // Initializing all memory bits to 0
    }

    /* Fetch one Byte from PC */
    Byte FetchByte( u32& cycles, Memory& memory ) {
        Byte Data = memory[PC];
        PC++;
        cycles--;
        return Data;
    }

    /* Fetch one Word from PC, PC + 1 */
    Word FetchWord( u32& cycles, Memory& memory ) {
        Byte Upper = memory[PC++];
        Byte Lower = memory[PC++];
        cycles -= 2;
        return (((Word)Upper) << 8) | ((Word)Lower);
    }

    void AccumulatorSetFlags() {
        Z = (A == 0); // Set Zero flag if A == 0
        S = (A & 0b10000000) > 0; // Set Sign flag if 8th bit of A is 1 i.e. A is negative
    }

    /* Check if required number of clock cycles are present to execute instruction */
    void CheckCycles(u32& cycles, u32 requiredCycles) {
        if (cycles < requiredCycles) throw OutOfCycles();
        return;
    }

    /* Fetch -> Decode -> Execute procedure */
    void Execute( u32 cycles, Memory& memory ) {
        while (cycles > 0) {
            IR = FetchByte( cycles, memory );
            switch( IR ) {
                case OPCODE::LDA_IMM:
                {
                    CheckCycles( cycles, 1 );
                    Byte Value = FetchByte( cycles, memory ); // Fetch value to load into Accumulator
                    A = Value; 
                    AccumulatorSetFlags();
                } break;
                case OPCODE::INR_A:
                {
                    CheckCycles( cycles, 1 );
                    A += 0b00000001; // Increment Accumulator by 1
                    AccumulatorSetFlags();
                } break;
                case OPCODE::JMP:
                {   
                    CheckCycles( cycles, 2 );
                    Word Address = FetchWord( cycles, memory );
                    PC = Address;
                } break;
                default:
                    throw InvalidOpcode();
            }

        }
        

    }

};