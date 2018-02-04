#include "I_functions.hpp"
using namespace std;

void i_type(State& mips_state, bool& executed){
	if(!executed){
		uint32_t instr = mips_state.ram[mips_state.pc];

		uint32_t opcode = (instr & 0xFC000000) >> 26;
		uint32_t rs = (instr & 0x03E00000) >> 21;
		uint32_t rt= (instr & 0x001F0000) >> 16;
		int32_t immediate = instr & 0x0000FFFF;

		//In our case BranchAddr = SignExtImm;

		int32_t SignExtImm;

		if(immediate >> 15){
			SignExtImm = immediate | 0xFFFF0000;
		}
		else{
			SignExtImm = immediate;
		}

 
		switch(opcode){
			case 0x00000008:
				addi(mips_state, rs, rt, SignExtImm);
				executed = true;
				return;
			case 0x00000009:
				addiu(mips_state, rs, rt, SignExtImm);
				executed = true;
				return;
			case 0x0000000C:
				andi(mips_state, rs, rt, immediate);
				executed = true;
				return;
			case 0x00000004:
				beq(mips_state, rs, rt, SignExtImm);
				executed = true;
				return;
			case 0x00000005:
				bne(mips_state, rs, rt, SignExtImm);
				executed = true;
				return;
			case 0x00000024:
				lbu(mips_state, rs, rt, SignExtImm);
				executed = true;
				return;
			case 0x00000020:
				lb(mips_state, rs, rt, SignExtImm);
				executed = true;
				return;
			case 0x00000025:
				lhu(mips_state, rs, rt, SignExtImm);
				executed = true;
				return;
			case 0x00000021:
				lh(mips_state, rs, rt, SignExtImm);
				executed = true;
				return;
			case 0x0000000F:
				lui(mips_state, rs, rt, immediate);
				executed = true;
				return;
			case 0x00000023:
				lw(mips_state, rs, rt, SignExtImm);
				executed = true;
				return;
			case 0x00000022:
				lwl(mips_state, rs, rt, SignExtImm);
				executed = true;
				return;
			case 0x00000026:
				lwr(mips_state, rs, rt, SignExtImm);
				executed = true;
				return;
			case 0x00000028:
				sb(mips_state, rs, rt, SignExtImm);
				executed = true;
				return;
			case 0x00000029:
				sh(mips_state, rs, rt, SignExtImm);
				executed = true;
				return;
			case 0x0000002B:
				sw(mips_state, rs, rt, SignExtImm);
				executed = true;
				return;
			case 0x0000000A:
				slti(mips_state, rs, rt, SignExtImm);
				executed = true;
				return;
			case 0x0000000B:
				sltiu(mips_state, rs, rt, SignExtImm);
				executed = true;
				return;
			case 0x0000000E:
				xori(mips_state, rs, rt, immediate);
				executed = true;
				return;
			case 0x0000000D:
				ori(mips_state, rs, rt, immediate);
				executed = true;
				return;
			case 0x00000007:
				bgtz(mips_state, rs, rt, SignExtImm);
				executed = true;
				return;
			case 0x00000006:
				blez(mips_state, rs, rt, SignExtImm);
				executed = true;
				return;
			case 0x00000001:
				bdecoder(mips_state, rs, rt, SignExtImm);
				executed = true;
				return;
			default:
				executed = false;
				return;
		}
	}	
}


void addi(State& mips_state, uint32_t rs, uint32_t rt, int32_t SignExtImm){
		int32_t temp = mips_state.reg[rs];
		if (((temp < 0) && (SignExtImm < 0) && (temp + SignExtImm >= 0)) || ((temp > 0) && (SignExtImm > 0) && (temp + SignExtImm <= 0))){
			throw (static_cast<int>(Exception::ARITHMETIC));
		}
		else {
			mips_state.reg[rt] = temp + SignExtImm;
		}

		++mips_state.npc;
}

void addiu(State& mips_state, uint32_t rs, uint32_t rt, int32_t SignExtImm){
	mips_state.reg[rt] = static_cast<uint32_t>(static_cast<uint32_t>(mips_state.reg[rs]) + SignExtImm);

	++mips_state.npc;
}
	
void andi(State& mips_state, uint32_t rs, uint32_t rt, int32_t immediate){
	int32_t temp = mips_state.reg[rs];
	mips_state.reg[rt] = temp & immediate;

	++mips_state.npc;
}

void beq(State& mips_state, uint32_t rs, uint32_t rt, int32_t SignExtImm){
	if(mips_state.reg[rt] == mips_state.reg[rs]){
		mips_state.npc += SignExtImm;
	}
	else{
		++mips_state.npc;
	}
}

void bne(State& mips_state, uint32_t rs, uint32_t rt, int32_t SignExtImm){
	if(mips_state.reg[rt] != mips_state.reg[rs]){
		mips_state.npc += SignExtImm;
	}
	else{
		++mips_state.npc;
	}
}

void lbu(State& mips_state, uint32_t rs, uint32_t rt, int32_t SignExtImm){
		uint32_t addr = static_cast<uint32_t>(SignExtImm + mips_state.reg[rs]);
		checkRead(static_cast<int>(addr / 4));

		if((addr / 4) == ADDR_GETC){
			if((addr % 4) != 3){
				throw (static_cast<int>(Exception::MEMORY));
			}
			else{
				char c = readChar();
				if(c == -1){
					mips_state.reg[rt] = 0xFFFFFFFF; //If we have EOF set rt to -1
					return;
				}
				else{
					mips_state.reg[rt] = c & 0x000000FF;
					return;
				}	
			}
		}


		switch(addr % 4){
			case 0: mips_state.reg[rt] = ((mips_state.ram[static_cast<int>(addr /4)] & 0xFF000000) >> 24) & 0x000000FF;
					break;
			case 1: mips_state.reg[rt] = (mips_state.ram[static_cast<int>(addr /4)] & 0x00FF0000) >> 16;
					break;
			case 2: mips_state.reg[rt] = (mips_state.ram[static_cast<int>(addr /4)] & 0x0000FF00) >> 8;
					break;
			case 3: mips_state.reg[rt] = (mips_state.ram[static_cast<int>(addr /4)] & 0x000000FF);
					break;
			default: break;
		}

	++mips_state.npc;
}

void lb(State& mips_state, uint32_t rs, uint32_t rt, int32_t SignExtImm){
		uint32_t addr = static_cast<uint32_t>(SignExtImm + mips_state.reg[rs]);
		checkRead(static_cast<int>(addr / 4));

		if((addr / 4) == ADDR_GETC){
			if((addr % 4) != 3){
				throw (static_cast<int>(Exception::MEMORY));
			}
			else{
				char c = readChar();
				if(c == -1){
					mips_state.reg[rt] = 0xFFFFFFFF; //If we have EOF set rt to -1
					return;
				}
				else{
					mips_state.reg[rt] = c & 0x000000FF;
					return;
				}
			}
		}	

		switch(addr % 4){
			case 0: mips_state.reg[rt] = ((mips_state.ram[static_cast<int>(addr /4)] & 0xFF000000) >> 24) & 0x000000FF;
					break;
			case 1: mips_state.reg[rt] = (mips_state.ram[static_cast<int>(addr / 4)] & 0x00FF0000) >> 16;
					break;
			case 2: mips_state.reg[rt] = (mips_state.ram[static_cast<int>(addr / 4)] & 0x0000FF00) >> 8;
					break;
			case 3: mips_state.reg[rt] = (mips_state.ram[static_cast<int>(addr / 4)] & 0x000000FF);
					break;
			default: break;
		}

		if(mips_state.reg[rt] >> 7 == 1){
			mips_state.reg[rt] = mips_state.reg[rt] | 0xFFFFFF00;
		}	

		++mips_state.npc;

	}

void lhu(State& mips_state, uint32_t rs, uint32_t rt, int32_t SignExtImm){
		uint32_t addr = static_cast<uint32_t>(SignExtImm + mips_state.reg[rs]);
		checkRead(static_cast<int>(addr / 4));

		if((addr / 4) == ADDR_GETC){
			if((addr % 4) != 2){
				throw (static_cast<int>(Exception::MEMORY));
			}
			else{
				char c = readChar();
				if(c == -1){
					mips_state.reg[rt] = 0xFFFFFFFF; //If we have EOF set rt to -1
					return;
				}
				else{
					mips_state.reg[rt] = c & 0x000000FF;
					return;
				}
			}
		}

		if(addr % 2 != 0){
			throw (static_cast<int>(Exception::MEMORY));
		}
		else{
			switch(addr % 4){
				case 0: mips_state.reg[rt] = ((mips_state.ram[static_cast<int>(addr / 4)] & 0xFFFF0000) >> 16) & 0x0000FFFF;
						break;
				case 2: mips_state.reg[rt] = (mips_state.ram[static_cast<int>(addr / 4)] & 0x0000FFFF);
						break;
			}
		}	
		++mips_state.npc;
	}

	
void lh(State& mips_state, uint32_t rs, uint32_t rt, int32_t SignExtImm){
		uint32_t addr = static_cast<uint32_t>(SignExtImm + mips_state.reg[rs]);
		checkRead(static_cast<int>(addr / 4));

		if((addr / 4) == ADDR_GETC){
			if((addr % 4) != 2){
				throw (static_cast<int>(Exception::MEMORY));
			}
			else{
				char c = readChar();
				if(c == -1){
					mips_state.reg[rt] = 0xFFFFFFFF; //If we have EOF set rt to -1
					return;
				}
				else{
					mips_state.reg[rt] = c & 0x000000FF;
					return;
				}
			}
		}

		if(addr % 2 != 0){
			throw (static_cast<int>(Exception::MEMORY));
		}
		else{
			switch(addr % 4){
				case 0: mips_state.reg[rt] = ((mips_state.ram[static_cast<int>(addr / 4)] & 0xFFFF0000) >> 16) & 0x0000FFFF;
						break;
				case 2: mips_state.reg[rt] = (mips_state.ram[static_cast<int>(addr / 4)] & 0x0000FFFF);
						break;
			}
	
			if((mips_state.reg[rt] >> 15) == 1){
				mips_state.reg[rt] = mips_state.reg[rt] | 0xFFFF0000;
			}
		}

		++mips_state.npc;
	}



void lui(State& mips_state, uint32_t rs, uint32_t rt, int32_t immediate){
		if(rs != 0x00000000){
			throw (static_cast<int>(Exception::INSTRUCTION));
		}
		else{
			immediate = immediate << 16;
			mips_state.reg[rt] = immediate;
		}
		++mips_state.npc;
	}

void lw(State& mips_state , uint32_t rs, uint32_t rt, int32_t SignExtImm){
		uint32_t addr = static_cast<uint32_t>(SignExtImm + mips_state.reg[rs]);

		checkRead(addr / 4);

		if(addr % 4 != 0){
			throw (static_cast<int>(Exception::MEMORY));
		}
		else {
			if(addr / 4 == ADDR_GETC){
				char c = readChar();
				if(c == -1){
					mips_state.reg[rt] = 0xFFFFFFFF; //If we have EOF set rt to -1
					return;
				}
				else{
					mips_state.reg[rt] = c & 0x000000FF;
					return;
				}
			}
			else{
				mips_state.reg[rt] = mips_state.ram[addr / 4];
			}
		}
		++mips_state.npc;
}

void lwl(State& mips_state, uint32_t rs, uint32_t rt, int32_t SignExtImm){
	uint32_t addr = static_cast<uint32_t>(SignExtImm + mips_state.reg[rs]);
	uint32_t temp1(0);

	checkRead(addr / 4);

	switch(addr % 4){
		case 0: mips_state.reg[rt] = mips_state.ram[static_cast<int>(addr / 4)];
				break;
		case 1: temp1 = (mips_state.ram[static_cast<int>(addr / 4)] & 0x00FFFFFF) << 8;
				mips_state.reg[rt] = ((mips_state.reg[rt] & 0x000000FF)| temp1);
				break;
		case 2: temp1 = (mips_state.ram[static_cast<int>(addr / 4)] & 0x0000FFFF) << 16;
				mips_state.reg[rt] = ((mips_state.reg[rt] & 0x0000FFFF)| temp1);
				break;
		case 3: temp1 = (mips_state.ram[static_cast<int>(addr / 4)] & 0x000000FF) << 24;
				mips_state.reg[rt] = ((mips_state.reg[rt] & 0x00FFFFFF)| temp1);
				break;
		default: break;
	}

	++mips_state.npc;
}

void lwr(State& mips_state, uint32_t rs, uint32_t rt, int32_t SignExtImm){
	uint32_t addr = static_cast<uint32_t>(SignExtImm + mips_state.reg[rs]);
	uint32_t temp1(0);

	checkRead(addr / 4);

	switch(addr % 4){
		case 0: temp1 = (((mips_state.ram[static_cast<int>(addr / 4)] & 0xFF000000) >> 24) & 0x000000FF);
				mips_state.reg[rt] = (mips_state.reg[rt] & 0xFFFFFF00) | temp1;
				break;
		case 1: temp1 = (((mips_state.ram[static_cast<int>(addr / 4)] & 0xFFFF0000) >> 16) & 0x0000FFFF);
				mips_state.reg[rt] = (mips_state.reg[rt] & 0xFFFF0000) | temp1;
				break;
		case 2: temp1 = (((mips_state.ram[static_cast<int>(addr / 4)] & 0xFFFFFF00) >> 8) & 0X00FFFFFF);
				mips_state.reg[rt] = (mips_state.reg[rt] & 0xFF000000) | temp1;
				break;
		case 3: mips_state.reg[rt] = mips_state.ram[static_cast<int>(addr / 4)];
				break;
		default: break;
	}

	++mips_state.npc;

}

void ori(State& mips_state, uint32_t rs, uint32_t rt, int32_t immediate){
	mips_state.reg[rt] = mips_state.reg[rs] | immediate;

	++mips_state.npc;
}

void xori(State& mips_state, uint32_t rs, uint32_t rt, int32_t immediate){
	mips_state.reg[rt] = mips_state.reg[rs] ^ immediate;

	++mips_state.npc;
}

void slti(State& mips_state, uint32_t rs, uint32_t rt, int32_t SignExtImm){
	if(mips_state.reg[rs] < SignExtImm){
		mips_state.reg[rt] = 1;
	}
	else{
		mips_state.reg[rt] = 0;
	}

	++mips_state.npc;
}

void sltiu(State& mips_state, uint32_t rs, uint32_t rt, int32_t SignExtImm){
	uint32_t temp = static_cast<uint32_t>(SignExtImm);

	if(uint32_t(mips_state.reg[rs]) < temp){
		mips_state.reg[rt] = 1;
	}
	else{
		mips_state.reg[rt] = 0;
	}

	++mips_state.npc;
}

void sb(State& mips_state, uint32_t rs, uint32_t rt, int32_t SignExtImm){
		uint32_t addr = static_cast<uint32_t>(SignExtImm + mips_state.reg[rs]);
		checkWrite(static_cast<uint32_t>(addr / 4));

		if((addr / 4) == ADDR_PUTC){
			if((addr % 4) != 3){
				throw (static_cast<int>(Exception::MEMORY));
			}
			else{
				writeChar(static_cast<char>(0x000000FF & mips_state.reg[rt]));
				return;
			}
		}

		int32_t temp = mips_state.reg[rt] & 0x000000FF;

		uint32_t index = addr % 4;
		switch(index){
			case 0: mips_state.ram[static_cast<int>(addr / 4)] = (mips_state.ram[static_cast<int>(addr / 4)] & 0x00FFFFFF) | (temp << 24);
					break;
			case 1: mips_state.ram[static_cast<int>(addr / 4)] = (mips_state.ram[static_cast<int>(addr / 4)] & 0xFF00FFFF) | (temp << 16);
					break;
			case 2: mips_state.ram[static_cast<int>(addr / 4)] = (mips_state.ram[static_cast<int>(addr / 4)] & 0xFFFF00FF) | (temp << 8);
					break;
			case 3: mips_state.ram[static_cast<int>(addr / 4)] = (mips_state.ram[static_cast<int>(addr / 4)] & 0xFFFFFF00) | temp;
					break;
			default: break;
		}

		++mips_state.npc;
	}

void sh(State& mips_state, uint32_t rs, uint32_t rt, int32_t SignExtImm){
		uint32_t addr = static_cast<uint32_t>(SignExtImm + mips_state.reg[rs]);
		checkWrite(static_cast<uint32_t>(addr / 4));

		if((addr / 4) == ADDR_PUTC){
			if((addr % 4) != 2){
				throw (static_cast<int>(Exception::MEMORY));
			}
			else{
				writeChar(static_cast<char>(0x000000FF & mips_state.reg[rt]));
				return;
			}
		}

		if(addr % 2){
			throw (static_cast<int>(Exception::MEMORY));
		}

		else{

			switch(addr % 4){
				case 0: mips_state.ram[static_cast<uint32_t>(addr / 4)] = (mips_state.ram[static_cast<uint32_t>(addr / 4)] & 0x0000FFFF) |((mips_state.reg[rt] & 0x0000FFFF) << 16);
						break;
				case 2: mips_state.ram[static_cast<uint32_t>(addr / 4)] = (mips_state.ram[static_cast<uint32_t>(addr / 4)] & 0xFFFF000) | (mips_state.reg[rt] & 0x0000FFFF);
						break;
			}
		}

		++mips_state.npc;
	}

void sw(State& mips_state, uint32_t rs, uint32_t rt, int32_t SignExtImm){
		uint32_t addr = static_cast<uint32_t>(SignExtImm + mips_state.reg[rs]);
		checkWrite(static_cast<uint32_t>(addr / 4));

		if(addr % 4 != 0){
			throw (static_cast<int>(Exception::MEMORY));
		}
		else{
			if(addr / 4 == ADDR_PUTC){
				writeChar(static_cast<char>(0x000000FF & mips_state.reg[rt]));
			}
			mips_state.ram[addr / 4] = mips_state.reg[rt];
		}

		++mips_state.npc;
	}

void bgez(State& mips_state, uint32_t rs, int32_t SignExtImm){
	if(mips_state.reg[rs] >= 0){
		mips_state.npc += SignExtImm;
	}
	else{
		++mips_state.npc;
	}
}

void bgezal(State& mips_state, uint32_t rs, int32_t SignExtImm){
	int32_t temp = mips_state.reg[rs];
	//Regardless of whether the condition is true, the return address needs to be set
	mips_state.reg[31] = (mips_state.pc * 4) + 8;
	if(temp >= 0){
		mips_state.npc += SignExtImm;
	}
	else{
		++mips_state.pc;
	}
}

void bgtz(State& mips_state, uint32_t rs, uint32_t rt, int32_t SignExtImm){
		if(rt != 0x00000000){
			throw (static_cast<int>(Exception::INSTRUCTION));
		}
		else{
			if(mips_state.reg[rs] > 0){
				mips_state.npc += SignExtImm;
			}
			else{
				++mips_state.npc;
			}
		}
	}

void blez(State& mips_state, uint32_t rs, uint32_t rt, int32_t SignExtImm){
		int32_t temp = mips_state.reg[rs];
		if(rt != 0){
			throw (static_cast<int>(Exception::INSTRUCTION));
		}

		else{
			if(temp <= 0x00000000){
				mips_state.npc += SignExtImm;
			}
			else{
				++mips_state.npc;
			}
		}
	}

void bltz(State& mips_state, uint32_t rs, int32_t SignExtImm){
	int32_t temp = mips_state.reg[rs];
	if(temp < 0){
		mips_state.npc += SignExtImm;
	}
	else{
		++mips_state.npc;
	}
}

void bltzal(State& mips_state, uint32_t rs, int32_t SignExtImm){
	int32_t temp = mips_state.reg[rs];
	//Regardless of whether the conditions is true, the return address hars to be set
	mips_state.reg[31] = (mips_state.pc * 4) + 8;
	if(temp < 0){
		mips_state.npc += SignExtImm;
	}
	else{
		++mips_state.npc;
	}
}
	
void bdecoder(State& mips_state, uint32_t rs, uint32_t rt, int32_t SignExtImm){
	switch(rt){
		case 0x00000001:
			bgez(mips_state, rs, SignExtImm);
			return;
		case 0x00000011:
			bgezal(mips_state, rs, SignExtImm);
			return;
		case 0x00000000:
			bltz(mips_state, rs, SignExtImm);
			return;
		case 0x00000010:
			bltzal(mips_state, rs, SignExtImm);
			return;
		default:
			throw (static_cast<int>(Exception::INSTRUCTION));
			return;
	}
}			
