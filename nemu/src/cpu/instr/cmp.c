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

make_instr_func(cmp_rv_rmv){
    printf("\ncmp:eax=%x ecx=%x\n",cpu.eax,cpu.ecx);
    OPERAND r,rm;
    r.data_size=data_size;
    rm.data_size=data_size;
    r.type=OPR_REG;
    int len=1;
    len+=modrm_r_rm(eip+1,&r,&rm);
    operand_read(&r);
    operand_read(&rm);
    printf("\n%x %x\n",r.val,rm.val);
    alu_sub(r.val,rm.val);
    return len;
}
