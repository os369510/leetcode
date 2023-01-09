#include <string.h>
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::map<char, string> m;
        std::map<string, char> check;
        std::size_t ppos = 0, ns = 0;
        std::string ss;
        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            ns = s.find(" ", ppos);
            if (ns != -1)
                ss = s.substr(ppos, ns - ppos);
            else
                ss = s.substr(ppos);
            if (m.count(c) == 0) {
                m[c] = ss;
                if (check.count(ss) == 0)
                    check[ss] = c;
                else if (check[ss] != c)
                    return false;
            }
            else if (m[c] != ss)
                return false;
            ppos = ns + 1;
        }
        if (ns != -1)
            return false;
        return true;
    }
};
