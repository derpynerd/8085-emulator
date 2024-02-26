#include "constants.hpp"
#include "exceptions.hpp"
#pragma once

class Memory {
    static constexpr u32 MAX_MEM = 1024 * 64; // Maximum addressable locations = 64kb
    Byte Data[MAX_MEM]; // Every location will be storing 1 byte => 64kB

    public:
    /* Set all memory bits to 0 */
    void Initialize() {
        for(u32 i = 0; i < MAX_MEM; ++i) {
            this->Data[i] = 0;
        }
    }

    /* Read a byte */
    Byte operator[]( u32 Address ) const {
        if (Address > MAX_MEM) { // Assert that Address < MAX_MEM
            throw MemoryOutOfBounds();
        }

        return Data[Address]; // Return byte stored at 'Address'
    }

    /* Return pointer to byte ~ Write a byte */
    Byte& operator[]( u32 Address ) {
        if (Address > MAX_MEM) { // Assert that Address < MAX_MEM
            throw MemoryOutOfBounds();
        }

        return Data[Address]; // Return Address at location
    }

};