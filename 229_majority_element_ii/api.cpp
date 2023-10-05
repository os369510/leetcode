class Solution {
private:
    map<int, int> m;
public:
    vector<int> majorityElement(vector<int>& nums) {
        int thres = nums.size() / 3;
        vector<int> res;
        for (auto e : nums)
            m[e]++;
        for (auto e : m)
            if (e.second > thres) res.push_back(e.first);
        return res;
    }
};
