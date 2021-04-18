/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    int *ret = calloc(numsSize, sizeof(int));
    int i = 0;
    ret[0] = nums[0];
    *returnSize = numsSize;
    for (i = 1; i < numsSize; i++)
        ret[i] = ret[i - 1] + nums[i];
    return ret;
}
