int *cache = NULL;
int sum(int *nums, int numsSize, int idx) {
    int f = 0, s = 0, n = 0;
    if (idx >= numsSize)
        return 0;
    if (cache[idx] != -1)
        return cache[idx];
    f = sum(nums, numsSize, idx + 2);
    s = sum(nums, numsSize, idx + 3);
    if (s > f)
        f = s;
    if (cache[idx] == -1)
        cache[idx] = f + nums[idx];
    return f + nums[idx];
}

int rob(int* nums, int numsSize){
    int f = 0, s = 0;
    cache = calloc(numsSize, sizeof(int));
    memset(cache, -1, sizeof(int) * numsSize);
    f = sum(nums, numsSize, 0);
    s = sum(nums, numsSize, 1);
    if (s > f)
        f = s;
    return f;
}
