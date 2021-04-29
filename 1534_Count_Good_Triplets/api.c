int countGoodTriplets(int* arr, int arrSize, int a, int b, int c){
    int i,j,k,count=0;
    for (i = 0; i < arrSize - 2; i++) {
        for (j = i + 1; j < arrSize -1; j++) {
            for (k = j + 1; k < arrSize; k++) {
                if ((arr[i] - arr[j]) * (arr[i] - arr[j]) > a * a)
                    break;
                if ((arr[j] - arr[k]) * (arr[j] - arr[k]) > b * b)
                    continue;
                if ((arr[i] - arr[k]) * (arr[i] - arr[k]) > c * c)
                    continue;
                count++;
            }
        }
    }
    return count;
}
