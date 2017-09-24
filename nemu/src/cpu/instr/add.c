#include "cpu/instr.h"

make_instr_func(add_edx){
    OPERAND imm;
    imm.data_size=data_size;
    imm.addr=eip+2;
    imm.type=OPR_IMM;
    operand_read(&imm);
    if(data_size==16)cpu.gpr[2]._16=alu_add(imm.val,cpu.gpr[2]._16);
    else cpu.edx=alu_add(imm.val,cpu.edx);
    //printf("\nimm.val=%x\n",imm.val);
    return 2+data_size/8;
}

