struct trie_node {
    struct trie_node* n[26];
    bool word; // true if presents in dict
};

int cache[300]= {-1};

int find_string(char *str, int start, struct trie_node *head) {
    struct trie_node *cur = head;
    int len = strlen(str);
    int ret = 0;
    
    if (len == start)
        return 1;
    if (cache[start] != -1)
        return cache[start];
    
    for (int i = start; i < len; i++) {
        int idx = str[i] - 'a';
        if (!cur->n[idx])
            break;
        cur = cur->n[idx];
        if (cur->word)
            ret |= find_string(str, i + 1, head);
    }
    cache[start] = ret? 1 : 0;
    return cache[start];
}
bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    struct trie_node instance = {0}, *head = &instance, *cur = head;
    for (int i = 0; i < wordDictSize; i++) {
        int len = strlen(wordDict[i]);
        cur = head;
        for (int j = 0; j < len; j++) {
            char c = wordDict[i][j];
            int idx = c - 'a';
            if (!cur->n[idx]) {
                cur->n[idx] = calloc(1, sizeof(struct trie_node));
            }
            if (j == len - 1) {
                cur->n[idx]->word = true;
            }
            cur = cur->n[idx];
        }        
    }
    memset(cache, -1, 300 * sizeof(int));
    return find_string(s, 0, head);
}
