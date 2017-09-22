#include "cpu/instr.h"

make_instr_func(push_ebp){
    cpu.esp-=4;
    OPERAND dst;
    dst.data_size=data_size;
    dst.addr=esp;
    dst.val=ebp;
    operand_write(&dst);
    return 2;
}
