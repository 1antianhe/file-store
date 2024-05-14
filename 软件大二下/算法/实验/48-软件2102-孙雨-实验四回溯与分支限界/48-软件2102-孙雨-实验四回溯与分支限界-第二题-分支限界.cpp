#include <stdio.h>
#include <limits.h>

#define N 4  // ���е�����

int graph[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int visited[N];  // ��¼�����Ƿ��ѷ���
int bestTour[N]; // ��¼����·��
int bestCost = INT_MAX; // ��¼����·�����ܳɱ�

void branchAndBound(int currentCity, int tour[], int cost, int level) {
    int i;

    if (level == N - 1) { // �Ѿ����������г���
        cost += graph[currentCity][0]; // ��ӻص���ʼ���е�·���ɱ�

        if (cost < bestCost) { // �����ǰ·���ɱ����ͣ����������·��
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

    printf("����·��: ");
    for (i = 0; i < N; i++)
        printf("%d ", bestTour[i]);

    printf("\n����·���ɱ�: %d\n", bestCost);

    return 0;
}

