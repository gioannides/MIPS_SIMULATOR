#include "error.hpp"
#include <cstdlib> //for std::exit

void checkExec(const std::vector<int32_t>& reg, uint32_t addr){
	if(((addr < ADDR_INSTR) || (addr > (ADDR_INSTR + ADDR_INSTR_L - 1))) && (addr != ADDR_NULL)){
		throw (static_cast<int>(Exception::MEMORY));
	}
	if(addr == ADDR_NULL){
		uint32_t out = reg[2] & 0x000000FF;
		std::exit(out);
	}
}	

void checkRead(uint32_t addr){
	if(((addr < ADDR_INSTR) || (addr > (ADDR_INSTR + ADDR_INSTR_L - 1)))
		&& ((addr < ADDR_DATA) || (addr > (ADDR_DATA + ADDR_DATA_L - 1)))
		&& (addr != ADDR_GETC)){
			throw (static_cast<int>(Exception::MEMORY));
		}
   }	

void checkWrite(uint32_t addr){
	if(((addr < ADDR_DATA || (addr > (ADDR_DATA + ADDR_DATA_L - 1)))) && (addr != ADDR_PUTC)){
		throw (static_cast<int>(Exception::MEMORY));
	}
}


char readChar(){
	char c;
	c = std::getchar();
	if(std::cin.eof()){
		return 0xFF;
	}
	if(!std::cin.good()){
		throw (static_cast<int>(Error::IO));
	}
	return c;
 }	

void writeChar(char c){
	std::putchar(c);
	if(!std::cout.good()){
		throw (static_cast<int>(Error::IO));
	}
  }	
