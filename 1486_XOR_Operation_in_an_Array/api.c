int xorOperation(int n, int start){
    int ret = start, i = 0;
    for (i = 1; i < n; i++) {
        start += 2;
        ret ^= start;
    }
    return ret;
}
