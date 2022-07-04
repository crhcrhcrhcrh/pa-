
#include <assert.h>
#include <stdio.h>
#include "yemu.h"

// op | rt | rs
// op | addr
typedef union inst
{
    struct {u8 rs : 2, rt : 2, op : 4;}rtype;
    struct {u8 addr : 4, op : 4;}mtype;

}inst_t;

#define RTYPE(i) u8 rt = (i)->rtype.rt, rs = (i)->rtype.rs;
#define MTYPE(i) u8 addr = (i)->mtype.addr;

void idex(){
    // 取出指令
    inst_t* cur = (inst_t*)&M[pc];
    // 取寄存器
    RTYPE(cur);
    // 取地址
    MTYPE(cur);
    switch (cur->rtype.op)
    {
        // movl rt, rs
        case 0b0000: {R[rt] = R[rs];pc++; break;}
        // add rt, rs
        case 0b0001: {R[rt] += R[rs];pc++; break;}
        // load addr 
        case 0b1110: {R[RA] = M[addr];pc++; break;}
        // store addr
        case 0b1111: {M[addr] = R[RA];pc++; break;}
        // 不存在的指令
        default: assert(0);
    }
}
