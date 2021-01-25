bool canConstruct(char * ransomNote, char * magazine){
    if (!*ransomNote) return true;
    int lm = strlen(magazine), lr = strlen(ransomNote);
    if (lr > lm) return false;
    short table[26] = {0};
    int r = 0, m = 0, i = 0;
    for (m = 0, r = 0; m < lm; m++, r++) {
        table[magazine[m] - 'a']++;
        if (r < lr)
            table[ransomNote[r] - 'a']--;
    }
    for (i = 0; i < 26; i++) {
        if (table[i] < 0)
            return false;
    }
    return true;
}
