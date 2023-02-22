class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int len = s.size(), tail = 0, max_checked_ptr = 0;
        if (s[len - 1] == '1') return false;
        vector<bool> reachable(len, false);
        reachable[0] = true;
        for (int i = 0; i < len; i++) {
            if (reachable[i] == false) continue;
            if (i == len - 1) return true;
            tail = min(i + maxJump, len - 1);
            for (int j = max(max_checked_ptr, i + minJump); j <= tail; j++) {
                if (s[j] == '0') reachable[j] = true;
            }
            max_checked_ptr = tail + 1;
        }
        return false;
    }
};
