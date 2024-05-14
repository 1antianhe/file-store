#include <stdio.h>
#include <stdlib.h>

int g[100][100];

int DP(int m, int n) {
    int i, j, k;
    int f[100][100] = {0};  
    for (i = 1; i <= n; i++) { 
        for (j = 0; j <= m; j++) { 
            for (k = 0; k <= j; k++) {  
                if (f[i-1][j-k] + g[i][k] > f[i][j]) {
                    f[i][j] = f[i-1][j-k] + g[i][k];
                }
            }
        }
    }

    printf("Ͷ�ʶ�\t\t");
    for(j=0;j<=m;j++)
        printf("%d\t",j);
    printf("\n");

    for(i=1;i<=n;i++) {
        printf("��%d����Ŀ\t",i);
        for(j=0;j<=m;j++) {
            printf("%d\t",g[i][j]);
        }
        printf("\n");
    }

    return f[n][m];
}

int main() {
    int m, n, i, j;
    printf("������Ͷ���ܶ��λ��ʮ��Ԫ����Ͷ����Ŀ����:");
    scanf("%d %d", &m, &n);
    for (i = 1; i <= n; i++) {
        printf("�������%d����Ŀ����ÿ����ʮ��Ͷ�ʺ������ֵ:", i);
        for (j = 1; j <= m; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    int max = DP(m, n);
    printf("Ͷ���������Ϊ��%dʮ��Ԫ\n", max);  
    return 0;
}




