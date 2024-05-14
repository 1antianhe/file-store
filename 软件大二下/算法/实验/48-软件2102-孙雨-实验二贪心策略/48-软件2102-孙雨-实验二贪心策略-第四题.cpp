#include <stdio.h>
#include <stdlib.h>

#define MAX_N 20

struct Minister {
    int left;
    int right;
    int reward;
};
//比较函数，用于排序 
int compare(const void *a, const void *b) {
    const struct Minister *ma = (const struct Minister *)a;
    const struct Minister *mb = (const struct Minister *)b;
    return ma->left - mb->left;
}

int main() {
    int n;
    struct Minister m[MAX_N + 1];
    scanf("%d", &n);
    scanf("%d %d", &m[0].left, &m[0].right);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &m[i].left, &m[i].right);
    }
    qsort(m, n + 1, sizeof(struct Minister), compare);
    int max_reward = 0;
    for (int i = n; i >= 0; i--) {
        int left_product = 1;
        for (int j = 0; j < i; j++) {
            left_product *= m[j].left;
        }
        m[i].reward = left_product / m[i].right;
        if (i == n || m[i].reward > max_reward) {
            max_reward = m[i].reward;
        }
    }
    printf("%d\n", max_reward);
    return 0;
}



