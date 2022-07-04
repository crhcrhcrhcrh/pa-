#include <stdint.h>
#include <stdio.h>
// {0, 1, 2, 3, 4}
enum {RA, R1, R2, PC, NREG};
typedef uint8_t u8;
u8 R[]={
    [RA] = 0,
    [R1] = 0,
    [R2] = 0,
    [PC] = 0 
};
// #define NREG (sizeof(R) / sizeof(R[0]))
int main(){
    printf("%d\n", PC);
    printf("%d\n", R[PC]);
}