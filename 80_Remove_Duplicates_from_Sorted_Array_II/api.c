int removeDuplicates(int* nums, int numsSize){
    int idx = 1, i = 0, pre = nums[0], protect = 1;
    for (i = 1; i < numsSize; i++) {
        if (pre != nums[i] ) {
            nums[idx] = nums[i];
            idx++;
            pre = nums[i];
            protect = 1;
        }
        else if (protect) {
            protect = 0;
            nums[idx] = nums[i];
            idx++;
        }
    }
    return idx;

}
