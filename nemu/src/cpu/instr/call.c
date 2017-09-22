#include "cpu/instr.h"

make_instr_func(call){
    cpu.esp-=4;
    OPERAND readd;
    readd.val=cpu.eip+5;
    readd.data_size=32;
    readd.addr=cpu.esp;
    cout<<"fku";
    operand_write(&readd);
    cout<<"fkt";
    OPERAND disp[4];
    int t=1,len=5;
    for(int i=0;i<4;++i){
        disp[i].data_size=8;
        disp[i].addr=cpu.eip+i+1;
        operand_read(&disp[i]);
        len+=(uint32_t)disp[i].val*t;
        t*=16;
    };
    return len;
}
