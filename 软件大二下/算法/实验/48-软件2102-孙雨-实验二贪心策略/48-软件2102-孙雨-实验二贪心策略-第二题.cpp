#include <stdio.h>
#define MAXN 100

int graph[MAXN][MAXN];  // 邻接矩阵
int n;  // 村庄数量

int main() {
    // 读取输入
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // 找到最佳医院的位置
    int ho = 0;  // 初始化最佳医院的位置为 0
    int min;
    for (int i = 0; i < n; i++) {
        int max = 0;
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != -1 && graph[i][j] > max) {
                max = graph[i][j];
            }
        }
        if (max < min) {
            min = max;
            ho = i;
        }
    }

    // 输出结果
    printf("最佳医院的位置为：%d\n", ho + 1);

    return 0;
}

