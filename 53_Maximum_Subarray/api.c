int maxSubArray(int* nums, int numsSize){
    int l = 0, max = nums[0];
    int lmax = nums[l], buf = 0;
    for (int l = 0; l < numsSize - 1; l++) {
        if (max < 0) {
            if (nums[l + 1] > max) {
                max = nums[l + 1];
                lmax = nums[l + 1];
                continue;
            }
        }
        buf = lmax + nums[l + 1];
        if (buf > lmax) {
            if (nums[l + 1] > buf)
                lmax = nums[l + 1];
            else
                lmax = buf;
        }
        else if (buf < 0)
            lmax = nums[l + 1];
        else
            lmax = buf;
        if (lmax > max)
            max = lmax;
    }
    return max;
}
