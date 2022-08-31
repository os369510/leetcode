int *cache;
int _lengthOfLIS(int* nums, int numsSize, int idx) {
    int max = 1, tmp = 0;
    if (cache[idx])
        return cache[idx];
    if (numsSize == 1) {
        cache[idx] = 1;
        return cache[idx];
    }
    for (int i = 1; i < numsSize; i++) {
        if (nums[0] < nums[i]){
            tmp = cache[idx + i] + 1;
            if (max < tmp)
                max = tmp;
        }
    }
    cache[idx] = max;
    return max;
}
int lengthOfLIS(int* nums, int numsSize){
    int max = 1, tmp = 0;
    cache = calloc(numsSize, sizeof(int));
    for (int i = numsSize - 1; i >= 0; i--) {
        tmp = _lengthOfLIS(&nums[i], numsSize - i, i);
        if (tmp > max)
            max = tmp;
    }
    free(cache);
    return max;
}
