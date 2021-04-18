char * defangIPaddr(char * address){
    int len = strlen(address);
    char *ret = calloc(len + 7, sizeof(char));
    int i = 0, idx = 0;
    for (i = 0; i < len; i++) {
        if (address[i] == '.') {
            ret[idx++] = '[';
            ret[idx++] = address[i];
            ret[idx++] = ']';
        }
        else
            ret[idx++] = address[i];
    }
    ret[idx] = NULL;
    return ret;
}
