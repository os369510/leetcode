class Solution {
public:
    bool detectCapitalUse(string word) {
        int has_upper = 0, has_lower = 0;
        if (word[0] > 'Z') has_lower = 1;
        for (int c = 1; c < word.size(); c++) {
            if (word[c] <= 'Z')
                has_upper = 1;
            else if (word[c] > 'Z')
                has_lower = 1;
            if (has_lower && has_upper)
                return false;
        }
        return true;
    }
};
