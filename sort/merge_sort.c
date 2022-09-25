#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define ARR_NUM 10000000

static void _merge(int *arr, int *tmparr, int s, int m, int e) {
    int i1 = s, i2 = m + 1, ti = s;
    int len = e - s + 1;

    memset(tmparr + s, 0, len * sizeof(int));

    while (i1 <= m && i2 <= e) {
        if (arr[i1] <= arr[i2])
            tmparr[ti++] = arr[i1++];
        else
            tmparr[ti++] = arr[i2++];
    }
    while (i1 <= m)
        tmparr[ti++] = arr[i1++];
    while (i2 <= e)
        tmparr[ti++] = arr[i2++];

    memcpy(arr + s, tmparr + s, len * sizeof(int));

    return;
}
static void _merge_sort(int *arr, int *tmparr, int s, int e) {
    if (s >= e)
        return;
    int m = (s + e) / 2;
    _merge_sort(arr, tmparr, s, m);
    _merge_sort(arr, tmparr, m + 1, e);
    _merge(arr, tmparr, s ,m, e);
}
void merge_sort(int *arr, int *tmparr, int len) {
    _merge_sort(arr, tmparr, 0, len - 1);
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void main(void) {
    int *arr, *tmparr, *verarr;
    arr = calloc(ARR_NUM, sizeof(int));
    tmparr = calloc(ARR_NUM, sizeof(int));
    verarr = calloc(ARR_NUM, sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < ARR_NUM; i++) {
        arr[i] = rand() % 20000 - 10000;
        verarr[i] = arr[i];
    }

    printf("processing amount of %d datas..\n", ARR_NUM);

    clock_t begin, end;
    double time_spent;

    begin = clock();
    merge_sort(arr, tmparr, ARR_NUM);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("my merge sort spent %lf seconds\n", time_spent);

    begin = clock();
    qsort(verarr, ARR_NUM, sizeof(int), cmpfunc);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("lib qsort spent %lf seconds\n", time_spent);

    for (int i = 0; i < ARR_NUM; i++) {
        if (arr[i] == verarr[i])
            continue;
        break;
    }

    free(verarr);
    free(tmparr);
    free(arr);
    return;
}

