int cache[10001];
int _coinChange(int* coins, int coinsSize, int amount){
    int ret = -1, min = INT_MAX;
    bool found = false;
    if (amount < 0) return -1;
    if (cache[amount]) return cache[amount];
    if (amount == 0) return 0;
    for (int i = 0; i < coinsSize; i++) {
        if (coins[i] > amount)
            continue;
        ret = _coinChange(coins, coinsSize, amount - coins[i]);
        if (ret < 0) continue;
        found = true;
        min = fmin(min, ret + 1);
    }
    cache[amount] = (found)? min : -1;
    return cache[amount];
}
int coinChange(int* coins, int coinsSize, int amount){
    if (!amount) return 0;
    memset(cache, 0, 10001 * sizeof(int));
    return _coinChange(coins, coinsSize, amount);
}
