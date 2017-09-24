#include "cpu/instr.h"

make_instr_func(cmp_b_rmv){
    OPERAND imm,rm;
    imm.data_size=8;
    rm.data_size=data_size;
    imm.type=OPR_IMM;
    int len=modrm_rm(eip+1,&rm);
    imm.addr=eip+2+len;
    operand_read(&imm);
    
    if(data_size==16){
        imm.val=(int16_t)(char)imm.val;
    }
    else{
        imm.val=(int32_t)(char)imm.val;
    }
    alu_sub(imm.val,rm.val);
    
    return 2+len;
}

make_instr_func(cmp_rv_rmv){
    //printf("\ncmp:eax=%x ecx=%x\n",cpu.eax,cpu.ecx);
    OPERAND r,rm;
    r.data_size=data_size;
    rm.data_size=data_size;
    r.type=OPR_REG;
    int len=1;
    len+=modrm_r_rm(eip+1,&r,&rm);
    operand_read(&r);
    operand_read(&rm);
    //printf("\n%x %x\n",r.val,rm.val);
    alu_sub(r.val,rm.val);
    return len;
}
