class Solution {
private:
    int *cache;
    int pick_min(int from, int end) {
        int min = INT_MAX;
        for (int i = from; i <= end; i++) {
            if (cache[i] == 0) continue;
            if (min > cache[i]) min = cache[i];
        }
        return (min == INT_MAX)? 0 : min;
    }
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        cache = (int*) calloc(len, sizeof(int));
        for (int i = len - 2, end; i >= 0; i--) {
            if (nums[i] == 0) continue;
            end = i + nums[i];
            if (end >= len - 1) {
                cache[i] = 1;
                continue;
            }
            // end must <= len - 1
            cache[i] = pick_min(i + 1, end);
            if (cache[i] == 0) continue;
            cache[i]++;
        }
        return cache[0];
    }
};
