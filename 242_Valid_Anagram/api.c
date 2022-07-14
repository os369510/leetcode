bool isAnagram(char * s, char * t){
    char *arr = calloc(0xff, sizeof(char));
    int lens = strlen(s);
    int lent = strlen(t);
    if (lens != lent)
        return false;
    for (int i = 0; i < lent; i++) {
        arr[s[i]] ++;
        arr[t[i]] --;
    }
    for (int i = 0; i < 0xff; i++) {
        if (arr[i])
            return false;
    }
    return true;
}
