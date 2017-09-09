#include "cpu/cpu.h"

void set_CF_add(uint32_t result, uint32_t src) {
    cpu.eflags.CF = result < src;                                                                                
}       
void set_CF_sub(uint32_t dest,uint32_t src){
    cpu.eflags.CF=dest<src;
}
void set_CF_adc(uint32_t result,uint32_t src,uint32_t dest){
    cpu.eflags.CF=(result<(src+cpu.eflags.CF))||(result<(dest+cpu.eflags.CF))||(cpu.eflags.CF==1&&result==dest);
}
void set_CF_sbb(uint32_t result,uint32_t src,uint32_t dest){
    if(dest<src) cpu.eflags.CF=1;
    else set_CF_sub(dest-src,cpu.eflags.CF);
}
void set_CF_mul(uint64_t res,uint32_t src,uint32_t dest,size_t data_size){
    uint32_t res1=res<<(64-data_size)>>(64-data_size);
    cpu.eflags.CF=(res==res1);
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
void set_OF_mul(uint64_t result,uint32_t src,uint32_t dest,size_t data_size){
    int r=result<<(64-data_size)>>63;
    int s=src<<(32-src)>>31;
    int d=dest<<(32-src)>>31;
    if((d==s&&r==1)||(d!=s&&r=0))cpu.eflags.OF=1;
    else cpu.eflags.OF=0;
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
    uint32_t res=dest+src+cpu.eflags.CF;

    set_CF_adc(res,src,dest);
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

uint32_t alu_sbb(uint32_t src, uint32_t dest){
    uint32_t res=dest-src-cpu.eflags.CF;
    
    set_CF_sbb(res,src,dest);
    set_PF(res);
    //set_AF();
    set_ZF(res);
    set_SF(res);
    set_OF_sub(res,src,dest);

    return res;
}


uint64_t alu_mul(uint32_t src, uint32_t dest, size_t data_size) {
	uint64_t  res=src*dest;

    set_CF_mul(res,src,dest,data_size);
    set_PF(res);
    //set_AF();
    set_ZF(res);
    set_SF(res);
    set_OF_mul(res,src,dest,data_size);

    return res;
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
