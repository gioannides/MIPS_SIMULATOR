#ifndef SETUP_HPP_
#define SETUP_HPP_

#include <vector>
#include <bitset>
#include <fstream>
#include <iostream>

//These are some GLOBAL CONSTANTS that we will need
//All of these have to be divided by 4 since we are using 32 bits instead of 8.
#define ADDR_NULL 0x00000000
#define ADDR_INSTR 0x04000000 //0x10000000 / 4 = 0x4000000
#define ADDR_INSTR_L 0x00400000
#define ADDR_DATA 0x08000000
#define ADDR_DATA_L 0x01000000
#define ADDR_GETC 0x0C000000
#define ADDR_PUTC 0x0C000001
#define MEM_SIZE 0x0C000002

//This Data Structure represents the current state of the processors "memory"
struct State{
	std::vector<int32_t> ram;
	uint32_t pc;
	uint32_t npc;
	std::vector<int32_t> reg;
	int32_t Hi;
	int32_t Lo;
};

//This Structure is used as a buffer to store all the data from the binary file.
//This buffer is then used to get the individual instructions into the vector.
struct MBlock{
	std::streampos size;
	char* data;
};

//The "setUp" function is the main function used to pass in the binary instructions.
//It calls memToVector and convTo32B
//It also sets the PC to ADDR_INSTR and the rest of the state elements to 0
void setUp(State& s, const std::string& fileName);

//This function passes the instructions in the buffer to a vector.
//It calls convTo32B
void memToVector(const MBlock& m, std::vector<int32_t >& v);

//This functions combines 4 char (i.e. 8 bit values) into a 32bit
uint32_t convTo32B(char* in);

#endif /* SETUP_HPP_ */
