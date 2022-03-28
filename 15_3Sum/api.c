int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i = 0, j = 0, k = 0, total = 32;
    int **ret = NULL, idx = 0;
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    *returnSize = 0;
    /* If realloc one array each time, then it will cause "Time Limit Exceeded".
     * Thus, alloc a bigger array in each time */
    ret = calloc(total, sizeof(int*));
    *returnColumnSizes = calloc(total, sizeof(int));
    for (i = 0; i < numsSize - 2; i++) {
        if (i && nums[i] == nums[i - 1])
            continue;
        if (nums[i] > 0 || nums[i] + nums[i+1] + nums[i+2] > 0)
            break;
        j = i + 1;
        k = numsSize - 1;
        while (j < k) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                j++;
                continue;
            }
            if (k < numsSize - 1 && nums[k] == nums[k + 1]) {
                k--;
                continue;
            }
            if (nums[j] + nums[k] > -nums[i])
                k--;
            else if (nums[j] + nums[k] < -nums[i])
                j++;
            else {
                *returnSize = *returnSize + 1;
                idx = *returnSize - 1;
                if (total == *returnSize){
                    total *= 2;
                    ret = realloc(ret, total * sizeof(int*));
                    *returnColumnSizes = realloc(*returnColumnSizes, total * sizeof(int));
                }
                ret[idx] = calloc(3, sizeof(int));
                (*returnColumnSizes)[idx] = 3;
                ret[idx][0] = nums[i];
                ret[idx][1] = nums[j];
                ret[idx][2] = nums[k];
                j++;
                k--;
            }
        }
    }
    return ret;
}
