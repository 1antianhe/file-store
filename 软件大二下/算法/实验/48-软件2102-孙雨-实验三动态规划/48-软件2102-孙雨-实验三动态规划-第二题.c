#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
//��̬�滮 
void LCS(char* s1, char* s2) {
    int l1 = strlen(s1), l2 = strlen(s2);
    int i, j;
    int c[MAX + 1][MAX + 1] = { 0 };

    int b[MAX + 1][MAX + 1] = { 0 };
    
    for (i = 1; i <= l1; i++) {
        for (j = 1; j <= l2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 0;
            }
            else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 1;
            }
            else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 2;
            }
        }
    }
//�������������� 
    char lcs[MAX + 1] = { 0 };
    int index = 0, maxlen = c[l1][l2];
    for (i = l1, j = l2; i > 0 && j > 0;) {
        if (b[i][j] == 0) {
            lcs[--maxlen] = s1[i - 1];
            i--;
            j--;
        }
        else if (b[i][j] == 1) {
            i--;
        }
        else {
            j--;
        }
    }

    // ������
    printf("��һ���ַ����У�%s\n", s1);
    printf("�ڶ����ַ����У�%s\n", s2);
    printf("����������г���Ϊ��%d\n", c[l1][l2]);
    printf("������������ǣ�");
    for (i = 0; i < strlen(lcs); i++) {
        printf("%c", lcs[i]);
    }
    printf("\n");
}

int main() {
    char s1[MAX], s2[MAX];
    printf("�������һ���ַ����У�");
    scanf("%s", s1);
    printf("������ڶ����ַ����У�");
    scanf("%s", s2);
    LCS(s1, s2);
    return 0;
}


