class Solution {
private:
    bool comp(string lstr, string sstr) {
        int len_lstr = lstr.size(), len_sstr = sstr.size();
        if (len_lstr % len_sstr != 0) return false;
        for (int i = 0, count = 0; i < len_lstr; i++) {
            if (lstr[i] != sstr[count++]) return false;
            if (count == len_sstr) count = 0;
        }
        return true;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        std::map<char, vector<int>> m;
        string sstr = str2, lstr = str1;
        char fc, lc;
        int n = 0;
        if (str1.size() < str2.size()) {
            sstr = str1;
            lstr = str2;
        }
        fc = sstr[0];
        lc = sstr[sstr.size() - 1];
        for (int i = 0; i < sstr.size(); i++) {
            m[sstr[i]].push_back(i);
        }
        n = m[fc].size();
        for (int i = n - 1; i >= 0; i--) {
            if (n % (i + 1) != 0) continue;
            if (i == n - 1) {
                if (comp(lstr, sstr)) return sstr;
            }
            else {
                string subs = sstr.substr(0, m[fc][i + 1]);
                if (comp(sstr, subs) == false) continue;
                if (comp(lstr, subs)) return subs;
            }
        }
        return "";
    }
};
