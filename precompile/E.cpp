#include <stdio.h>
#include <iostream>
#define A "aaa"
#define TEN(A) A A A
#define B TEN(A)
#define C TEN(B)
#define D TEN(C)


// ##连接
#define SYS sys##tem
using namespace std;
// int main(){
//     string s = "aaa" "aaa" "aaa" "aaa" "aaa" "aaa" "aaa" "aaa" "aaa" "aaa" "aaa" "aaa" "aaa" "aaa" "aaa" "aaa" "aaa" "aaa" "aaa" "aaa" "aaa" "aaa" "aaa" "aaa" "aaa" "aaa" "aaa";
//     cout << s <<endl;
//     cout << system << endl;
// }
int main(){
    string s = D;
    cout << s <<endl;
    // cout << SYS;
}   