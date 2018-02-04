#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <cstdlib> //for std::exit
#include <cstdint>
#include "setUp.hpp"

//This header file will include all the functions we need for error checking

//These "check" functions take as input the address you want to verify that
//you have the specific rights to and if you do not it will exit with the 
//memory exception code (-11)

void checkWrite(uint32_t addr);
void checkRead(uint32_t addr);

//This function will also terminate the program with the appropriate exit code
//if addr = 0
void checkExec(const std::vector<int32_t>&, uint32_t addr);

//This functions should be called if the binary read/writes to the corresponding
//address. They also handle errors
char readChar();
void writeChar(char c);

//This enum will include both Exception and Error codes
//The Enumerator will add clarity to the simulator code
enum class Exception{
	ARITHMETIC = -10,
	MEMORY = -11,
	INSTRUCTION = -12,	
};

enum class Error{
	INTERNAL = -20,
	IO = -21
};

#endif
