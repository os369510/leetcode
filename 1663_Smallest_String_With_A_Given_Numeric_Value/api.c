char * getSmallestString(int n, int k){
    int i = 0, r = 0;
    char *str = NULL;
    str = calloc(n + 1, sizeof(char));
    for (i = 0; i < n; i++){
        if (k <= (n - 1 - i) * 26) {
            str[i] = 'a';
            k--;
        }
        else if (k < (n - i) * 26) {
            r = k % 26;
            str[i] = 'a' - 1 + r;
            k -= r;
        }
        else {
            str[i] = 'z';
            k -= 26;
        }
    }
    return str;
}
