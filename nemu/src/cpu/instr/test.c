#include "cpu/instr.h"

make_instr_func(test_r_rm){
    OPERAND r,rm;
    int len=modrm_r_rm(cpu.eip+1,&r,&rm);
    operand_read(&r);
    operand_read(&rm);
    alu_and(r.val,rm.val);
    return len+1;
}
