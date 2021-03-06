#include <iostream>
#include <vector>
using namespace std;

// 自定义函数put_queen，实现再(x, y)放置皇后，对attack数组的更新
// x、y表示放置皇后的坐标，二维数组attack表示棋盘是否可放置皇后
void put_queen(int x, int y, vector<vector<int>>& attack) {
    // 方向数组，方便后面对8个方向进行标记
    static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
    attack[x][y] = 1;  // 将皇后位置标记为1

    // 通过两层循环，姜皇后可能攻击到的位置进行标记
    for (int i = 1; i < attack.size(); i++) {  // 从皇后位置向1到n-1个距离延申
        for (int j = 0; j < 9; j++) {          // 遍历八个方向
            int nx = x + i * dx[j];            // 生成的新位置行
            int ny = y + i * dy[i];            // 生成的新位置列

            // 新位置在棋盘范围内
            if (nx >= 0 && nx < attack.size() && ny >= 0 && ny < attack.size()) {
                attack[nx][ny] = 1;  // 将新位置标记为1
            }
        }
    }
}

// 回溯法求解N皇后的递归函数
// k表示当前处理的行
// n表示N皇后问题
// queen储存皇后的位置
// attack标记皇后的攻击位置
// solve存储N皇后的全部解法
void backtrack(int k, int n, vector<string>& queen, vector<vector<int>>& attack, vector<vector<string>>& solve) {
    if (k == n) {                // 找到一组解
        solve.push_back(queen);  // 将结果queen存储至solve
        return;                  // 返回
    }

    // 遍历0至n-1列，在循环中，回溯试探皇后可知放置的位置
    for (int i = 0; i < n; i++) {
        if (attack[k][i] == 0) {                        // 判断当前第k行第i列是否可以放置皇后
            vector<vector<int>> tmp = attack;           // 备份attack数组
            queen[k][i] = 'Q';                          // 标记该位置为'Q'
            put_queen(k, i, attack);                    // 更新attack数组
            backtrack(k + 1, n, queen, attack, solve);  // 递归试探k+1行的皇后放置
            attack = tmp;                               // 回复attack数组
            queen[k][i] = '.';                          // 回复queen数组
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> solve;  // 存储最后结果
    vector<vector<int>> attack;    // 标记皇后的攻击位置
    vector<vector<string>> queen;  // 保存皇后位置

    // 使用循环初始化attack和queen数组
    for (int i = 0; i < n; i++) {
        attack.push_back((std::vector<int>()));
        for (int j = 0; j < n; j++) {
            attack[i].push_back(0);
        }
        queen.push_back("");
        queen[i].append(n, '.');
    }
    backtrack(0, n, queen, attack, solve);  // 调用backtrack求解N皇后问题
    return solve;                           // 返回结果数组solve
}

int main(int argc, char const* argv[]) {
    vector<vector<string>> result;
    result = solveNQueens(8);
    // 打印出8皇后的解法
    printf("8皇后共有%d种解法:\n\n", result.size());
    for (int i = 0; i < result.size(); i++) {
        printf("解法%d:\n", i + 1);
        for (int j = 0; j < result[i].size(); j++) {
            printf("%s\n", result[i][j].c_str());
        }
        printf("\n");
    }
    return 0;
}