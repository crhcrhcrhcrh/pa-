#include <assert.h>
#include <stdio.h>
#include "yemu.h"

typedef union inst {
  struct { u8 rs  : 2, rt: 2, op: 4; } rtype;
  struct { u8 addr: 4,        op: 4; } mtype;
} inst_t;

#define RTYPE(i) u8 rt = (i)->rtype.rt, rs = (i)->rtype.rs;
#define MTYPE(i) u8 addr = (i)->mtype.addr;

void idex() {
  inst_t *cur = (inst_t *)&M[pc];
  RTYPE(cur);
  MTYPE(cur);
  switch (cur->rtype.op) {
    case 0b0000: {  R[rt]   = R[rs];   pc++; break; }
    case 0b0001: {  R[rt]  += R[rs];   pc++; break; }
    case 0b1110: {  R[RA]   = M[addr]; pc++; break; }
    case 0b1111: {  M[addr] = R[RA];   pc++; break; }
    default: printf("NOT this instruction\n");assert(0);
  }
}
