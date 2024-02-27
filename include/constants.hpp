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
    static constexpr Byte MVI_R_DAT = 0x3E; // Move Immediate Data to Register : [r] <-- data
    static constexpr Byte MVI_M_DAT = 0x36; // Move Immediate Data to Memory : [M] <-- data
    static constexpr Byte LXI_RP_DAT = 0x01; // Load Register pair Immediate : [rp] <-- data 16 bits, [rh] <-- 8 LSBs of data
    static constexpr Byte LDA_ADDR = 0x3A; // Load Accumulator Direct : [A] <-- [addr]
    static constexpr Byte STA_ADDR = 0x32; // Store Accumulator Direct : [addr] <-- [A]
    static constexpr Byte LHLD_ADDR = 0x2A; // Load H-L pair Direct : [L] <-- [addr], [H] <-- [addr+1]
    static constexpr Byte SHLD_ADDR = 0x22; // Store H-L pair Direct : [addr] <-- [L], [addr+1] <-- [H] 
    static constexpr Byte LDAX_RP = 0x0A; // Load Accumulator Indirect : [A] <-- [[rp]]
    static constexpr Byte STAX_RP = 0x02; // Store Accumulator Indirect : [[rp]] <-- [A]
    static constexpr Byte XCHG = 0xEB; // Exchange data between H-L and D-E pairs : [H-L] <-> [D-E]

    /* Arithmetic Group */
    static constexpr Byte INR_A = 0x3C; // Increment Accumulator
    
    /* Logical Group */

    /* Branch Group */
    static constexpr Byte JMP = 0xC3; // Unconditional Jump

    /* Stack, I/O and Memory Control Group */

};
