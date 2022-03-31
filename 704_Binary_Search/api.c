int search(int* nums, int numsSize, int target){
    int i = numsSize / 2, pre = i;
    int start = 0, tail = numsSize - 1;
    if (nums[start] == target)
        return start;
    if (nums[tail] == target)
        return tail;
    while (1) {
        pre = i;
        if (nums[i] > target) {
            // goes to left
            tail = i;
        }
        else if (nums[i] < target) {
            // goes to right
            start = i;
        }
        else {
            return i;
        }
        i = (start + tail) / 2;
        if (pre == i)
            return -1;
    }
    return -1;
}
