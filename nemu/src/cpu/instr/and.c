#include "cpu/instr.h"

make_instr_func(and_b_rmv){
    OPERAND imm,rm;
    imm.data_size=8;
    rm.data_size=data_size;
    int len=modrm_rm(eip+1,&rm);
    imm.type=OPR_IMM;
    imm.addr=eip+1+len;
    operand_read(&imm);
    operand_read(&rm);
    if(data_size==16)imm.val=(int16_t)(char)imm.val;
    else imm.val=(int32_t)(char)imm.val;
    rm.val=alu_and(imm.val,rm.val);
    operand_write(&rm);
    return len+2;
}
