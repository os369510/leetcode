int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*) b);
}
int lastStoneWeight(int* stones, int stonesSize){
    int i = 0, size = stonesSize;
    qsort(stones, stonesSize, sizeof(int), cmpfunc);
    for (i = stonesSize - 1; i > 0; i--) {
        if (stones[i] == stones[i - 1]) {
            stones[i] = stones[i - 1] = 0;
            size -= 2;
            i--;
        }
        else {
            stones[i - 1] = stones[i] - stones[i - 1];
            size -= 1;
            qsort(stones, size, sizeof(int), cmpfunc);
        }
    }
    return stones[0];
}
