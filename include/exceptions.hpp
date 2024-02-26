#include <exception>
#pragma once

class InvalidOpcode : public std::exception {
    virtual const char* what() const throw() {
    return "Invalid Opcode specified";
  }
};

class MemoryOutOfBounds : public std::exception {
    virtual const char* what() const throw() {
        return "Trying to address memory outside of MAX_MEM";
    }
};

class OutOfCycles : public std::exception {
    virtual const char* what() const throw() {
        return "Insufficient clock cycles to execute given instruction";
    }
};