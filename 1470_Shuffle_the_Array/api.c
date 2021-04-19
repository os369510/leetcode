/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int i = 0, j = 0, count = 1, tmp = 0, idx = 0;
    for (i = numsSize / 2 - 1; i >= 1; i--, count++) {
        for (j = 0; j < count; j++) {
            idx = i + j * 2;
            tmp = nums[idx];
            nums[idx] = nums[idx + 1];
            nums[idx + 1] = tmp;
        }
    }
    *returnSize = numsSize;
    return nums;
}
