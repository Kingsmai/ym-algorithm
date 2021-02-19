#include <stdio.h>
#include <stdlib.h>

/**
 * 小明对数位中含有2、0、1、9的数字很感兴趣，在1到40中这样的数包
 * 括1、2、9、10至32、39 和40，共 28个，他们的和是574，平方和是
 * 14362。注意，平方和是指将每个数分别平方后求和。
 * 
 * 请问，在1到2019中，所有这样的数的平方和是多少？
 */

int check(int n) {
    int t;
    while (n) {
        if (((t = n % 10) == 2) || t == 0 || t == 1 || t == 9)
            return 1;
        n /= 10;
    }
    return 0;
}

int main(int argc, char const* argv[]) {
    // 暴力解法
    unsigned int num, result = 0;
    for (num = 1; num <= 2019; num++) {
        if (check(num))
            result += num * num;
    }
    printf("%u\n", result);
    return 0;
}
