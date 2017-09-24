#include "cpu/instr.h"

make_instr_func(sub_b_rmv){
    OPERAND imm,rm;
    imm.data_size=8;
    rm.data_size=data_size;
    imm.type=OPR_IMM;
    int len=modrm_rm(eip+1,&rm);
    imm.addr=eip+1+len;
    operand_read(&imm);
    operand_read(&rm);
    if(data_size==16)imm.val=(int16_t)(char)imm.val;
    else imm.val=(int32_t)(char)imm.val;
    rm.val=alu_sub(imm.val,rm.val);
    return 2+len;
}
