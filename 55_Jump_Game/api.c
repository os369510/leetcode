bool _canJump(int* nums, int numsSize){
    int i = 0;
    if (numsSize == 1 && nums[0])
        return true;
    for (i = numsSize - 2; i >= 0; i--) {
        if (nums[i] >= numsSize - i - 1)
            return _canJump(nums, i + 1);
    }
    return false;
}
bool canJump(int* nums, int numsSize){
    if (numsSize == 1)
        return true;
    return _canJump(nums, numsSize);
}
