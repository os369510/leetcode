class Solution {
private:
    unsigned char arr1_idx = 0, arr2_idx = 0;
    int arr1[2] = {INT_MAX, INT_MAX}, arr2[2] = {INT_MAX, INT_MAX};
    bool arr1_is_minimum = true;
public:
    bool increasingTriplet(vector<int>& nums) {
        arr1[0] = arr2[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (arr1_idx == 1 && nums[i] > arr1[arr1_idx])
                return true;
            if (arr2_idx == 1 && nums[i] > arr2[arr2_idx])
                return true;
            if (arr1_is_minimum) {
                if (nums[i] > arr1[arr1_idx])
                    arr1[++arr1_idx] = nums[i];
                else if (nums[i] > arr1[0]) // only if nums between [0] and [1]
                    arr1[arr1_idx] = nums[i];
                else { // if num less than arr1[0]
                    if (arr2_idx == 1 && arr1_idx == 0)
                        arr1[arr1_idx] = nums[i];
                    else {
                        arr2_idx = 0;
                        arr2[arr2_idx] = nums[i];
                        arr1_is_minimum = false;
                    }
                }
            }
            else {
                if (nums[i] > arr2[arr2_idx])
                    arr2[++arr2_idx] = nums[i];
                else if (nums[i] > arr2[0]) // only if nums between [0] and [1]
                    arr2[arr2_idx] = nums[i];
                else { // if num less than arr2[0]
                    if (arr1_idx == 1 && arr2_idx == 0)
                        arr2[arr2_idx] = nums[i];
                    else {
                        arr1_idx = 0;
                        arr1[arr1_idx] = nums[i];
                        arr1_is_minimum = true;
                    }
                }
            }
        }
        return false;
    }
};
