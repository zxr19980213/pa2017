#include "cpu/instr.h"

make_instr_func(push_ebp){
    cpu.esp-=4;
    *(cpu.esp)=cpu.ebp;
    return 2;
}
