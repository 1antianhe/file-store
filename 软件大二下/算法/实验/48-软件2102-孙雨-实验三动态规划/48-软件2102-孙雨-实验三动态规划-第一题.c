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

    printf("投资额\t\t");
    for(j=0;j<=m;j++)
        printf("%d\t",j);
    printf("\n");

    for(i=1;i<=n;i++) {
        printf("第%d个项目\t",i);
        for(j=0;j<=m;j++) {
            printf("%d\t",g[i][j]);
        }
        printf("\n");
    }

    return f[n][m];
}

int main() {
    int m, n, i, j;
    printf("请输入投资总额（单位：十万元）和投资项目总数:");
    scanf("%d %d", &m, &n);
    for (i = 1; i <= n; i++) {
        printf("请输入第%d个项目按照每增加十万投资后的收益值:", i);
        for (j = 1; j <= m; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    int max = DP(m, n);
    printf("投资最大收益为：%d十万元\n", max);  
    return 0;
}




