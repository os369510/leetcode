int *cache;
int _climbStairs(int n){
    int v = 0;
    if (cache[n])
        return cache[n];
    if (n <= 1) {
        cache[n] = 1;
        return 1;
    }
    v = _climbStairs(n - 1) + _climbStairs(n - 2);
    cache[n] = v;
    return v;
}
int climbStairs(int n){
    cache = calloc(n + 1, sizeof(int));
    return _climbStairs(n);
}
