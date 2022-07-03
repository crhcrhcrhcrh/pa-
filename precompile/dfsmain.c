#include <stdio.h>


int main(int argc, char* argv[]){
    // x64 指针 -> 8字节
    printf("%d\n", sizeof(void*));
    if(argc != 0){
        printf("%d, %s\n", argc, argv[0]);
        main(argc - 1, argv + 1);
    }
}

//  ./a.out crh ccy asd
// 4, ./a.out
// 3, crh
// 2, ccy
// 1, asd