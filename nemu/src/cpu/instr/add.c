#include "cpu/instr.h"

make_instr_func(add_edx){
    OPERAND imm;
    imm.data_size=data_size;
    imm.addr=cpu.eip+1;
    imm.type=OPR_IMM;
    operand_read(&imm);
    if(data_size==16)alu_add(imm.val,cpu.grp[2]._16);
    else alu_add(imm.val,cpu.edx);
    return 2+data_size/8;
}

