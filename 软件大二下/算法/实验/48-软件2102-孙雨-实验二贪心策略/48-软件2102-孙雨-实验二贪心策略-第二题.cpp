#include <stdio.h>
#define MAXN 100

int graph[MAXN][MAXN];  // �ڽӾ���
int n;  // ��ׯ����

int main() {
    // ��ȡ����
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // �ҵ����ҽԺ��λ��
    int ho = 0;  // ��ʼ�����ҽԺ��λ��Ϊ 0
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

    // ������
    printf("���ҽԺ��λ��Ϊ��%d\n", ho + 1);

    return 0;
}

