#include <stdio.h>

int isSafe(int n, int m, int avail[], int alloc[][m], int need[][m], int seq[]) {
    int work[m], finish[n], count = 0, i, j;
    for (j = 0; j < m; j++) work[j] = avail[j];
    for (i = 0; i < n; i++) finish[i] = 0;

    while (count < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (!finish[i]) {
                for (j = 0; j < m && need[i][j] <= work[j]; j++);
                if (j == m) {
                    for (j = 0; j < m; j++) work[j] += alloc[i][j];
                    seq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) return 0;
    }
    return 1;
}

int main() {
    int n, m, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], need[n][m], avail[m], seq[n];

    printf("Enter Allocation matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) scanf("%d", &alloc[i][j]);

    printf("Enter Max matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) scanf("%d", &max[i][j]);

    printf("Enter Available resources:\n");
    for (j = 0; j < m; j++) scanf("%d", &avail[j]);

    printf("\nNeed matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    if (isSafe(n, m, avail, alloc, need, seq)) {
        printf("\nSystem is in SAFE state.\nSafe sequence: ");
        for (i = 0; i < n; i++) printf("P%d%s", seq[i], i < n - 1 ? " -> " : "\n");
    } else {
        printf("\nSystem is NOT in a safe state.\n");
        return 0;
    }

    int p, req[m];
    printf("\nEnter process number making a new request (-1 for none): ");
    scanf("%d", &p);

    if (p >= 0 && p < n) {
        printf("Enter request: ");
        for (j = 0; j < m; j++) scanf("%d", &req[j]);

        for (j = 0; j < m; j++)
            if (req[j] > need[p][j]) {
                printf("Error: process has exceeded its maximum claim.\n");
                return 0;
            }
        for (j = 0; j < m; j++)
            if (req[j] > avail[j]) {
                printf("Resources not available, P%d must wait.\n", p);
                return 0;
            }

        for (j = 0; j < m; j++) {
            avail[j] -= req[j];
            alloc[p][j] += req[j];
            need[p][j] -= req[j];
        }

        if (isSafe(n, m, avail, alloc, need, seq)) {
            printf("\nRequest can be GRANTED. New safe sequence: ");
            for (i = 0; i < n; i++) printf("P%d%s", seq[i], i < n - 1 ? " -> " : "\n");
        } else {
            for (j = 0; j < m; j++) {
                avail[j] += req[j];
                alloc[p][j] -= req[j];
                need[p][j] += req[j];
            }
            printf("\nRequest CANNOT be granted (system would be unsafe).\n");
        }
    }
    return 0;
}