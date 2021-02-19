#include <stdio.h>

int main(int argc, char const* argv[]) {
    int a, b, res;
    a = 1073741824, b = 1073741824;
    res = a + b;
    printf("%d + %d = %u\n", a, b, res);
    
    int modA, modB, modRes;
    modA = a % 10000;
    modB = b % 10000;
    modRes = modA + modB;
    printf("%d + %d = %d\n", modA, modB, modRes);
    return 0;
}
