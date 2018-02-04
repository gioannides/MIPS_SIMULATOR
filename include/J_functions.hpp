#ifndef J_TYPE
#define J_TYPE

#include "mips.hpp"

void j_type(State& mips_state, bool& executed);


void j(State& mips_state, uint32_t address);
void jal(State& mips_state, uint32_t address);

#endif
