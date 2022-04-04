void reverseString(char* s, int sSize){
    int i = 0;
    char tmp = 0;
    for (i = 0; i < sSize / 2; i++) {
        tmp = s[i];
        s[i] = s[sSize - 1 -i];
        s[sSize - 1 - i] = tmp;
    }
}
