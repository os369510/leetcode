/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decompressRLElist(int* nums, int numsSize, int* returnSize){
    int i = 0, j = 0, len = 0, idx = 0;
    for (i = 0; i < numsSize; i+=2) {
        len += nums[i];
    }
    int *ret = calloc(len, sizeof(int));
    for (i = 0; i < numsSize; i+=2) {
        for (j = 0; j < nums[i]; j++) {
            ret[idx + j] = nums[i + 1];
        }
        idx += nums[i];
    }
    *returnSize = len;
    return ret;
}
