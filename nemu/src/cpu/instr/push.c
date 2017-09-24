#include "cpu/instr.h"

make_instr_func(push_ebp){
    cpu.esp-=4;
    OPERAND dst;
    dst.data_size=data_size;
    dst.addr=cpu.esp;
    dst.val=cpu.ebp;
    dst.type=OPR_MEM;
    //printf("here %x\n",dst.val);
    //printf("fku\n");
    operand_write(&dst);
    //printf("fkt\n");
    return 1;
}
make_instr_func(push_ebx){
    cpu.esp-=4;
    OPERAND dst;
    dst.data_size=data_size;
    dst.addr=cpu.esp;
    dst.val=cpu.ebx;
    dst.type=OPR_MEM;
    operand_write(&dst);
    return 1;
}
