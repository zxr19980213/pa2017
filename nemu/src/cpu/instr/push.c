#include "cpu/instr.h"

make_instr_func(push_ebp){
    cpu.esp-=4;
    OPERAND dst;
    dst.data_size=data_size;
    dst.addr=cpu.esp;
    dst.val=cpu.ebp;
    //dst.type=OPR_MEM;
    //printf("fku\n");
    operand_write(&dst);
    //printf("fkt\n");
    return 1;
}
