#include "cpu/instr.h"

make_instr_func(inc_rmv){
    OPERAND rm;
    rm.data_size=data_size;
    int len=modrm_rm(eip+1,&rm);
    operand_read(&rm);
    rm.val+=1;
    operand_write(&rm);
    return len+1;
}
