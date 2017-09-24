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

make_instr_func(add_iv_eax){
    OPERAND imm;
    imm.data_size=data_size;
    imm.addr=eip+1;
    imm.type=OPR_IMM;
    operand_read(&imm);
    if(data_size==16)cpu.gpr[0]._16=alu_add(imm.val,cpu.gpr[0]._16);
    else cpu.eax=alu_add(imm.val,cpu.eax);
    return 1+data_size/8;
}

make_instr_func(add_rv_rmv){
    OPERAND r,rm;
    r.data_size=data_size;
    rm.data_size=data_size;
    int len=1;
    len+=modrm_r_rm(eip+1,&r,&rm);
    operand_read(&r);
    operand_read(&rm);
    rm.val+=r.val;
    operand_write(&rm);
}
