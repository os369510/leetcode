int minPartitions(char * n){
    int max = 0, i = 0, len = strlen(n);
    for (i = 0; i < len; i++) {
        if (n[i] - 0x30 > max)
            max = n[i] - 0x30;
    }
    return max;
}
