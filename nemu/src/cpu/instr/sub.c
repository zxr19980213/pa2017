#include "cpu/instr.h"

make_instr_func(sub_esp){
    printf("\nsub:esp=%x\n",cpu.esp);
    OPERAND imm;
    imm.data_size=8;
    imm.type=OPR_IMM;
    imm.addr=eip+2;
    operand_read(&imm);

    if(data_size==16){
        uint16_t nimm=(int16_t)(char)imm.val;
        cpu.gpr[4]._16=alu_sub(nimm,cpu.gpr[4]._16);
    }
    else{
        uint32_t nimm=(int32_t)(char)imm.val;
        cpu.esp=alu_sub(nimm,cpu.esp);
    }
    //printf("\nsub:esp=%x\n",cpu.esp);
    return 3;
}
