void push(int **arr, int start, int end) {
    int i = 0;
    for (i = end; i > start; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }
    return;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    int *ret = calloc(numsSize, sizeof(int)), i = 0;
    *returnSize = numsSize;
    for (i = 0; i < numsSize; i++) {
        push(&ret, index[i], i);
        ret[index[i]] = nums[i];
    }
    return ret;
}
