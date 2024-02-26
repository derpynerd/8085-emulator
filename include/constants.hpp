using Byte = unsigned char; // 8 bit
using Word = unsigned short; // 16 bit

using u32 = unsigned int; // 64 bit

class OPCODE {

public:
    /* Opcodes */
    static constexpr Byte LDA_IMM = 0x3A; // Load Accumulator Immediate
    static constexpr Byte INR_A = 0x3C; // Increment Accumulator
    static constexpr Byte JMP = 0xC3; // Unconditional Jump

};
