char * restoreString(char * s, int* indices, int indicesSize){
    int i = 0;
    char *ret = calloc(indicesSize + 1, sizeof(char));
    for (i = 0; i < indicesSize; i++) {
        ret[indices[i]] = s[i];
    }
    return ret;
}
