int sumOddLengthSubarrays(int* arr, int arrSize){
    int odd = arrSize % 2, i = 0, ret = 0, m = 0, d = 0, diff = 0, pick = 0;
    for (i = 0; i < arrSize / 2 + odd; i++) {
        if (!odd) {
            if (!m) m = arrSize / 2;
            ret += arr[i] * m + arr[arrSize - i - 1] * m;
            m += arrSize / 2 - 1 - i;
        }
        else {
            if (!m) m = arrSize / 2 + 1;
            ret += arr[i] * m + arr[arrSize - i - 1] * m;
            if (i == arrSize / 2)
                pick = arr[i] * m;
            if (!d) {
                diff = arrSize / 2 - 1 - i;
                d = 1;
            }
            else {
                d = 0;
            }
            m += diff;
        }
    }
    if (odd) ret -= pick;
    return ret;
}
