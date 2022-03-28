int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i = 0, j = 0, k = 0, diff = 0;
    int **ret = NULL, idx = 0;
    if (!numsSize) return NULL;
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    for (i = 0; i < numsSize - 2; i++) {
        if (i && nums[i] == nums[i - 1])
            continue;
        //printf("i = %d\n", i);
        for (j = numsSize - 1; j > i + 1; j--) {
            //printf("j = %d\n", j);
            diff = nums[i] + nums[j];
            for (k = j - 1; k > i; k--) {
                //printf("k = %d\n", k);
                if (!(diff + nums[k])) {
                    *returnSize = *returnSize + 1;
                    idx = *returnSize - 1;
                    if (!ret) {
                        ret = calloc(1, sizeof(int*));
                        returnColumnSizes = calloc(1, sizeof(int*));
                    }
                    else {
                        ret = realloc(ret, *returnSize * sizeof(int*));
                        returnColumnSizes = realloc(returnColumnSizes, *returnSize * sizeof(int*));
                    }
                    ret[idx] = calloc(3, sizeof(int));
                    returnColumnSizes[idx] = calloc(1, sizeof(int));
                    *returnColumnSizes[idx] = 3;
                    ret[idx][0] = nums[i];
                    ret[idx][1] = nums[j];
                    ret[idx][2] = nums[k];
                    printf("found: %d %d %d\n", ret[idx][0], ret[idx][1], ret[idx][2]);
                    break;
                }
            }
        }
    }
    printf("return size %d\n", *returnSize);
    for (i = 0; i < *returnSize; i++) {
        printf("ret[%d][0] = %d ret[%d][1] = %d ret[%d][2] = %d\n", i, ret[i][0], i, ret[i][1], i, ret[i][2]);
        printf("returnColumnSizes[%d][0] = %d\n", i, returnColumnSizes[i][0]);
    }
    return ret;
}
