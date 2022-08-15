int findMin(int* nums, int numsSize){
    int l = 0, r = numsSize - 1, m = 0;
    while (l < r) {
        m = (l + r) / 2;
        if (nums[l] > nums[m] && r != m) {
            r = m;
            continue;
        }
        if (nums[m] > nums[r] && l != m) {
            l = m;
            continue;
        }
        if (nums[l] > nums[r]) {
            l = r;
            continue;
        }
        r--;
    }
    return nums[l];
}
