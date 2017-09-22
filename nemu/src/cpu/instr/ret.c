#include "cpu/instr.h"

make_instr_func(ret_near){
    OPERAND temp;
    temp.type=OPR_MEM;
    temp.data_size=32;
    temp.addr=cpu.ebp+4;
    operand_read(&temp);
    printf("%x\n",temp.val);
    cpu.eip=temp.val;
    return 1;
}
