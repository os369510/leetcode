int cmpfunc (const void * a, const void * b) {                                                          
   return ( *(int*)a - *(int*)b );
}
bool _combinationSum(int* candidates, int candidatesSize, int target, int *count, int *len, int **ra, int **rcs) {
    bool ret = false;
    for (int i = candidatesSize - 1; i >= 0; i--) {
        if (candidates[i] > target)
            continue;
        if (candidates[i] == target) {
            if ((*len) <= 150)
                memcpy(ra[(*len) + 1], ra[(*len)], 500 * sizeof(int));
            ra[(*len)][(*count)] = candidates[i];
            (*rcs)[(*len)] = (*count) + 1;
            (*len)++;
            if (!i)
                return true;
            continue;
        }
        // if candidates[i] < target
        ra[(*len)][(*count)] = candidates[i];
        (*count)++;
        ret = _combinationSum(candidates, i + 1, target - candidates[i], count, len, ra, rcs);
        (*count)--;
        if (!ret) {
            if (i != 0)
                continue;
            return ret;
        }
    }
    return false;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int count = 0, len = 0, **ra = NULL;
    *returnSize = 0;
    qsort(candidates, candidatesSize, sizeof(int), cmpfunc);
    if (candidates[0] > target)
        return ra;
    ra = calloc(150, sizeof(int*));
    *returnColumnSizes = calloc(150, sizeof(int));
    for (int i = 0; i < 150; i++) {
        ra[i] = calloc(500, sizeof(int));
    }
    _combinationSum(candidates, candidatesSize, target, &count, &len, ra, returnColumnSizes);
    (*returnSize) = len;
    return ra;
}
