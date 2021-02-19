#include <stdio.h>

/**
 * ��������1, 1, 3, 5, 9, 17, ..., �ӵ�4�ʼ��ÿ���ǰ3��ĺ͡�
 * ���20190324������4λ���֡�
 * 
 * ������쳲��������еĵ� n �ֻ��������ʽ���ˣ������õݹ飬����ջ��
 * ����һ��������ֱ���㵽�� 20190324 ��϶��ǻ�����ģ��ڼ��������Ҫ����ȡ�������
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
