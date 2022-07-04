
#include <stdint.h>
// 参数为int返回值为void的函数指针
typedef void (*sighandler_t)(int);
// 返回值为sighandler_t， 参数为int和sighandler_t的函数
sighandler_t signal (int, sighandler_t);

