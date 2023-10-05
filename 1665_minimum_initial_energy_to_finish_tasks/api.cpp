class Solution {
private:
    int dp[100001];
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        int diff_a = a[1] - a[0];
        int diff_b = b[1] - b[0];
        if (diff_a < diff_b) return false;
        else if (diff_a > diff_b) return true;
        return (a[1] <= b[1])? false : true;
    }
    int solver(vector<vector<int>>& tasks, int *dp, int i) {
        if (i >= tasks.size()) return 0;
        if (dp[i] != -1) return dp[i];
        int seng = tasks[i][1];
        int next = tasks[i][0] + solver(tasks, dp, i+1);
        dp[i] = max(seng, next);
        return dp[i];
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        memset(dp, -1, sizeof(dp));
        sort(tasks.begin(), tasks.end(), compare);
        return solver(tasks, dp, 0);
    }
};
