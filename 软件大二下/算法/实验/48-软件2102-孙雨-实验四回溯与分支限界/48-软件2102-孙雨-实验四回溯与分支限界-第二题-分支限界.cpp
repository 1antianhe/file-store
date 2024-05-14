#include <stdio.h>
#include <limits.h>

#define N 4  // 城市的数量

int graph[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int visited[N];  // 记录城市是否已访问
int bestTour[N]; // 记录最优路径
int bestCost = INT_MAX; // 记录最优路径的总成本

void branchAndBound(int currentCity, int tour[], int cost, int level) {
    int i;

    if (level == N - 1) { // 已经遍历完所有城市
        cost += graph[currentCity][0]; // 添加回到起始城市的路径成本

        if (cost < bestCost) { // 如果当前路径成本更低，则更新最优路径
            for (i = 0; i < N; i++)
                bestTour[i] = tour[i];
            bestCost = cost;
        }
        return;
    }

    for (i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            tour[level + 1] = i;
            branchAndBound(i, tour, cost + graph[currentCity][i], level + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    int i, tour[N];

    for (i = 0; i < N; i++)
        visited[i] = 0;

    visited[0] = 1;
    tour[0] = 0;

    branchAndBound(0, tour, 0, 0);

    printf("最优路径: ");
    for (i = 0; i < N; i++)
        printf("%d ", bestTour[i]);

    printf("\n最优路径成本: %d\n", bestCost);

    return 0;
}

