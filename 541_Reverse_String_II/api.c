void _reverseString(char* s, int sSize){
    int i = 0;
    char tmp = 0;
    for (i = 0; i < sSize / 2; i++) {
        tmp = s[i];
        s[i] = s[sSize - 1 -i];
        s[sSize - 1 - i] = tmp;
    }
}
char * reverseStr(char * s, int k){
    int i = 0, size = strlen(s);
    int seg = size / (2 * k), min = 0;
    if (size % (2 * k))
        seg++;
    for (i = 0; i < seg; i++){
        if (strlen(&s[i * 2 * k]) < k)
            min = strlen(&s[i * 2 * k]);
        else
            min = k;
        _reverseString(&s[i * 2 * k], min);
    }
    return s;
}
