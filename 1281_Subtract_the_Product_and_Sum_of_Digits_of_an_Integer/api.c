int subtractProductAndSum(int n){
    int product = n % 10;
    int sum = n % 10;
    int curr = 0;
    n /= 10;
    while (n) {
        curr = n % 10;
        product *= curr;
        sum += curr;
        n /= 10;
    }
    return product - sum;
}
