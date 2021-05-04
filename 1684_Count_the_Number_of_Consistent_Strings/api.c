int countConsistentStrings(char * allowed, char ** words, int wordsSize){
    int alen = strlen(allowed), i = 0, c = 0, k = 0, h = 0, match = 0, al = 0, ret = 0;
    for (i = 0; i < wordsSize; i++) {
        c = strlen(words[i]);
        al = 1;
        for (k = 0; k < c; k++) {
            match = 0;
            for (h = 0; h < alen; h++) {
                if (words[i][k] == allowed[h]) {
                    match = 1;
                    break;
                }
            }
            if (!match) {
                al = 0;
                break;
            }
        }
        if (al)
            ret++;
    }
    return ret;
}
