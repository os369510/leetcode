class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int ss = 0, ts = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '#') {
                ss++;
                continue;
            }
            if (ss != 0) {
                ss--;
                continue;
            }
            int found = 0;
            while (!t.empty()) {
                char _t = t.back();
                t.pop_back();
                if (_t == '#') {
                    ts++;
                    continue;
                }
                if (ts != 0) {
                    ts--;
                    continue;
                }
                if (_t != s[i]) return false;
                found = 1;
                break;
            }
            if (found == 0) return false;
        }
        while (!t.empty()) {
            char _t = t.back();
            t.pop_back();
            if (_t == '#')  {
                ts++;
                continue;
            }
            if (ts != 0) {
                ts--;
                continue;
            }
            return false;
        }
        return true;
    }
};
