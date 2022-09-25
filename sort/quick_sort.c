#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ARR_NUM 10000000

static void swap(int *a, int *b) {
    int c = *b;
    *b = *a;
    *a = c;
}
static int _partition(int *arr, int s, int e) {
    int pivot = arr[e];
    int m = s;

    for (int i = s; i < e; ++i) {
        if (arr[i] >= pivot)
            continue;
        swap(&arr[i], &arr[m]);
        ++m;
    }
    swap(&arr[e], &arr[m]);
    return m;
}
static void _quick_sort(int *arr, int s, int e) {
    if (s >= e)
        return;
    int pi = _partition(arr, s, e);
    _quick_sort(arr, s, pi - 1);
    _quick_sort(arr, pi + 1, e);
}
void quick_sort(int *arr, int len) {
    _quick_sort(arr, 0, len - 1);
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void main(void) {
    int *arr, *verarr;
    arr = calloc(ARR_NUM, sizeof(int));
    verarr = calloc(ARR_NUM, sizeof(int));

    for (int i = 0; i < ARR_NUM; i++) {
        arr[i] = rand() % 20000 - 10000;
        verarr[i] = arr[i];
    }

    printf("processing amount of %d datas..\n", ARR_NUM);

    clock_t begin, end;
    double time_spent;

    begin = clock();
    quick_sort(arr, ARR_NUM);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("my qsort spent %lf seconds\n", time_spent);

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
    free(arr);
    return;
}

