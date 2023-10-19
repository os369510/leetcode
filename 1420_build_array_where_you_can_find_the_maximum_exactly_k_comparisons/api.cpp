class Solution {
private:
    int cache[50][100][51] = {0}; // n, m, k
    int resolver(int n, int m, int k, int max) {
        int res = 0;
        if (n == 0) return 0;
        if (k > n || k < 0) return 0;
        if (n == 1) {
            //printf("n is now 1, max is %d, k %d, m %d\n", max, k, m);
            if (k == 0) return max;
            if (k == 1 && max < m) return m - max;
        }
        for (int i = 1; i <= m; i++) {
                int _k = k, _max = max, tmp = 0;
                if (i > _max) {
                    _k--;
                    if (_k < 0) continue;
                    _max = i;
                }
                //if (cache[gn - n][i - 1][_k] != -1) {
                 //   printf("read from cache[%d][%d][%d] = %d\n", gn - n, i - 1, k, cache[gn - n][i - 1][_k]);
                 //   return cache[gn - n][i - 1][_k];
                //}
                tmp = resolver(n - 1, m, _k, _max);
                res += tmp;
                //if (cache[gn - n][i - 1][_k] == -1) {
                //    cache[gn - n][i - 1][_k] = tmp;
                //    printf("cache[%d][%d][%d] = %d\n", gn - n, i - 1, k, tmp);
                //}
                //    printf("res %d, n %d i %d _k %d max %d\n", res, n, i, _k, _max);
        }
        printf("\n");
        return res;
    }
public:
    int gn = 0;
    int numOfArrays(int n, int m, int k) {
        gn = n;
        memset(cache, -1, sizeof cache); 
        if (k == 0) return k;
        return resolver(n, m, k, -1);
    }
};
