#include "cpu/instr.h"

make_instr_func(leave){
    cpu.esp=cpu.ebp;
    OPERAND temp;
    temp.type=OPR_MEM;
    temp.data_size=data_size;
    temp.addr=cpu.esp;
    operand_read(&temp);
    cpu.ebp=temp.val;
    cpu.esp+=4;
    return 1;
}
