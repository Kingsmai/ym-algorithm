#include <iostream>
#include <vector>
using namespace std;

// �Զ��庯��put_queen��ʵ����(x, y)���ûʺ󣬶�attack����ĸ���
// x��y��ʾ���ûʺ�����꣬��ά����attack��ʾ�����Ƿ�ɷ��ûʺ�
void put_queen(int x, int y, vector<vector<int>>& attack) {
    // �������飬��������8��������б��
    static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
    attack[x][y] = 1;  // ���ʺ�λ�ñ��Ϊ1

    // ͨ������ѭ�������ʺ���ܹ�������λ�ý��б��
    for (int i = 1; i < attack.size(); i++) {  // �ӻʺ�λ����1��n-1����������
        for (int j = 0; j < 9; j++) {          // �����˸�����
            int nx = x + i * dx[j];            // ���ɵ���λ����
            int ny = y + i * dy[i];            // ���ɵ���λ����

            // ��λ�������̷�Χ��
            if (nx >= 0 && nx < attack.size() && ny >= 0 && ny < attack.size()) {
                attack[nx][ny] = 1;  // ����λ�ñ��Ϊ1
            }
        }
    }
}

// ���ݷ����N�ʺ�ĵݹ麯��
// k��ʾ��ǰ�������
// n��ʾN�ʺ�����
// queen����ʺ��λ��
// attack��ǻʺ�Ĺ���λ��
// solve�洢N�ʺ��ȫ���ⷨ
void backtrack(int k, int n, vector<string>& queen, vector<vector<int>>& attack, vector<vector<string>>& solve) {
    if (k == n) {                // �ҵ�һ���
        solve.push_back(queen);  // �����queen�洢��solve
        return;                  // ����
    }

    // ����0��n-1�У���ѭ���У�������̽�ʺ��֪���õ�λ��
    for (int i = 0; i < n; i++) {
        if (attack[k][i] == 0) {                        // �жϵ�ǰ��k�е�i���Ƿ���Է��ûʺ�
            vector<vector<int>> tmp = attack;           // ����attack����
            queen[k][i] = 'Q';                          // ��Ǹ�λ��Ϊ'Q'
            put_queen(k, i, attack);                    // ����attack����
            backtrack(k + 1, n, queen, attack, solve);  // �ݹ���̽k+1�еĻʺ����
            attack = tmp;                               // �ظ�attack����
            queen[k][i] = '.';                          // �ظ�queen����
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> solve;  // �洢�����
    vector<vector<int>> attack;    // ��ǻʺ�Ĺ���λ��
    vector<vector<string>> queen;  // ����ʺ�λ��

    // ʹ��ѭ����ʼ��attack��queen����
    for (int i = 0; i < n; i++) {
        attack.push_back((std::vector<int>()));
        for (int j = 0; j < n; j++) {
            attack[i].push_back(0);
        }
        queen.push_back("");
        queen[i].append(n, '.');
    }
    backtrack(0, n, queen, attack, solve);  // ����backtrack���N�ʺ�����
    return solve;                           // ���ؽ������solve
}

int main(int argc, char const* argv[]) {
    vector<vector<string>> result;
    result = solveNQueens(8);
    // ��ӡ��8�ʺ�Ľⷨ
    printf("8�ʺ���%d�ֽⷨ:\n\n", result.size());
    for (int i = 0; i < result.size(); i++) {
        printf("�ⷨ%d:\n", i + 1);
        for (int j = 0; j < result[i].size(); j++) {
            printf("%s\n", result[i][j].c_str());
        }
        printf("\n");
    }
    return 0;
}