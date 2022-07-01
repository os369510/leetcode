char * longestPalindrome(char * s){
    int len = strlen(s), i = 0, max = 0;
    char pre, post;
    char *ret = calloc(len + 1, sizeof(char));
    if (!len || len == 1)
            return s;
    ret[0] = s[0];
    max = 1;
    for (i = 1; i <= len - 1; i++){
        if (i < len - 1) {
            pre = s[i - 1];
            post = s[i + 1];
            if (pre == post) { // found
                int j = 1;
                while (i - j >= 0 && i + j <= len - 1) {
                    if (s[i - j] != s[i + j])
                        break;
                    j++;
                }
                if ((2 * (j - 1) + 1) > max) {
                    strncpy(ret, &s[i - j + 1], (2 * (j - 1) + 1));
                    max = (2 * (j - 1) + 1);
                }
            }
        }
        pre = s[i - 1];
        post = s[i];
        if (pre == post) { // found
            int j = 1;
            while (i - j >= 0 && i + j - 1 <= len - 1) {
                if (s[i - j] != s[i + j - 1])
                    break;
                j++;
            }
            if ((2 * (j - 1)) > max) {
                strncpy(ret, &s[i - j + 1], (2 * (j - 1)));
                max = (2 * (j - 1));
            }
        }
        if (len - 1 - i < max / 2)
            break;
    }
    return ret;
}
