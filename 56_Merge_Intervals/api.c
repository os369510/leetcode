int cmp (const void * pa, const void * pb)
{
    const int *a = *(const int **)pa;
    const int *b = *(const int **)pb;
    if(a[0] == b[0])
        return a[1] - b[1];
    else
        return a[0] - b[0];
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int **ret, idx = 0, found = 0;
    ret = calloc(intervalsSize, sizeof(int*));
    // sort
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    // compare and merge
    for (int i = 0; i < intervalsSize; i++) {
        if (!ret[idx]) {
            ret[idx] = calloc(2, sizeof(int));
        }
        if (!found) {
            ret[idx][0] = intervals[i][0];
            ret[idx][1] = intervals[i][1];
            found = 1;
            if (i == intervalsSize - 1)
                idx++;
            continue;
        }
        if (intervals[i][0] <= ret[idx][1]) {
            // merge
            if (intervals[i][1] > ret[idx][1])
                ret[idx][1] = intervals[i][1];
            if (i == intervalsSize - 1)
                idx++;
        }
        else {
            idx++;
            i--;
            found = 0;
        }
    }
    *returnSize = idx;
    *returnColumnSizes = calloc(idx, sizeof(int));
    for (int i = 0; i < idx; i++)
        (*returnColumnSizes)[i] = 2;
    return ret;
}
