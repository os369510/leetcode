int removeElement(int* nums, int numsSize, int val){
    if (!numsSize) return 0;
    int idx = 0, i = 0;
    for (i = 0; i < numsSize; i++) {
        if (val != nums[i]) {
            nums[idx] = nums[i];
            idx++;
        }
    }
    return idx;

}
