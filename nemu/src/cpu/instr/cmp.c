#include "cpu/instr.h"

make_instr_func(cmp_eax){
    OPERAND imm;
    imm.data_size=8;

    imm.type=OPR_IMM;
    imm.addr=eip+2;
    operand_read(&imm);
    
    if(data_size==16){
        uint16_t nimm=(int16_t)(char)imm.val;
        alu_sub(nimm,cpu.gpr[0]._16);
    }
    else{
        uint32_t nimm=(int32_t)(char)imm.val;
        alu_sub(nimm,cpu.eax);
    }
    
    return 3;
}
