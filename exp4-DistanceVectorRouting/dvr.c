#include <stdio.h>

#define MAX_NODES 20

struct node {
    unsigned dist[MAX_NODES];
    unsigned from[MAX_NODES];
} rt[MAX_NODES];

int main() {
    int costmat[MAX_NODES][MAX_NODES];
    int nodes, i, j, k, count;

    printf("\nEnter the number of nodes : ");
    scanf("%d", &nodes);

    printf("\nEnter the cost matrix :\n");
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            scanf("%d", &costmat[i][j]);
            costmat[i][i] = 0;
            rt[i].dist[j] = costmat[i][j]; 
            rt[i].from[j] = j;
        }
    }

    do {
        count = 0;
        for (i = 0; i < nodes; i++) {
            for (j = 0; j < nodes; j++) {
                for (k = 0; k < nodes; k++) {
                    if (rt[i].dist[j] > costmat[i][k] + rt[k].dist[j]) { 
                        rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                        rt[i].from[j] = k;
                        count++;
                    }
                }
            }
        }
    } while (count != 0);

    for (i = 0; i < nodes; i++) {
        printf("\n\n For router %d\n", i + 1);
        for (j = 0; j < nodes; j++) {
            printf("\t\nnode %d via %d Distance %d ", j + 1, rt[i].from[j] + 1, rt[i].dist[j]);
        }
    }

    printf("\n\n");
    return 0;
}
