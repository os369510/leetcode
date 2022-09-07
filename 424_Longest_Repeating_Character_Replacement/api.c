int characterReplacement(char * s, int tmp){
    int len = strlen(s), max = 0, lmax = 0, k = tmp;
    char prevc = 0;
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (prevc == c)
            continue;
        lmax = 0;
        k = tmp;
        for (int j = i; j < len; j++) {
            if (s[j] == c) { lmax++; continue; }
            if (!k) break;
            lmax++;
            k--;
        }
        if (k) {
            if (lmax + k < len)
                lmax = lmax + k;
            else
                lmax = len;
        }
        max = fmax(max, lmax);
        prevc = c;
    }
    return max;
}
