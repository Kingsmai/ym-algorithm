#include <stdio.h>

/**
 * 给定数列1, 1, 3, 5, 9, 17, ..., 从第4项开始，每项都是前3项的和。
 * 求第20190324项的最后4位数字。
 * 
 * 类似于斐波那契数列的第 n 项，只不过递推式变了，不能用递归，否则爆栈，
 * 还有一个问题是直接算到第 20190324 项肯定是会溢出的，在计算过程中要进行取余操作。
 */

int solve(int n) {
    if(n <= 3) {
        return 1;
    }
    int a = 1, b = 1, c = 1, result;
    for(int i = 4; i <= n; i++) {
        result = (a + b + c) % 10000;
        a = b;
        b = c;
        c = result;
    }
    return result;
}

int main(int argc, char const* argv[]) {
    printf("%d", solve(20190324));
    return 0;
}
