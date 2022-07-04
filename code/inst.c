#include <stdint.h>
#include <stdio.h>
#define u8 uint8_t
#define RTYPE(i) u8 rt = (i)->rtype.rt, rs = (i)->rtype.rs;
#define MTYPE(i) u8 addr = (i)->mtype.addr;
// 4bit  |2bit|2bit
// op    | rs | rt 
// op    | addr   
typedef union inst
{
    struct 
    {
        u8 rs :2, rt : 2, op : 4;
    }rtype;

    struct{
        u8 addr:4, op : 4;
    }mtype;
}inst_t;
u8 M[1 << 8];
u8 R[1 << 8];
u8 pc = 0;
void idex(){
    M[0] = 0b00011111;
    // 取出当前指令的地址
    inst_t* cur = (inst_t*)&M[pc];
    printf("current op is %d\n", cur->rtype.op);
    switch (cur->rtype.op)
    {
        case 0b0000: {R[cur->rtype.rt] = R[cur->rtype.rs]; pc++; break;};
        case 0b0001: {R[cur->rtype.rt] += R[cur->rtype.rs]; pc++; break;};
        case 0b1110: {R[0] = R[cur->mtype.addr]; pc++;break;}
        case 0b1111: {R[cur->mtype.addr] = R[0]; pc++; break;}
        default:printf("invalid instruction at PC = %x\n", pc);
    }
}

int main(){
    idex();
}