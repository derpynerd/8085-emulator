#pragma once

using Byte = unsigned char; // 8 bit
using Word = unsigned short; // 16 bit

using u32 = unsigned int; // 64 bit

class OPCODE {

public:
    /* Data Transfer Group */
    static constexpr Byte MOV_R1_R2 = 0x78; // Move data from Register 2 to Register 1 : [r1] <-- [r2]
    static constexpr Byte MOV_R_M = 0x7E; // Move data from Memory to Register : r <-- [M]
    static constexpr Byte MOV_M_R = 0x77; // Move data from Register to Memory : M <-- [r]
    static constexpr Byte MVI_R_DAT = 0x3E; // Move immediate Data to Register : [r] <-- data
    static constexpr Byte MVI_M_DAT = 0x36; // Move immediate Data to Memory : [M] <-- data
    static constexpr Byte LXI_RP_DAT = 0x01; // Load Register pair immediate : [rp] <-- data 16 bits, [rh] <-- 8 LSBs of data
    static constexpr Byte LDA_ADDR = 0x3A; // Load Accumulator Direct : [A] <-- [addr]
    static constexpr Byte STA_ADDR = 0x32; // Store Accumulator Direct : [addr] <-- [A]
    static constexpr Byte LHLD_ADDR = 0x2A; // Load H-L pair Direct : [L] <-- [addr], [H] <-- [addr+1]
    static constexpr Byte SHLD_ADDR = 0x22; // Store H-L pair Direct : [addr] <-- [L], [addr+1] <-- [H] 
    static constexpr Byte LDAX_RP = 0x0A; // Load Accumulator Indirect : [A] <-- [[rp]]
    static constexpr Byte STAX_RP = 0x02; // Store Accumulator Indirect : [[rp]] <-- [A]
    static constexpr Byte XCHG = 0xEB; // Exchange data between H-L and D-E pairs : [H-L] <-> [D-E]

    /* Arithmetic Group */
    static constexpr Byte ADD_R = 0x87; // Add Register to Accumulator : [A] <-- [A] + [r]
    static constexpr Byte ADD_M = 0x86; // Add Memory to Accumulator : [A] <-- [A] + [[H-L]]
    static constexpr Byte ADC_R = 0x8F; // Add Register with carry to Accumulator : [A] <-- [A] + [r] + [CS]
    static constexpr Byte ADC_M = 0x8E; // Add Memory with carry to Accumulator : [A] <-- [A] + [[H-L]] + [CS]
    static constexpr Byte ADI_DAT = 0xC6; // Add immediate Data to Accumulator : [A] <-- [A] + data
    static constexpr Byte ACI_DAT = 0xCE; // Add with carry immediate data to Accumulator : [A] <-- [A] + data + [CS]
    static constexpr Byte DAD_RP = 0x09; // Add Register pair to H-L pair : [H-L] <-- [H-L] + [rp]
    static constexpr Byte SUB_R = 0x97; // Subtract Register from Accumulator : [A] <-- [A] – [r]
    static constexpr Byte SUB_M = 0x96; // Subtract Memory from Accumulator : [A] <-- [A] – [[H-L]]
    static constexpr Byte SBB_R = 0x9F; // Subtract Register from Accumulator with borrow : [A] <-- [A] – [r] – [CS]
    static constexpr Byte SBB_M = 0x9E; // Subtract Memory from Accumulator with borrow : [A] <-- [A] – [[H-L]] – [CS]
    static constexpr Byte SUI_DAT = 0xD6; // Subtract immediate data from Accumulator : [A] <-- [A] – data
    static constexpr Byte SBI_DAT = 0xDE; // Subtract immediate data from Accumulator with borrow : [A] <-- [A] – data - [CS]
    static constexpr Byte INR_R = 0x3C; // Increment Register content : [r] <-- [r] + 1
    static constexpr Byte INR_M = 0x34; // Increment Memory content : [[H-L]] <-- [[H-L]] + 1
    static constexpr Byte DCR_M = 0x35; // Decrement Memory content : [[H-L]] <-- [[H-L]] - 1
    static constexpr Byte INX_RP = 0x03; // Increment Register pair : [rp] <-- [rp] + 1
    static constexpr Byte DCX_RP = 0x0B; // Decrement Register pair : [rp] <-- [rp] - 1
    static constexpr Byte DAA = 0x27; // Decimal adjust Accumulator
    
    /* Logical Group */
    static constexpr Byte ANA_R = 0xA7; // AND Register with Accumulator : [A] <-- [A] ^ [r]
    static constexpr Byte ANA_M = 0xA6; // AND Memory with Accumulator : [A] <-- [A] ^ [[H-L]]
    static constexpr Byte ANI_DAT = 0xE6; // AND immediate data with Accumulator : [A] <-- [A] ^ data
    static constexpr Byte ORA_R = 0xB7; // OR Register with Accumulator : [A] <-- [A] v [r]
    static constexpr Byte ORA_M = 0xB6; // OR Memory with Accumulator : [A] <-- [A] v [[H-L]]
    static constexpr Byte ORI_DAT = 0xF6; // OR immediate data with Accumulator : [A] <-- [A] v data
    static constexpr Byte XRA_R = 0xAF; // XOR Memory with Accumulator : [A] <-- [A] V [r]
    static constexpr Byte XRA_M = 0xAE; // XOR Memory with Accumulator : [A] <-- [A] V [[H-L]]
    static constexpr Byte XRI_DAT = 0xEE; // XOR immediate data with Accumulator : [A] <-- [A] V data
    static constexpr Byte CMA = 0x2F; // Complement the Accumulator : [A] <-- [A]
    static constexpr Byte CMC = 0x3F; // Complement the carry status : [CS] <-- [CS]
    static constexpr Byte STC = 0x37; // Set carry status : [CS] <-- 1
    static constexpr Byte CMP_R = 0xBF; // Compare Register with Accumulator : [A] -- [r]
    static constexpr Byte CMP_M = 0xBD; // Compare Memory with Accumulator : [A] -- [[H-L]]
    static constexpr Byte CPI_DAT = 0xFE; // Compare immediate data with Accumulator : [A] -- data
    static constexpr Byte RLC = 0x07; // Rotate Accumulator left : [An+1] <-- [An], [A0] <-- [A7], [CS] <--[A7]
    static constexpr Byte RRC = 0x0F; // Rotate Accumulator right : [An] <-- [An+1], [CS] <-- [A0], [An] <-- [An+1]
    static constexpr Byte RAL = 0x17; // Rotate Accumulator left through carry : [An+1] <-- [An], [CS] <-- [A7], [A0] <-- [CS]
    static constexpr Byte RAR = 0x1F; // Rotate Accumulator right through carry :  [An] <-- [An+1], [CS] <-- [A0], [A7] <-- [CS]

    /* Branch Group */
    static constexpr Byte JMP_ADDR = 0xC3; // Unconditional jump : [PC] <-- Address/Label
    static constexpr Byte JZ_ADDR = 0xCA; // Jump if Z == 0
    static constexpr Byte JNZ_ADDR = 0xC2; // Jump if Z == 1
    static constexpr Byte JC_ADDR = 0xDA; // Jump if C == 1
    static constexpr Byte JNC_ADDR = 0xD2; // Jump if C == 0
    static constexpr Byte JP_ADDR = 0xF2; // Jump if S == 0
    static constexpr Byte JM_ADDR = 0xFA; // Jump if S == 1
    static constexpr Byte JPE_ADDR = 0xEA; // Jump if even parity 
    static constexpr Byte JPO_ADDR = 0xE2; // Jump if odd parity
    static constexpr Byte CALL_ADDR = 0xCD; // Unconditional subroutine call : Return_Address <-- [PC+1], [SP] <-- [SP] - 2, [PC] <-- Address/Label
    static constexpr Byte RET = 0xC9; // Return from subroutine : [PC] <-- Return_Address, SP <-- [SP] + 2 (?)
    static constexpr Byte RST = 0xC7; // One-word CALL instruction : [PC] <-- memory[SP], [PC] <-- Restart_Location (?)

    /* Stack, I/O and Memory Control Group */
    static constexpr Byte IN_PORT = 0xDB; // Input to Accumulator from I/O port : [A] <-- [Port]
    static constexpr Byte OUT_PORT = 0xD3; // Ouput from Accumulator to I/O port : [Port] <-- [A]
    static constexpr Byte PUSH_RP = 0xC5; // Push content of Register pair to Stack
    static constexpr Byte PUSH_PSW = 0xF5; // Push Processor Status Word
    static constexpr Byte POP_RP = 0xC1; // Pop content of Register pair from Stack
    static constexpr Byte POP_RSW = 0xF1; // Pop Processor Status Word
    static constexpr Byte HLT = 0x76; // Halt
    static constexpr Byte XTHL = 0xE3; // Exchange Stack-top with H-L
    static constexpr Byte SPHL = 0xF9; // Move contents of H-L pair to SP
    static constexpr Byte EI = 0xFB; // Enable Interrupts
    static constexpr Byte DI = 0xF3; // Disable Interrupts
    static constexpr Byte SIM = 0x30; // Set Interrupt Masks
    static constexpr Byte RIM = 0x20; // Read Interrupt Masks
    static constexpr Byte NOP = 0x00; // No Operation

};
