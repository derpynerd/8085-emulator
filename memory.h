#include "constants.h"
#include "exceptions.h"
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

    /* Read 1 byte */
    Byte operator[]( u32 Address ) const {
        if (Address > MAX_MEM) { // Assert that Address < MAX_MEM
            throw MemoryOutOfBounds();
        }

        return Data[Address]; // Return 1 Byte starting from Address
    }

    /** Testing function **/
    /* Set byte at address to passed value */
    void setByte( u32 Address, Byte Value ) {
        Data[Address] = Value;
    }
    /** Testing function **/

};