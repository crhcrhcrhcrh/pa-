#include <stdio.h>
#include <iostream>
#define A "aaa"
#define TEN(A) A A A
#define B TEN(A)
#define C TEN(B)
#define D TEN(C)
using namespace std;
int main(){
    string s = D;
    cout << s;
}   