#include "cpu/instr.h"

make_instr_func(lea_m_rv){
    //printf("\nlea:eax=%x\n",cpu.eax);
    OPERAND m,rv;
    m.data_size=data_size;
    rv.data_size=data_size;
    int len=1;
    len+=modrm_r_rm(eip+1,&rv,&m);
    rv.val=m.addr;
    operand_write(&rv);
    //printf("\nlea:edx=%x\n",cpu.edx);
    return len;
}
