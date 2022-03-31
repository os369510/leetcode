int searchInsert(int* nums, int numsSize, int target){
    int i = numsSize / 2, start = 0, tail = numsSize - 1;
    while (1) {
        if (nums[i] > target) {
            // goes left
            tail = i;
        }
        else if (nums[i] < target) {
            // goes right
            start = i;
        }
        else {
            return i;
        }
        i = (tail + start) / 2;
        if (tail <= start + 1)
            break;
    }
    if (target > nums[tail])
        return tail + 1;
    else if (target <= nums[start])
        return start;
    else
        return tail;
    return -1;
}
