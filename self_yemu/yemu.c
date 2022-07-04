#include <stdio.h>
#include "yemu.h"


int main(){
    while (1)
    {
        // point to address 0 -> error
        if(M[pc] == 0){
            // 遍历内存
            for (int i = 0; i < NMEM; i++)
            {
                // address i mem is M[i]
                printf("M[%02d] = 0x%02x (%d)\n", i, M[i], M[i]);
            }
            break;
            
        }
        // execute
        idex();
    }
    return 0;
}

u8 R[NREG], M[NMEM] = {
  0b11100111,
  0b00000100,
  0b11100110,
  0b00010001,
  0b11111000,
  0b00000000,
  0b00010000,
  0b00100001,
  0b00000000,
};
