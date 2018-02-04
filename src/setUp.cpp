#include "setUp.hpp"

void setUp(State& s, const std::string& fileName){

	//Set all the state elements to the correct value
	s.ram.resize(MEM_SIZE);
	s.pc = ADDR_INSTR;
	s.npc = ADDR_INSTR + 1;
	s.reg.resize(32, 0);
	s.Hi = 0;
	s.Lo = 0;

	std::ifstream fileIn(fileName, std::ios::binary | std::ios::ate);

	if(!fileIn.is_open()){
		std::cout << "E: Could not open file" << std::endl;
		std::exit(2);
	}
	else{
		MBlock m;

	    m.size = fileIn.tellg();
	    m.data = new char [m.size];
	    fileIn.seekg (0, std::ios::beg);
	    fileIn.read (m.data, m.size);
	    fileIn.close();

/*
	    std::cout << "Bit read: " << std::endl; //Commented lines are useful for debugging
	    for(int i = 0; i < m.size; i++){
	    	std::bitset<8> temp(m.data[i]);
	    	std::cout << temp << " ";
	    	if(((i + 1) % 4) == 0){
	    		std::cout << std::endl;
	    	}
	    }
*/
	    memToVector(m, s.ram);

	    //Remember to delete the dynamically allocated memory
	    delete[] m.data;

	}
}



void memToVector(const MBlock& m, std::vector<int32_t >& v){
	uint32_t addr = ADDR_INSTR;
	for(int i = 0; i < m.size; i+=4){
		v[addr] = convTo32B(&m.data[i]);
		//The commented lines are useful for debugging
		//std::cout << std::hex << v[addr] << std::endl;
		//std::cout << "ADDR " << addr << std::endl;
		++addr;
	}
}

uint32_t convTo32B(char* in){
		int32_t out(0), temp(0);

		for(int i = 0; i < 4; i++){
			out <<= 8;
			temp = in[i];
			//N.B. This clears the sign extension!
			temp = temp & 0x000000FF;
			out = out | temp;
		}

		return out;
}
