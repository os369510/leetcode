int brokenCalc(int startValue, int target){
    int count = 0;
    while (target != startValue) {
        if (target % 2 || target < startValue) {
            target++;
            count++;
        }
        else {
            target = target >> 1;
            count++;
        }
    }
    return count;
}
