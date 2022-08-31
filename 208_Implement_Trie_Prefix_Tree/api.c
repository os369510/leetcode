typedef struct _trie{
    char *pres;
    struct _trie *arr[26];
    bool is_word;
} Trie;


Trie* trieCreate() {
    return calloc(1, sizeof(Trie));
}

void trieInsert(Trie* obj, char * word) {
    Trie *tmp = obj;
    int len = strlen(word), idx = 0;
    if (tmp->pres) {
        free(tmp->pres);
        tmp->pres = NULL;
    }
    if (!tmp->pres)
        tmp->pres = calloc(len + 1, sizeof(char));
    strncpy(tmp->pres, word, len);
    for (int i = 0; i < len; i++) {
        idx = word[i] - 'a';
        if (!tmp->arr[idx])
            tmp->arr[idx] = calloc(1, sizeof(Trie));
        tmp = tmp->arr[idx];
    }
    tmp->is_word = true;
    return;
}

bool trieSearch(Trie* obj, char * word) {  
    Trie *tmp = obj;
    int len = strlen(word), idx = 0;
    for (int i = 0; i < len; i++) {
        idx = word[i] - 'a';
        if (!tmp->arr[idx])
            return false;
        tmp = tmp->arr[idx];
    }
    return tmp->is_word;
}

bool trieStartsWith(Trie* obj, char * prefix) {
    Trie *tmp = obj;
    int len = strlen(prefix), idx = 0;
    for (int i = 0; i < len; i++) {
        idx = prefix[i] - 'a';
        if (!tmp->arr[idx])
            return false;
        tmp = tmp->arr[idx];
    }
    return true;
}

void trieFree(Trie* obj) {
    for (int i = 0; i < 26; i++) {
        if (obj->arr[i])
            trieFree(obj->arr[i]);
    }
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
