#include <stdio.h>
#include <stdlib.h>

/**
 * С������λ�к���2��0��1��9�����ֺܸ���Ȥ����1��40������������
 * ��1��2��9��10��32��39 ��40���� 28�������ǵĺ���574��ƽ������
 * 14362��ע�⣬ƽ������ָ��ÿ�����ֱ�ƽ������͡�
 * 
 * ���ʣ���1��2019�У���������������ƽ�����Ƕ��٣�
 */

int st[10];

int check(int n) {
    while(n) {
        if (st[n % 10]) return 1;
        n /= 10;
    }
    return 0;
}

int main(int argc, char const* argv[]) {
    // �����ⷨ
    st[0] = st[1] = st[2] = st[9] = 1;
    st[3] = st[4] = st[5] = st[6] = st[7] = st[8] = 0;
    unsigned int num, result = 0;
    for (num = 1; num <= 2019; num++) {
        if (check(num)) result += num * num;
    }
    printf("%u\n", result);
    return 0;
}
