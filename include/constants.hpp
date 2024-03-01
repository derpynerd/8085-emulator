#pragma once

using Byte = unsigned char; // 8 bit
using Word = unsigned short; // 16 bit

using u32 = unsigned int; // 64 bit

class OPCODE {

public:

    static constexpr Byte NOP = 0x00; // No Operation
    static constexpr Byte LXI_B = 0x01; // Load Register pair immediate : [BC] <-- data 16 bits, [rh] <-- 8 LSBs of data
    static constexpr Byte STAX_B = 0x02; // Store Accumulator Indirect : [[BC]] <-- [A]
    static constexpr Byte INX_B = 0x03; // Increment Register pair : [BC] <-- [BC] + 1
    static constexpr Byte INR_B = 0x04; // Increment Register : [B] <-- [B] + 1
    static constexpr Byte DCR_B = 0x05; // Decrement Register : [B] <-- [B] - 1
    static constexpr Byte MVI_B_DAT = 0x06; // Move immediate data to Register : [B] <-- data
    static constexpr Byte RLC = 0x07; // Rotate Accumulator left : [An+1] <-- [An], [A0] <-- [A7], [CS] <--[A7]
    static constexpr Byte UNDEFINED_1 = 0x08;
    static constexpr Byte DAD_B = 0x09; // Add Register pair to H-L pair : [H-L] <-- [H-L] + [B-C]
    static constexpr Byte LDAX_B = 0x0A; // Load Accumulator Indirect : [A] <-- [[BC]]
    static constexpr Byte DCX_B = 0x0B; // Decrement Register pair : [BC] <-- [BC] - 1
    static constexpr Byte INR_C = 0x0C; // Increment Register : [C] <-- [C] + 1
    static constexpr Byte DCR_C = 0x0D; // Decrement Register : [C] <-- [C] - 1
    static constexpr Byte MVI_C_DAT = 0x0E; // Move immediate data to Register : [C] <-- data
    static constexpr Byte RRC = 0x0F; // Rotate Accumulator right : [An] <-- [An+1], [CS] <-- [A0], [An] <-- [An+1]

    static constexpr Byte UNDEFINED_2 = 0x10;
    static constexpr Byte LXI_D = 0x11; // Load Register pair immediate : [DE] <-- data 16 bits, [rh] <-- 8 LSBs of data
    static constexpr Byte STAX_D = 0x12; // Store Accumulator Indirect : [[DE]] <-- [A]
    static constexpr Byte INX_D = 0x13; // Increment Register pair : [DE] <-- [DE] + 1
    static constexpr Byte INR_D = 0x14; // Increment Register : [D] <-- [D] + 1
    static constexpr Byte DCR_D = 0x15; // Decrement Register : [D] <-- [D] - 1
    static constexpr Byte MVI_D_DAT = 0x16; // Move immediate data to Register : [D] <-- data
    static constexpr Byte RAL = 0x17; // Rotate Accumulator left through carry : [An+1] <-- [An], [CS] <-- [A7], [A0] <-- [CS]
    static constexpr Byte UNDEFINED_3 = 0x18;
    static constexpr Byte DAD_D = 0x19; // Add Register pair to H-L pair : [H-L] <-- [H-L] + [D-E]
    static constexpr Byte LDAX_D = 0x1A; // Load Accumulator Indirect : [A] <-- [[DE]]
    static constexpr Byte DCX_D = 0x1B; // Decrement Register pair : [DE] <-- [DE] - 1
    static constexpr Byte INR_E = 0x1C; // Increment Register : [E] <-- [E] + 1
    static constexpr Byte DCR_E = 0x1D; // Decrement Register : [E] <-- [E] - 1
    static constexpr Byte MVI_E_DAT = 0x1E; // Move immediate data to Register : [E] <-- data
    static constexpr Byte RAR = 0x1F; // Rotate Accumulator right through carry :  [An] <-- [An+1], [CS] <-- [A0], [A7] <-- [CS]

    static constexpr Byte RIM = 0x20; // Read Interrupt Masks
    static constexpr Byte LXI_B = 0x21; // Load Register pair immediate : [HL] <-- data 16 bits, [rh] <-- 8 LSBs of data
    static constexpr Byte SHLD_ADDR = 0x22; // Store H-L pair Direct : Memory[addr] <-- [L], [addr+1] <-- [H] 
    static constexpr Byte INX_H = 0x23; // Increment Register pair : [HL] <-- [HL] + 1
    static constexpr Byte INR_H = 0x24; // Increment Register : [H] <-- [H] + 1
    static constexpr Byte DCR_H = 0x25; // Decrement Register : [H] <-- [H] - 1
    static constexpr Byte MVI_H_DAT = 0x26; // Move immediate data to Register : [H] <-- data
    static constexpr Byte DAA = 0x27; // Decimal adjust Accumulator
    static constexpr Byte UNDEFINED_4 = 0x28;
    static constexpr Byte DAD_H = 0x29; // Add Register pair to H-L pair : [H-L] <-- [H-L] + [H-L]
    static constexpr Byte LHLD_ADDR = 0x2A; // Load H-L pair Direct : [L] <-- Memory[addr], [H] <-- [addr+1]
    static constexpr Byte DCX_H = 0x2B; // Decrement Register pair : [HL] <-- [HL] - 1
    static constexpr Byte INR_L = 0x2C; // Increment Register : [L] <-- [L] + 1
    static constexpr Byte DCR_L = 0x2D; // Decrement Register : [L] <-- [L] - 1
    static constexpr Byte MVI_L_DAT = 0x2E; // Move immediate data to Register : [L] <-- data
    static constexpr Byte CMA = 0x2F; // Complement the Accumulator : [A] <-- [A]

    static constexpr Byte SIM = 0x30; // Set Interrupt Masks
    static constexpr Byte LXI_SP = 0x31; // ?????????
    static constexpr Byte STA_ADDR = 0x32; // Store Accumulator Direct : Memory[addr] <-- [A]
    static constexpr Byte INX_SP = 0x33; // ??????????
    static constexpr Byte INR_M = 0x34; // Increment value in Memory : [[H-L]] <-- [[H-L]] + 1
    static constexpr Byte DCR_M = 0x35; // Decrement value in Memory : [[H-L]] <-- [[H-L]] - 1
    static constexpr Byte MVI_M_DAT = 0x36; // Move immediate data to Memory : [M] <-- data
    static constexpr Byte STC = 0x37; // Set carry status : [CS] <-- 1
    static constexpr Byte UNDEFINED_5 = 0x38;
    static constexpr Byte DAD_SP = 0x39; // ?????????
    static constexpr Byte LDA_ADDR = 0x3A; // Load Accumulator Direct : [A] <-- Memory[addr]
    static constexpr Byte DCX_SP = 0x3B; // ?????????
    static constexpr Byte INR_A = 0x3C; // Increment Accumulator  : [A] <-- [A] + 1
    static constexpr Byte DCR_A = 0x3D; // Decrement Accumulator  : [A] <-- [A] - 1
    static constexpr Byte MVI_A_DAT = 0x3E; // Move immediate data to Accumulator : [A] <-- data
    static constexpr Byte CMC = 0x3F; // Complement the carry status : [CS] <-- [CS]

    static constexpr Byte MOV_B_B = 0x40; // Move data from Register 2 to Register 1 : [B] <-- [B]
    static constexpr Byte MOV_B_C = 0x41; // Move data from Register 2 to Register 1 : [B] <-- [C]
    static constexpr Byte MOV_B_D = 0x42; // Move data from Register 2 to Register 1 : [B] <-- [D]
    static constexpr Byte MOV_B_E = 0x43; // Move data from Register 2 to Register 1 : [B] <-- [E]
    static constexpr Byte MOV_B_H = 0x44; // Move data from Register 2 to Register 1 : [B] <-- [H]
    static constexpr Byte MOV_B_L = 0x45; // Move data from Register 2 to Register 1 : [B] <-- [L]
    static constexpr Byte MOV_B_M = 0x46; // Move data from Memory to Register : [B] <-- [M]
    static constexpr Byte MOV_B_A = 0x47; // Move data from Register 2 to Register 1 : [B] <-- [A]
    static constexpr Byte MOV_C_B = 0x48; // Move data from Register 2 to Register 1 : [C] <-- [B]
    static constexpr Byte MOV_C_C = 0x49; // Move data from Register 2 to Register 1 : [C] <-- [C]
    static constexpr Byte MOV_C_D = 0x4A; // Move data from Register 2 to Register 1 : [C] <-- [D]
    static constexpr Byte MOV_C_E = 0x4B; // Move data from Register 2 to Register 1 : [C] <-- [E]
    static constexpr Byte MOV_C_H = 0x4C; // Move data from Register 2 to Register 1 : [C] <-- [H]
    static constexpr Byte MOV_C_L = 0x4D; // Move data from Register 2 to Register 1 : [C] <-- [L]
    static constexpr Byte MOV_C_M = 0x4E; // Move data from Memory to Register : [C] <-- [M]
    static constexpr Byte MOV_C_A = 0x4F; // Move data from Register 2 to Register 1 : [C] <-- [A]
    
    static constexpr Byte MOV_D_B = 0x50; // Move data from Register 2 to Register 1 : [D] <-- [B]
    static constexpr Byte MOV_D_C = 0x51; // Move data from Register 2 to Register 1 : [D] <-- [C]
    static constexpr Byte MOV_D_D = 0x52; // Move data from Register 2 to Register 1 : [D] <-- [D]
    static constexpr Byte MOV_D_E = 0x53; // Move data from Register 2 to Register 1 : [D] <-- [E]
    static constexpr Byte MOV_D_H = 0x54; // Move data from Register 2 to Register 1 : [D] <-- [H]
    static constexpr Byte MOV_D_L = 0x55; // Move data from Register 2 to Register 1 : [D] <-- [L]
    static constexpr Byte MOV_D_M = 0x56; // Move data from Memory to Register : [D] <-- [M]
    static constexpr Byte MOV_D_A = 0x57; // Move data from Register 2 to Register 1 : [D] <-- [A]
    static constexpr Byte MOV_E_B = 0x58; // Move data from Register 2 to Register 1 : [E] <-- [B]
    static constexpr Byte MOV_E_C = 0x59; // Move data from Register 2 to Register 1 : [E] <-- [C]
    static constexpr Byte MOV_E_D = 0x5A; // Move data from Register 2 to Register 1 : [E] <-- [D]
    static constexpr Byte MOV_E_E = 0x5B; // Move data from Register 2 to Register 1 : [E] <-- [E]
    static constexpr Byte MOV_E_H = 0x5C; // Move data from Register 2 to Register 1 : [E] <-- [H]
    static constexpr Byte MOV_E_L = 0x5D; // Move data from Register 2 to Register 1 : [E] <-- [L]
    static constexpr Byte MOV_E_M = 0x5E; // Move data from Memory to Register : [E] <-- [M]
    static constexpr Byte MOV_E_A = 0x5F; // Move data from Register 2 to Register 1 : [E] <-- [A]
    
    static constexpr Byte MOV_H_B = 0x60; // Move data from Register 2 to Register 1 : [H] <-- [B]
    static constexpr Byte MOV_H_C = 0x61; // Move data from Register 2 to Register 1 : [H] <-- [C]
    static constexpr Byte MOV_H_D = 0x62; // Move data from Register 2 to Register 1 : [H] <-- [D]
    static constexpr Byte MOV_H_E = 0x63; // Move data from Register 2 to Register 1 : [H] <-- [E]
    static constexpr Byte MOV_H_H = 0x64; // Move data from Register 2 to Register 1 : [H] <-- [H]
    static constexpr Byte MOV_H_L = 0x65; // Move data from Register 2 to Register 1 : [H] <-- [L]
    static constexpr Byte MOV_H_M = 0x66; // Move data from Memory to Register : [H] <-- [M]
    static constexpr Byte MOV_H_A = 0x67; // Move data from Register 2 to Register 1 : [H] <-- [A]
    static constexpr Byte MOV_L_B = 0x68; // Move data from Register 2 to Register 1 : [L] <-- [B]
    static constexpr Byte MOV_L_C = 0x69; // Move data from Register 2 to Register 1 : [L] <-- [C]
    static constexpr Byte MOV_L_D = 0x6A; // Move data from Register 2 to Register 1 : [L] <-- [D]
    static constexpr Byte MOV_L_E = 0x6B; // Move data from Register 2 to Register 1 : [L] <-- [E]
    static constexpr Byte MOV_L_H = 0x6C; // Move data from Register 2 to Register 1 : [L] <-- [H]
    static constexpr Byte MOV_L_L = 0x6D; // Move data from Register 2 to Register 1 : [L] <-- [L]
    static constexpr Byte MOV_L_M = 0x6E; // Move data from Memory to Register : [L] <-- [M]
    static constexpr Byte MOV_L_A = 0x6F; // Move data from Register 2 to Register 1 : [L] <-- [A]
    
    static constexpr Byte MOV_M_B = 0x70; // Move data from Register 2 to Register 1 : [M] <-- [B]
    static constexpr Byte MOV_M_C = 0x71; // Move data from Register 2 to Register 1 : [M] <-- [C]
    static constexpr Byte MOV_M_D = 0x72; // Move data from Register 2 to Register 1 : [M] <-- [D]
    static constexpr Byte MOV_M_E = 0x73; // Move data from Register 2 to Register 1 : [M] <-- [E]
    static constexpr Byte MOV_M_H = 0x74; // Move data from Register 2 to Register 1 : [M] <-- [H]
    static constexpr Byte MOV_M_L = 0x75; // Move data from Register 2 to Register 1 : [M] <-- [L]
    static constexpr Byte HLT = 0x76; // Halt
    static constexpr Byte MOV_M_A = 0x77; // Move data from Register 2 to Register 1 : [M] <-- [A]
    static constexpr Byte MOV_A_B = 0x78; // Move data from Register 2 to Register 1 : [A] <-- [D]
    static constexpr Byte MOV_A_C = 0x79; // Move data from Register 2 to Register 1 : [A] <-- [C]
    static constexpr Byte MOV_A_D = 0x7A; // Move data from Register 2 to Register 1 : [A] <-- [D]
    static constexpr Byte MOV_A_E = 0x7B; // Move data from Register 2 to Register 1 : [A] <-- [E]
    static constexpr Byte MOV_A_H = 0x7C; // Move data from Register 2 to Register 1 : [A] <-- [H]
    static constexpr Byte MOV_A_L = 0x7D; // Move data from Register 2 to Register 1 : [A] <-- [L]
    static constexpr Byte MOV_A_M = 0x7E; // Move data from Memory to Register : [A] <-- [M]
    static constexpr Byte MOV_A_A = 0x7F; // Move data from Register 2 to Register 1 : [A] <-- [A]
    
    static constexpr Byte ADD_B = 0x80; // Add Register to Accumulator : [A] <-- [A] + [B]
    static constexpr Byte ADD_C = 0x81; // Add Register to Accumulator : [A] <-- [A] + [C]
    static constexpr Byte ADD_D = 0x82; // Add Register to Accumulator : [A] <-- [A] + [D]
    static constexpr Byte ADD_E = 0x83; // Add Register to Accumulator : [A] <-- [A] + [E]
    static constexpr Byte ADD_H = 0x84; // Add Register to Accumulator : [A] <-- [A] + [H]
    static constexpr Byte ADD_L = 0x85; // Add Register to Accumulator : [A] <-- [A] + [L]
    static constexpr Byte ADD_M = 0x86; // Add Memory to Accumulator : [A] <-- [A] + [[H-L]]
    static constexpr Byte ADD_A = 0x87; // Add Register to Accumulator : [A] <-- [A] + [A]
    static constexpr Byte ADC_B = 0x88; // Add Register with carry to Accumulator : [A] <-- [A] + [B] + [CS]
    static constexpr Byte ADC_C = 0x89; // Add Register with carry to Accumulator : [A] <-- [A] + [C] + [CS]
    static constexpr Byte ADC_D = 0x8A; // Add Register with carry to Accumulator : [A] <-- [A] + [D] + [CS]
    static constexpr Byte ADC_E = 0x8B; // Add Register with carry to Accumulator : [A] <-- [A] + [E] + [CS]
    static constexpr Byte ADC_H = 0x8C; // Add Register with carry to Accumulator : [A] <-- [A] + [H] + [CS]
    static constexpr Byte ADC_L = 0x8D; // Add Register with carry to Accumulator : [A] <-- [A] + [L] + [CS]
    static constexpr Byte ADC_M = 0x8E; // Add Memory with carry to Accumulator : [A] <-- [A] + [[H-L]] + [CS]
    static constexpr Byte ADC_A = 0x8F; // Add Register with carry to Accumulator : [A] <-- [A] + [A] + [CS]
    
    static constexpr Byte SUB_B = 0x90; // Subtract Register from Accumulator : [A] <-- [A] – [B]
    static constexpr Byte SUB_C = 0x91; // Subtract Register from Accumulator : [A] <-- [A] – [C]
    static constexpr Byte SUB_D = 0x92; // Subtract Register from Accumulator : [A] <-- [A] – [D]
    static constexpr Byte SUB_E = 0x93; // Subtract Register from Accumulator : [A] <-- [A] – [E]
    static constexpr Byte SUB_H = 0x94; // Subtract Register from Accumulator : [A] <-- [A] – [H]
    static constexpr Byte SUB_L = 0x95; // Subtract Register from Accumulator : [A] <-- [A] – [L]
    static constexpr Byte SUB_M = 0x96; // Subtract Memory from Accumulator : [A] <-- [A] – [[H-L]]
    static constexpr Byte SUB_A = 0x97; // Subtract Accumulator from Accumulator : [A] <-- [A] – [A]
    static constexpr Byte SBB_B = 0x98; // Subtract Register from Accumulator with borrow : [A] <-- [A] – [B] – [CS]
    static constexpr Byte SBB_C = 0x99; // Subtract Register from Accumulator with borrow : [A] <-- [A] – [C] – [CS]
    static constexpr Byte SBB_D = 0x9A; // Subtract Register from Accumulator with borrow : [A] <-- [A] – [D] – [CS]
    static constexpr Byte SBB_E = 0x9B; // Subtract Register from Accumulator with borrow : [A] <-- [A] – [E] – [CS]
    static constexpr Byte SBB_H = 0x9C; // Subtract Register from Accumulator with borrow : [A] <-- [A] – [H] – [CS]
    static constexpr Byte SBB_L = 0x9D; // Subtract Register from Accumulator with borrow : [A] <-- [A] – [L] – [CS]
    static constexpr Byte SBB_M = 0x9E; // Subtract Memory from Accumulator with borrow : [A] <-- [A] – [M] – [CS]
    static constexpr Byte SBB_A = 0x9F; // Subtract Accumulator from Accumulator with borrow : [A] <-- [A] – [A] – [CS]
    
    static constexpr Byte ANA_B = 0xA0; // AND Register with Accumulator : [A] <-- [A] ^ [B]
    static constexpr Byte ANA_C = 0xA1; // AND Register with Accumulator : [A] <-- [A] ^ [C]
    static constexpr Byte ANA_D = 0xA2; // AND Register with Accumulator : [A] <-- [A] ^ [D]
    static constexpr Byte ANA_E = 0xA3; // AND Register with Accumulator : [A] <-- [A] ^ [E]
    static constexpr Byte ANA_H = 0xA4; // AND Register with Accumulator : [A] <-- [A] ^ [H]
    static constexpr Byte ANA_L = 0xA5; // AND Register with Accumulator : [A] <-- [A] ^ [L]
    static constexpr Byte ANA_M = 0xA6; // AND Memory with Accumulator : [A] <-- [A] ^ [[H-L]]
    static constexpr Byte ANA_A = 0xA7; // AND Register with Accumulator : [A] <-- [A] ^ [A]
    static constexpr Byte XRA_B = 0xA8; // XOR Register with Accumulator : [A] <-- [A] V [B]
    static constexpr Byte XRA_C = 0xA9; // XOR Register with Accumulator : [A] <-- [A] V [C]
    static constexpr Byte XRA_D = 0xAA; // XOR Register with Accumulator : [A] <-- [A] V [D]
    static constexpr Byte XRA_E = 0xAB; // XOR Register with Accumulator : [A] <-- [A] V [E]
    static constexpr Byte XRA_H = 0xAC; // XOR Register with Accumulator : [A] <-- [A] V [H]
    static constexpr Byte XRA_L = 0xAD; // XOR Register with Accumulator : [A] <-- [A] V [L]
    static constexpr Byte XRA_M = 0xAE; // XOR Memory with Accumulator : [A] <-- [A] V [[H-L]]
    static constexpr Byte XRA_A = 0xAF; // XOR Accumulator with Accumulator : [A] <-- [A] V [A]
    
    static constexpr Byte ORA_B = 0xB0; // OR Register with Accumulator : [A] <-- [A] v [B]
    static constexpr Byte ORA_C = 0xB1; // OR Register with Accumulator : [A] <-- [A] v [C]
    static constexpr Byte ORA_D = 0xB2; // OR Register with Accumulator : [A] <-- [A] v [D]
    static constexpr Byte ORA_E = 0xB3; // OR Register with Accumulator : [A] <-- [A] v [E]
    static constexpr Byte ORA_H = 0xB4; // OR Register with Accumulator : [A] <-- [A] v [H]
    static constexpr Byte ORA_L = 0xB5; // OR Register with Accumulator : [A] <-- [A] v [L]
    static constexpr Byte ORA_M = 0xB6; // OR Memory with Accumulator : [A] <-- [A] v [M]
    static constexpr Byte ORA_A = 0xB7; // OR Register with Accumulator : [A] <-- [A] v [A]
    static constexpr Byte CMP_B = 0xB8; // Compare Register with Accumulator : [A] -- [B]
    static constexpr Byte CMP_C = 0xB9; // Compare Register with Accumulator : [A] -- [C]
    static constexpr Byte CMP_D = 0xBA; // Compare Register with Accumulator : [A] -- [D]
    static constexpr Byte CMP_E = 0xBB; // Compare Register with Accumulator : [A] -- [E]
    static constexpr Byte CMP_H = 0xBC; // Compare Register with Accumulator : [A] -- [H]
    static constexpr Byte CMP_L = 0xBD; // Compare Register with Accumulator : [A] -- [L]
    static constexpr Byte CMP_M = 0xBE; // Compare Memory with Accumulator : [A] -- [[H-L]]
    static constexpr Byte CMP_A = 0xBF; // Compare Register with Accumulator : [A] -- [A]
    
    static constexpr Byte RNZ = 0xC0; // ????????
    static constexpr Byte POP_B = 0xC1; // Pop  of Register pair BC from Stack
    static constexpr Byte JNZ_ADDR = 0xC2; // Jump if Z == 1
    static constexpr Byte JMP_ADDR = 0xC3; // Unconditional jump : [PC] <-- Address/Label
    static constexpr Byte CNZ_ADDR = 0xC4; // ????????
    static constexpr Byte PUSH_B = 0xC5; // Push  of Register pair BC to Stack
    static constexpr Byte ADI_DAT = 0xC6; // Add immediate Data to Accumulator : [A] <-- [A] + data
    static constexpr Byte RST_0 = 0xC7; // One-word CALL instruction : [PC] <-- memory[SP], [PC] <-- Restart_Location (?)
    static constexpr Byte RZ = 0xC8; // ?????????
    static constexpr Byte RET = 0xC9; // Return from subroutine : [PC] <-- Return_Address, SP <-- [SP] + 2 (?)
    static constexpr Byte JZ_ADDR = 0xCA; // Jump if Z == 0
    static constexpr Byte UNDEFINED_6 = 0xCB;
    static constexpr Byte CZ_LABEL = 0xCC; // ?????????
    static constexpr Byte CALL_LABEL = 0xCD; // Unconditional subroutine call : Return_Address <-- [PC+1], [SP] <-- [SP] - 2, [PC] <-- Address/Label
    static constexpr Byte ACI_DAT = 0xCE; // Add with carry immediate data to Accumulator : [A] <-- [A] + data + [CS]
    static constexpr Byte RST_1 = 0xCF; // One-word CALL instruction : [PC] <-- memory[SP], [PC] <-- Restart_Location (?)
    
    static constexpr Byte RNC = 0xD0; // ???????
    static constexpr Byte POP_D = 0xD1; // Pop  of Register pair DE from Stack
    static constexpr Byte JNC_ADDR = 0xD2; // Jump if C == 0
    static constexpr Byte OUT_PORT = 0xD3; // Ouput from Accumulator to I/O port : [Port] <-- [A]F
    static constexpr Byte CNC_ADDR = 0xD4; // ????????
    static constexpr Byte PUSH_D = 0xD5; // Push  of Register pair DE to Stack
    static constexpr Byte SUI_DAT = 0xD6; // Subtract immediate data from Accumulator : [A] <-- [A] – data
    static constexpr Byte RST_2 = 0xD7; // One-word CALL instruction : [PC] <-- memory[SP], [PC] <-- Restart_Location (?)
    static constexpr Byte RC = 0xD8; // ????????
    static constexpr Byte UNDEFINED_7 = 0xD9;
    static constexpr Byte JC_ADDR = 0xDA; // Jump if C == 1
    static constexpr Byte IN_PORT = 0xDB; // Input to Accumulator from I/O port : [A] <-- [Port]
    static constexpr Byte CC_ADDR = 0xDC; // ???????
    static constexpr Byte UNDEFINED_8 = 0xDD;
    static constexpr Byte SBI_DAT = 0xDE; // Subtract immediate data from Accumulator with borrow : [A] <-- [A] – data - [CS]
    static constexpr Byte RST_3 = 0xDF; // One-word CALL instruction : [PC] <-- memory[SP], [PC] <-- Restart_Location (?)
    
    static constexpr Byte RPO = 0xE0; // ????????
    static constexpr Byte POP_H = 0xE1; // Pop  of Register pair HL from Stack
    static constexpr Byte JPO_ADDR = 0xE2; // Jump if odd parity
    static constexpr Byte XTHL = 0xE3; // Exchange Stack-top with H-L
    static constexpr Byte CPO_LABEL = 0xE4; // ???????
    static constexpr Byte PUSH_H = 0xE5; // Push  of Register pair HL to Stack
    static constexpr Byte ANI_DAT = 0xE6; // AND immediate data with Accumulator : [A] <-- [A] ^ data
    static constexpr Byte RST_4 = 0xE7; // One-word CALL instruction : [PC] <-- memory[SP], [PC] <-- Restart_Location (?)
    static constexpr Byte RPE = 0xE8; // ?????????
    static constexpr Byte PCHL = 0xE9; // ?????????
    static constexpr Byte JPE_ADDR = 0xEA; // Jump if even parity 
    static constexpr Byte XCHG = 0xEB; // Exchange data between H-L and D-E pairs : [H-L] <-> [D-E]
    static constexpr Byte CPE_LABEL = 0xEC; // ???????
    static constexpr Byte UNDEFINED_9 = 0xED;
    static constexpr Byte XRI_DAT = 0xEE; // XOR immediate data with Accumulator : [A] <-- [A] V data
    static constexpr Byte RST_5 = 0xEF; // One-word CALL instruction : [PC] <-- memory[SP], [PC] <-- Restart_Location (?)
    
    static constexpr Byte RP = 0xF0; // ?????????
    static constexpr Byte POP_PSW = 0xF1; // Pop Processor Status Word
    static constexpr Byte JP_ADDR = 0xF2; // Jump if S == 0
    static constexpr Byte DI = 0xF3; // Disable Interrupts 
    static constexpr Byte CP_LABEL = 0xF4; // ????????
    static constexpr Byte PUSH_PSW = 0xF5; // Push Processor Status Word
    static constexpr Byte ORI_DAT = 0xF6; // OR immediate data with Accumulator : [A] <-- [A] v data
    static constexpr Byte RST_6 = 0xF7; // One-word CALL instruction : [PC] <-- memory[SP], [PC] <-- Restart_Location (?)
    static constexpr Byte RM = 0xF8; // ?????????
    static constexpr Byte SPHL = 0xF9; // Move contents of HL pair to SP
    static constexpr Byte JM_ADDR = 0xFA; // Jump if S == 1
    static constexpr Byte EI = 0xFB; // Enable Interrupts
    static constexpr Byte CM_LABEL = 0xFC; // ????????
    static constexpr Byte UNDEFINED_10 = 0xFD;
    static constexpr Byte CPI_DAT = 0xFE; // Compare immediate data with Accumulator : [A] -- data
    static constexpr Byte RST_7 = 0xFF; // One-word CALL instruction : [PC] <-- memory[SP], [PC] <-- Restart_Location (?)

};
