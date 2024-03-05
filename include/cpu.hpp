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
    Byte W, Z; // Temporary registers
    Byte B, C, D, E, H, L; // Registers

    /* Flag register */
    Byte Sign : 1; // Sign flag 
    Byte Zero : 1; // Zero flag
    Byte AuxC : 1; // Auxiliary Carry flag
    Byte Parity : 1; // Parity flag
    Byte Carry : 1; // Carry flag

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

    Byte HALT : 1;
    Byte InterruptEnable_ : 1;

    public:
    /* Reset routine */
    void Reset( Memory& memory ) {
        PC = 0x0000; // No reset vector for 8085
        IR = 0x00; // Default reset routine
        SP = 0x0100; // Starting stack from random memory location
        
        Sign = Zero = AuxC = Parity = Carry = 0; // Resetting all flags 
        A = 0; // Resetting Accumulator
        HALT = 0; // Not in halt state
        InterruptEnable_ = 1;

        memory.Initialize(); // Initializing all memory bits to 0
    }

    /* Fetch one Byte from PC */
    Byte FetchByte( Memory& memory ) {
        Byte Data = memory[PC++];
        return Data;
    }

    /* Fetch one Word from PC, PC + 1 */
    Word FetchWord( Memory& memory ) {
        Byte Low = memory[PC++];
        Byte High = memory[PC++];
        return (((Word)High) << 8) | ((Word)Low);
    }

    void AccumulatorSetFlags() {
        Zero = (A == 0); // Set Zero flag if A == 0
        Sign = (A & 0b10000000) > 0; // Set Sign flag if 8th bit of A is 1 i.e. A is negative
    }

    /* Fetch -> Decode -> Execute procedure */
        void Execute( Memory& memory ) {

        if (HALT == 1) {
            if (InterruptEnable_ == 0 && TRAP == 1) {
                // base implementation
            }

        }

        else {

            IR = FetchByte( memory );
            switch( IR ) {

                /* Control Instructions */
                case OPCODE::NOP: // No operation is performed
                {} break;
                case OPCODE::HLT: // CPU stops further execution - An interrupt or reset is necessary to exit from the halt state.
                {
                    HALT = 1;
                } break;
                case OPCODE::DI: // Interrupt enable is reset - All interrupts are disabled except TRAP
                {
                    InterruptEnable_ = 0; // reset IE_
                } break;
                case OPCODE::EI: // Interrupt enable is set - All interrupts are enabled
                {
                    InterruptEnable_ = 1; // set IE_
                } break;
                case OPCODE::RIM: // Read status of interrupts 7.5, 6.5, 5.5 and read serial data input bit
                {

                } break;
                case OPCODE::SIM: // Implement interrupts 7.5, 6.5, 5.5 and perform serial data output
                {

                } break;
                

                /* Logical Instructions */
                case OPCODE::CMP_A:
                {
                    
                } break;
                case OPCODE::CPI_DAT:
                {
                    Byte Value = FetchByte( memory );
                    if (A < Value) { Carry = 1; Zero = 0; }
                    else if (A == Value) {Carry = 0; Zero = 1; }
                    else if (A > Value) {Carry = 0; Zero = 0; }
                } break;
                case OPCODE::ANA_A:
                {

                } break;
                case OPCODE::ANI_DAT:
                {

                } break;
                case OPCODE::XRA_A:
                {

                } break;
                case OPCODE::XRI_DAT:
                {

                } break;
                case OPCODE::ORA_A:
                {

                } break;
                case OPCODE::ORI_DAT:
                {

                } break;
                case OPCODE::RLC:
                {

                } break;
                case OPCODE::RRC:
                {

                } break;
                case OPCODE::RAL:
                {

                } break;
                case OPCODE::RAR:
                {

                } break;
                case OPCODE::CMA:
                {

                } break;
                case OPCODE::CMC:
                {

                } break;
                case OPCODE::STC:
                {

                } break;


                /* Data Transfer Group */
                case OPCODE::MVI_A_DAT:
                {
                    Byte Value = FetchByte( memory );
                    A = Value;
                    AccumulatorSetFlags();
                } break;
                case OPCODE::LDA_ADDR:
                {
                    Word Address = FetchWord( memory ); // Fetch value to load into Accumulator
                    A = memory[Address]; 
                    AccumulatorSetFlags();
                } break;
                case OPCODE::STA_ADDR:
                {
                    Word Address = FetchWord( memory ); // Fetch address to store value in
                    memory[Address] = A;
                } break;
                case OPCODE::LHLD_ADDR:
                {
                    Word Address = FetchWord( memory );
                    L = memory[Address]; // L set to lower address value
                    H = memory[Address + 1]; // H set to higher address value
                } break;
                case OPCODE::SHLD_ADDR:
                {
                    Word Address = FetchWord( memory ); // Fetch address to store value in
                    memory[Address] = H; // Lower address value gets set to value of H
                    memory[Address + 1] = L; // Higher address value gets set to value of L
                } break;


                /* Arithmetic Group */
                case OPCODE::INR_A:
                {
                    A += 0b00000001; // Increment Accumulator by 1
                    AccumulatorSetFlags();
                } break;


                /* Branch Instructions */
                case OPCODE::JMP_ADDR:
                {   
                    Word Address = FetchWord( memory );
                    PC = Address;
                } break;


                /* Invalid Instruction */
                default:
                    throw InvalidOpcode();
            }

        
        }    

    }

};