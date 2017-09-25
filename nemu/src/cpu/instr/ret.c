#include "cpu/instr.h"

make_instr_func(ret_near){
    OPERAND temp;
    //printf("\n%x\n",cpu.eip);
    temp.type=OPR_MEM;
    temp.data_size=data_size;
    temp.addr=cpu.esp;
    cpu.esp+=4;
    operand_read(&temp);
    //printf("\n%x\n",temp.val);
    // int len=temp.val-cpu.eip;
    cpu.eip=temp.val;
    //printf("\n%x\n",cpu.eip);
    //printf("%x\n",len+1);
    return 0;
}
