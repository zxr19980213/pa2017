#include "cpu/instr.h"

make_instr_func(add_iv_rmv){
    OPERAND imm,rm;
    rm.data_size=data_size;
    imm.data_size=data_size;
    int len=modrm_rm(eip+1,&rm);
    imm.addr=eip+1+len;
    imm.type=OPR_IMM;
    operand_read(&imm);
    operand_read(&rm);
    rm.val=alu_add(imm.val,rm.val);
    operand_write(&rm);
    return 1+len+data_size/8;
}

make_instr_func(add_iv_eax){
    //printf("\nadd:eax=%x\n",cpu.eax);
    OPERAND imm;
    imm.data_size=data_size;
    imm.addr=eip+1;
    imm.type=OPR_IMM;
    operand_read(&imm);
    if(data_size==16)cpu.gpr[0]._16=alu_add(imm.val,cpu.gpr[0]._16);
    else cpu.eax=alu_add(imm.val,cpu.eax);
    //printf("\nadd:eax=%x\n",cpu.eax);
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
    rm.val=alu_add(r.val,rm.val);
    operand_write(&rm);
    return len;
}

make_instr_func(add_b_rmv){
    OPERAND imm,rm;
    imm.data_size=8;
    imm.type=OPR_IMM;
    rm.data_size=data_size;
    int len=modrm_rm(eip+1,&rm);
    operand_read(&rm);
    imm.addr=eip+1+len;
    operand_read(&imm);
    if(data_size==16){
        imm.val=(int16_t)(char)imm.val;
    }
    else
        imm.val=(int32_t)(char)imm.val;
    rm.val=alu_add(imm.val,rm.val);
    operand_write(&rm);
    return 2+len;
}
