#include <stdio.h>
#include <stdlib.h>

/**
 * С������λ�к���2��0��1��9�����ֺܸ���Ȥ����1��40������������
 * ��1��2��9��10��32��39 ��40���� 28�������ǵĺ���574��ƽ������
 * 14362��ע�⣬ƽ������ָ��ÿ�����ֱ�ƽ������͡�
 * 
 * ���ʣ���1��2019�У���������������ƽ�����Ƕ��٣�
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
    // �����ⷨ
    unsigned int num, result = 0;
    for (num = 1; num <= 2019; num++) {
        if (check(num))
            result += num * num;
    }
    printf("%u\n", result);
    return 0;
}
