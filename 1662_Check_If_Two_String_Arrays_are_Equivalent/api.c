bool arrayStringsAreEqual(char ** word1, int word1Size, char ** word2, int word2Size){
    int i1 = 0, i2 = 0;
    int i1c = 0, i2c = 0;
    int i1_end = 0, i2_end =0;
    while (1) {
        if (!word1[i1][i1c]) {
            if (++i1 == word1Size)
                i1_end = 1;
            i1c = 0;
        }
        if (!word2[i2][i2c]) {
            if (++i2 == word2Size)
                i2_end = 1;
            i2c = 0;
        }
        if (i1_end | i2_end) {
            break;
        }
        if (word1[i1][i1c] != word2[i2][i2c]) return false;
        i1c++;
        i2c++;
    }
    return (i1_end & i2_end)? true : false;
}
