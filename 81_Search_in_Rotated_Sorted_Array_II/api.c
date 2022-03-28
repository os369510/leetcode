int search(int* nums, int numsSize, int target){
    int start = 0, mid = numsSize / 2, tail = numsSize - 1;
    if (nums[start] == target || nums[mid] == target || nums[tail] == target)
        return true;
    while (start < mid && mid < tail) {
        if (nums[start] == target || nums[mid] == target || nums[tail] == target)
            return true;
        if (nums[start] > target) { // left of start
            if (nums[mid] > target) { // left of mid
                if (nums[tail] > target) { // left of tail
                    tail--;
                }
                else // right of tail
                    return false;
            }
            else { // right of mid
                if (nums[tail] > target) // left of tail
                    start = mid;
                else // right of tail
                    return false;
            }
        }
        else { // right of start
            if (nums[mid] > target) // left of mid
                tail = mid;
            else { // right of mid
                if (nums[tail] > target) // left of tail
                    start = mid;
                else { // right of tail
                    start++;
                }
            }
        }
        mid = (start + tail) / 2;
    }
    return false;
}

