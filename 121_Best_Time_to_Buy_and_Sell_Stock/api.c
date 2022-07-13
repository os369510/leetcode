int maxProfit(int* prices, int pricesSize){
    int min = INT_MAX, max = 0;
    for (int i = 0; i < pricesSize; i++) {
        min = (min > prices[i])? prices[i] : min;
        max = (max < prices[i] - min)? prices[i] - min : max;
    }
    return max;
}
