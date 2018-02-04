#ifndef R_TYPE
#define R_TYPE
#include "mips.hpp"
#include "error.hpp"


void r_type(State& mips_state, bool& executed);

void add(State& mips_state, uint32_t rt, uint32_t rs, uint32_t rd);
void addu(State& mips_state, uint32_t rt, uint32_t rs, uint32_t rd);
void And(State& mips_state,uint32_t rt,uint32_t rs, uint32_t rd);
void jr(State& mips_state, uint32_t rt);
void Or(State& mips_state, uint32_t rt, uint32_t rs, uint32_t rd);
void slt(State& mips_state, uint32_t rt, uint32_t rs, uint32_t rd);
void sltu(State& mips_state, uint32_t rt, uint32_t rs, uint32_t rd);
void sll(State& mips_state, uint32_t rs, uint32_t shamt_field, uint32_t rd);
void srl(State& mips_state, uint32_t rs, uint32_t shamt_field, uint32_t rd);
void sub(State& mips_state, uint32_t rt, uint32_t rs, uint32_t rd);
void subu(State& mips_state, uint32_t rt, uint32_t rs, uint32_t rd);
void div(State& mips_state, uint32_t rs, uint32_t rt);
void divu(State& mips_state, uint32_t rs, uint32_t rt);
void mfhi(State& mips_state, uint32_t rd);
void mflo(State& mips_state, uint32_t rd);
void mult(State& mips_state, uint32_t rs,uint32_t rt);
void multu(State& mips_state, uint32_t rs, uint32_t rt);
void sra(State& mips_state, uint32_t rs, uint32_t shamt_field, uint32_t rd);
void mthi(State& mips_state, uint32_t rt);
void mtlo(State& mips_state, uint32_t rt);
void sllv(State& mips_state, uint32_t rs, uint32_t rt, uint32_t rd);
void srav(State& mips_state, uint32_t rs, uint32_t rt, uint32_t rd);
void srlv(State& mips_state, uint32_t rs, uint32_t rt, uint32_t rd);
void Xor(State& mips_state,  uint32_t rt, uint32_t rs, uint32_t rd);
void jalr(State& mips_state, uint32_t rs, uint32_t rt, uint32_t rd);

#endif
