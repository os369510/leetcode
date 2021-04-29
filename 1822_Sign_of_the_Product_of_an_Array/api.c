int arraySign(int* nums, int numsSize){
    int count = 0, i = 0;
    for (i = 0; i < numsSize; i++) {
        if (!nums[i]) return 0;
        if (nums[i] < 0) count++;
    }
    return (count % 2)? -1 : 1;
}
