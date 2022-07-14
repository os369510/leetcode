bool isPalindrome(char * s){
    int len = strlen(s);
    int l = 0, r = len - 1;
    bool ret = true;
    while (l < r) {
        while (s[l]) {
            if ((s[l] >= 'a' && s[l] <= 'z') ||
                (s[l] >= 'A' && s[l] <= 'Z') ||
                (s[l] >= '0' && s[l] <= '9'))
                break;
            l++;
        }
        while (r >= 0 && s[r]) {
            if ((s[r] >= 'a' && s[r] <= 'z') ||
                (s[r] >= 'A' && s[r] <= 'Z') ||
                (s[r] >= '0' && s[r] <= '9'))
                break;
            r--;
        }
        if (l >= r)
            break;
        if (s[l] >= 'A' && s[l] <= 'Z')
            s[l] = s[l] - 'A' + 'a';
        if (s[r] >= 'A' && s[r] <= 'Z')
            s[r] = s[r] - 'A' + 'a';
        if (s[l] != s[r]) {
            ret = false;
            break;
        }
        l++;
        r--;
    }
    return ret;
}
