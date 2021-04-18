int maximumWealth(int** accounts, int accountsSize, int* accountsColSize){
    int i = 0, j = 0, max = 0, sum = 0;
    for (i = 0; i < accountsSize; i++) {
        for (j = 0, sum = 0; j < accountsColSize[i]; j++) {
            sum += accounts[i][j];
        }
        if (sum > max)
            max = sum;
    }
    return max;
}
