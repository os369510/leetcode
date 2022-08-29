int *cache;
// will check next char
int _numDecodings(char * s, int idx) {
    int len = strlen(s), count = 0;
    if (idx > len)
        return 0;
    if (idx == len)
        return 1;
    if (s[idx] == '0')
        return 0;
    if (idx == len - 1)
        return 1;
    if (cache[idx])
        return cache[idx];
    if (s[idx] == '1') {
        if (s[idx + 1] != '0')
            count += _numDecodings(s, idx + 1);
        count += _numDecodings(s, idx + 2);
    }
    else if (s[idx] == '2') {
        if (s[idx + 1] <= '6' && s[idx + 1] >= '1') {
            count += _numDecodings(s, idx + 1);
            count += _numDecodings(s, idx + 2);
        }
        else
            count += _numDecodings(s, idx + 2);
    }
    else
        count += _numDecodings(s, idx + 1);
    cache[idx] = count;
    return count;
}

int numDecodings(char * s){
    int len = strlen(s), count = 0;
    cache = calloc(len, sizeof(int));
    count = _numDecodings(s, 0);
    free(cache);
    return count;
}
