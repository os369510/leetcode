int removeDuplicates(int* nums, int numsSize){
    if (!numsSize) return 0;
    int idx = 1, i = 0, pre = nums[0];
    for (i = 1; i < numsSize; i++) {
          if (pre != nums[i]) {
              nums[idx] = nums[i];
              idx++;
              pre = nums[i];
          }
    }
    return idx;
}
