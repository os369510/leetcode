/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    int i = 0, j = 0;
    int *ret = calloc(numsSize, sizeof(int));
    for (i = 0; i < numsSize - 1; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] < nums[j])
                ret[j]++;
            else if (nums[i] > nums[j])
                ret[i]++;
        }
    }
    *returnSize = numsSize;
    return ret;
}
