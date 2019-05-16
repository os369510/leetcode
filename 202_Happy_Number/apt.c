bool isHappy(int n){
    int sum = 0;
    
    while (1){
        sum += (n%10) * (n%10);
        n /= 10;
        if (!n){
            if (sum == 1 || sum == 7)
                return true;
            else if (sum < 10)
                return false;
            n = sum;
            sum = 0;
        }
    }
    return false;
}
