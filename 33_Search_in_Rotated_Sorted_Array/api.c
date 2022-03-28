int search(int* nums, int numsSize, int target){
    int start = 0, mid = numsSize / 2, tail = numsSize - 1;
    if (nums[start] == target)
        return start;
    else if (nums[mid] == target)
        return mid;
    else if (nums[tail] == target)
        return tail;
    else if (numsSize <= 3)
        return -1;
    while (start < mid && mid < tail) {
        if (nums[start] == target)
            return start;
        else if (nums[mid] == target)
            return mid;
        else if (nums[tail] == target)
            return tail;
        
        if (nums[start] > target) { // left of start
            if (nums[mid] > target) { // left of mid
                if (nums[tail] > target) { // left of tail
                    if (nums[mid] < nums[start]) // right of start
                        tail = mid;
                    else // right of mid
                        start = mid;
                }
                else // right of tail
                    return -1;
            }
            else { // right of mid
                if (nums[tail] > target) // left of tail
                    start = mid;
                else // right of tail
                    return -1;
            }
        }
        else { // right of start
            if (nums[mid] > target) // left of mid
                tail = mid;
            else { // right of mid
                if (nums[tail] > target) // left of tail
                    start = mid;
                else { // right of tail
                    if (nums[mid] < nums[start]) // right of start
                        tail = mid;
                    else // right of mid
                        start = mid;
                }
            }
        }
        mid = (start + tail) / 2;
    }
    return -1;
}
