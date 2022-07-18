int search_mid(char *s, int idx) {
    int count = 1, i = 1;
    if (!idx)
        return count;
    while (1) {
        // prevent goes to end
        if (!s[idx + i])
            break;
        if (s[idx - i] == s[idx + i])
            count++;
        else
            break;
        // prevent goes before begin
        if (&(s[idx - i]) == s)
            break;
        i++;
    }
    return count;
}
int search_pair(char *s, int idx) {
    int count = 0, i = 1;
    while (1) {
        // prevent goes to end
        if (!s[idx + i])
            break;
        if (s[idx - i + 1] == s[idx + i])
            count++;
        else
            break;
        // prevent goes before begin
        if (&(s[idx - i + 1]) == s)
            break;
        i++;
    }
    return count;    
}
int check(char *s, int idx) {
    int count = 0;
    // if in left of pair
    count += search_mid(s, idx);
    // if middle
    count += search_pair(s, idx);
    return count;
}
int countSubstrings(char * s){
    int len = strlen(s), ret = 0;
    for (int i = 0; i < len; i++) {
        ret += check(s, i);
    }
    return ret;
}
