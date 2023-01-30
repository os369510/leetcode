class Solution {
private:
    int *cache;
public:
    int _tribonacci(int n) {
        int ret;
        if (cache[n] != 0) return cache[n];
        if (n == 0) return 0;
        if (n <= 2) return 1;
        ret = _tribonacci(n - 1) + _tribonacci(n - 2) + _tribonacci(n - 3);
        cache[n] = ret;
        return ret;
    }
    int tribonacci(int n) {
        cache = (int*) calloc(n + 1, sizeof(int));
        int ret = _tribonacci(n);
        free(cache);
        return ret;
    }
};
