#include <stdio.h>
#define NAMES(X) \
 X(TOM) X(Jerry) X(Tyke) X(Spike)
// 
int main(){
    #define PRINT(x) puts("hell, " #x " !");
    NAMES(PRINT);
}