int rob(int* nums, int numsSize){
    int *dp = NULL, prev = 0, fm = 0, sm = 0;
    if (numsSize == 1) return nums[0];
    if (numsSize == 2) return (nums[0] > nums[1])? nums[0] : nums[1];
    dp = calloc(numsSize, sizeof(int));
    dp[0] = nums[0];
    // 0 ... N - 1
    for (int i = 1; i < numsSize - 1; i++) {
        if (dp[i - 1] > nums[i] + prev)
            dp[i] = dp[i - 1];
        else
            dp[i] = nums[i] + prev;
        prev = dp[i - 1];
    }
    fm = (dp[numsSize - 2] > dp[numsSize - 3])? dp[numsSize - 2] : dp[numsSize - 3];
    memset(dp, 0, numsSize * sizeof(int));
    // 1 ... N
    dp[1] = nums[1];
    for (int i = 2, prev = 0; i < numsSize; i++) {
        if (dp[i - 1] > nums[i] + prev)
            dp[i] = dp[i - 1];
        else
            dp[i] = nums[i] + prev;
        prev = dp[i - 1];
    }
    sm = (dp[numsSize - 1] > dp[numsSize - 2])? dp[numsSize - 1] : dp[numsSize - 2];
    
    return (fm > sm)? fm : sm;
}
