#include "cpu/instr.h"

make_instr_func(cmp_eax){
    OPERAND rm,imm;
    rm.data_size=data_size;
    imm.data_size=8;

    imm.type=OPR_IMM;
    imm.addr=eip+1;
    operand_read(&imm);
    
    rm.type=OPR_REG;
    int32_t nimm;
    if(rm.data_size==32){
        rm.val=cpu.eax;
        nimm=imm.val;
    }
    else {
        rm.val=(((unsigned)(cpu.eax<<16))>>16);
        nimm=(int16_t)imm.val;
    }
    
    alu_sub(nimm,rm.val);
    return 3;
}
