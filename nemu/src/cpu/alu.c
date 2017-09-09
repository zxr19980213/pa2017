#include "cpu/cpu.h"

void set_CF_add(uint32_t result, uint32_t src) {
    cpu.eflags.CF = result < src;                                                                                
}       
void set_CF_sub(uint32_t dest,uint32_t src){
    cpu.eflags.CF=dest<src;
}
void set_PF(uint32_t result) {
	result<<=24;
	result>>=24;
	int num=0;
	while(result!=0)
	{
		num+=result%2;
		result/=2;
	}
	if(num%2) cpu.eflags.PF=0;
    else cpu.eflags.PF=1;
}   
void set_ZF(uint32_t result) {
	cpu.eflags.ZF = (result == 0);
}       
void set_SF(uint32_t result) {
	cpu.eflags.SF = sign(result);
}       
void set_OF_add(uint32_t result, uint32_t src, uint32_t dest) {
	if(sign(src) == sign(dest)) {
		if(sign(src) != sign(result)) cpu.eflags.OF = 1;
			else cpu.eflags.OF = 0; 
	} 
	else { cpu.eflags.OF = 0;  
	}
}
void set_OF_sub(uint32_t result,uint32_t src,uint32_t dest){
    cpu.eflags.OF=0;
    if((sign(src)!=sign(dest))&&sign(dest)!=sign(result))
        cpu.eflags.OF=1;
}


uint32_t alu_add(uint32_t src, uint32_t dest) {
	uint32_t res=0;
	res=dest+src;

	set_CF_add(res,src);
	set_PF(res);
	//set_AF();
	set_ZF(res);
	set_SF(res);
	set_OF_add(res,src,dest);

	return res;
}



uint32_t alu_adc(uint32_t src, uint32_t dest) {
    uint32_t res=dest+src+1;

    set_CF_add(res,src);
    set_PF(res);
    //set_AF;
    set_ZF(res);
    set_SF(res);
    set_OF_add(res,src,dest);

    return res;
}


uint32_t alu_sub(uint32_t src, uint32_t dest) {
	uint32_t res=dest-src;

    set_CF_sub(dest,src);
    set_PF(res);
    //set_AF;
    set_ZF(res);
    set_SF(res);
    set_OF_sub(res,src,dest);

    return res;
}

uint32_t alu_sbb(uint32_t src, uint32_t dest) {
	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
    assert(0);
	return 0;
}


uint64_t alu_mul(uint32_t src, uint32_t dest, size_t data_size) {
	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);
	return 0;
}

int64_t alu_imul(int32_t src, int32_t dest, size_t data_size) {
	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);
	return 0;
}

uint32_t alu_div(uint64_t src, uint64_t dest, size_t data_size) {
	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);
	return 0;
}

int32_t alu_idiv(int64_t src, int64_t dest, size_t data_size) {
	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);
	return 0;
}

uint32_t alu_mod(uint64_t src, uint64_t dest) {
	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);
	return 0;
}

int32_t alu_imod(int64_t src, int64_t dest) {
	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);
	return 0;
}

uint32_t alu_and(uint32_t src, uint32_t dest) {
	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);
	return 0;
}

uint32_t alu_xor(uint32_t src, uint32_t dest) {
	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);
	return 0;
}

uint32_t alu_or(uint32_t src, uint32_t dest) {
	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);
	return 0;
}

uint32_t alu_shl(uint32_t src, uint32_t dest, size_t data_size) {
	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);
	return 0;
}

uint32_t alu_shr(uint32_t src, uint32_t dest, size_t data_size) {
	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);
}

uint32_t alu_sar(uint32_t src, uint32_t dest, size_t data_size) {
	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);
	return 0;
}

uint32_t alu_sal(uint32_t src, uint32_t dest, size_t data_size) {
	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	assert(0);
	return 0;
}
