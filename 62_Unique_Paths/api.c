int **cache;
int _uniquePaths(int m, int n){
    int v = 0;
    if (cache[m][n])
        return cache[m][n];
    int d = 0, r = 0;
    if (m == 1 || n == 1) {
        cache[m][n] = 1;
        return 1;
    }
    if (m >= 2)
        d = _uniquePaths(m - 1, n);
    if (n >= 2)
        r = _uniquePaths(m, n - 1);
    v = d + r;
    cache[m][n] = v;
    return v;
}
int uniquePaths(int m, int n){
    int ret = 0;
    cache = calloc(m + 1, sizeof(int*));
    for (int i = 0; i <= m; i++) {
        cache[i] = calloc(n + 1, sizeof(int));
    }
    ret = _uniquePaths(m, n);
    for (int i = 0; i < m; i++) {
        free(cache[i]);
    }
    free(cache);
    return ret;
}
