

int countMatches(char *** items, int itemsSize, int* itemsColSize, char * ruleKey, char * ruleValue){
    int ret = 0, i = 0, idx = 0, max_len = 0;
    if (!strncmp(ruleKey, "type", 4))
        idx = 0;
    else if (!strncmp(ruleKey, "color", 5))
        idx = 1;
    else if (!strncmp(ruleKey, "name", 4))
        idx = 2;
    for (i = 0; i < itemsSize; i++) {
        max_len = strlen(ruleValue) > strlen(items[i][idx])? strlen(ruleValue) : strlen(items[i][idx]);
        if (!strncmp(items[i][idx], ruleValue, max_len))
            ret++;
    }
    return ret;
}
