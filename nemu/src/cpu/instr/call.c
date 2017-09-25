#include "cpu/instr.h"

make_instr_func(call){
    cpu.esp-=4;
    OPERAND readd;
    readd.val=eip+1+data_size/8;
    readd.data_size=data_size;
    readd.addr=cpu.esp;
    readd.type=OPR_MEM;
    operand_write(&readd);
    OPERAND dis;
    dis.type=OPR_IMM;
    dis.data_size=data_size;
    dis.addr=eip+1;
    operand_read(&dis);
    
    return 1+data_size/8+dis.val;
}
