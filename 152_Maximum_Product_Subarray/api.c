// contains n
int __maxProduct(int* nums, int numsSize) {    
    if (!numsSize) return 0;
    int ret = 1;
    for (int i = 0; i < numsSize; i++)
        ret *= nums[i];
    return ret;
}

// contains -n, n
int _maxProduct(int* nums, int numsSize) {
    int numn = 0, firstnidx = -1, lastnidx = -1;
    int skipidx = 0, retl = 0, retr = 0;
    if (numsSize == 1) return nums[0];
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < 0) {
            numn++;
            if (firstnidx == -1) firstnidx = i;
            lastnidx = i;
        }
    }
    if (numn % 2) {
        // try to skip first
        if (numsSize - firstnidx - 1 > 0)
            retl = __maxProduct(nums + firstnidx + 1, numsSize - firstnidx - 1);
        // try to skip last
        retr = __maxProduct(nums, lastnidx);
        
        return fmax(retl, retr);
    }
    else
        return __maxProduct(nums, numsSize);
    
    return -1;
}
// contains -n, 0, n
int maxProduct(int* nums, int numsSize){
    int idx = 0, ret = 0, max = 0;
    bool foundz = false;
    if (numsSize == 1) return nums[0];
    for (int i = 0; i < numsSize; i++) {
        // seperate by '0'
        if (!nums[i]) {
            foundz = true;
            ret = _maxProduct(nums + idx, i - idx);
            idx = i + 1;
            max = fmax(max, ret);
        }
    }
    // last splited array
    if (foundz && idx < numsSize)
        ret = _maxProduct(nums + idx, numsSize - idx);
    else
        ret = _maxProduct(nums, numsSize);
    max = fmax(max, ret);
    return max;
}
