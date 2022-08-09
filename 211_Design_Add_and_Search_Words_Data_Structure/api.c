


typedef struct {
    struct WordDictionary *c[26];
    bool is_word;
} WordDictionary;


WordDictionary* wordDictionaryCreate() {
    WordDictionary *head = calloc(1, sizeof(WordDictionary));
    return head;
}

void wordDictionaryAddWord(WordDictionary* obj, char * word) {
    WordDictionary *cur = obj;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        int idx = word[i] - 'a';
        if (!cur->c[idx])
            cur->c[idx] = calloc(1, sizeof(WordDictionary));
        cur = cur->c[idx];
    }
    cur->is_word = true;
}

bool wordDictionarySearch(WordDictionary* obj, char * word) {
    WordDictionary *cur = obj;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        // handle '.'
        if (word[i] == '.') {
            bool ret;
            for (int j = 0; j < 26; j++) {
                if (!cur->c[j])
                    continue;
                ret = wordDictionarySearch(cur->c[j], &word[i + 1]);
                if (ret)
                    return ret;
            }
            return false;
        }
        // normal english letters
        int idx = word[i] - 'a';
        if (!cur->c[idx])
            return false;
        cur = cur->c[idx];
    }
    return cur->is_word;
}

void wordDictionaryFree(WordDictionary* obj) {
    if (!obj) return;
    for (int i = 0; i < 26; i++) {
        if (obj->c[i])
            wordDictionaryFree(obj->c[i]);
    }
    free(obj);
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 
 * bool param_2 = wordDictionarySearch(obj, word);
 
 * wordDictionaryFree(obj);
*/
