#include <stdint.h>

typedef uint8_t u8;
// 16个存储地址
#define NMEM 16
// 4个寄存器, pc, 寄存器个数
enum { RA, R1, R2, R3, PC, NREG };
// 
extern u8 M[NMEM], R[NREG];
#define pc (R[PC])

void idex();
