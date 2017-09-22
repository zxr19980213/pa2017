#include "cpu/instr.h"

make_instr_func(cmp_edi){
    OPERAND rm,imm;
    rm.data_size=data_size;
    imm.data_size=8;

    imm.type=OPR_IMM;
    imm.addr=eip+1;
    operand_read(&imm);
    
    rm.type=OPR_REG;
    if(rm.data_size==32)rm.val=cpu.edi;
    else rm.val=(((unsigned)(cpu.edi<<16))>>16);
    
    alu_sub(imm.val,rm.val);
    return 3;
}
