#include "cpu/instr.h"

make_instr_func(lea_m_rv){
    OPERAND m,rv;
    m.data_size=data_size;
    rv.data_size=data_size;
    len+=modrm_r_rm(eip+1,&rv,&m);
    rv.val=m.addr;
    operand_write(&rv);
    return len;
}
