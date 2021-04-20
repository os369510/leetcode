char * interpret(char * command){
    char *ret = calloc(1, sizeof(char));
    int i = 0, len = 0, idx = 0;
    for (i = 0; i < strlen(command); i++) {
        if (command[i] == 'G') {
            len++;
            ret = realloc(ret, len * sizeof(char));
            ret[idx] = 'G';
            idx++;
        }
        else if (command[i] == '(') {
            if (command[i + 1] == ')') {
                len++;
                ret = realloc(ret, len * sizeof(char));
                ret[idx++] = 'o';
                i++;
            }
            else {
                len += 2;
                ret = realloc(ret, len * sizeof(char));
                ret[idx++] = 'a';
                ret[idx++] = 'l';
                i += 3;
            }
        }
    }
    ret = realloc(ret, (len + 1) * sizeof(char));
    ret[idx] = 0;
    return ret;
}
