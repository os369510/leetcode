class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int sl = strs[0].size();
        int len = strs.size();
        int count = 0;
        for (int s = 0; s < sl; s++) {
            int min = strs[0][s];
            for (int v = 1; v < len; v++) {
                if (strs[v][s] < min) {
                    count++;
                    break;
                }
                else 
                    min = strs[v][s];
            }
        }
        return count;
    }
};
