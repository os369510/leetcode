#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int diff;
    int idx;
} NODE;

int compare(const void * a, const void * b) {
    return (((NODE*)a)->diff - ((NODE*)b)->diff);
}
int twoCitySchedCost(int** costs, int costsSize, int* costsColSize){
    int sum = 0, i = 0;
    NODE *list = NULL;
    list = calloc(costsSize, sizeof(NODE));
    for (i = 0; i < costsSize; i++) {
        list[i].diff = costs[i][0] - costs[i][1];
        list[i].idx = i;
    }
    qsort(list, costsSize, sizeof(NODE), compare);
    for (i = 0; i < costsSize; i++) {
        if (i < costsSize / 2)
            sum += costs[list[i].idx][0];
        else
            sum += costs[list[i].idx][1];
    }
    return sum;
}
