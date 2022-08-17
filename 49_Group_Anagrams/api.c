struct dict;
struct arr_elem;
struct group;
struct dict {
    char c[26];
};
struct arr_elem {
    int idx;
    struct dict d;
    struct group *g;
    struct arr_elem *next;
};
struct group {
    struct arr_elem *first;
    struct arr_elem *last;
    struct group *next;
};

struct group * find_match_group(struct group *head, struct dict d) {
    while (head) {
        if (!memcmp(head->first->d.c, d.c, 26))
            return head;
        head = head->next;
    }
    return NULL;
}
void * append_new_group(struct group **head, struct arr_elem *elem, int *count) {
    int gc = 1;
    struct group *_head = NULL, *tmp = NULL, *_tmp = NULL;
    tmp = *head;
    if (!(*head)) {
        (*head) = calloc(1, sizeof(struct group));
        (*head)->first = (*head)->last = elem;
        *count = gc;
        return;
    }
    while (tmp) {
        if (!tmp->next)
            break;
        tmp = tmp->next;
        gc++;
    }
    _tmp = calloc(1, sizeof(struct group));
    tmp->next = _tmp;
    _tmp->first = _tmp->last = elem;
    *count = gc + 1;
    return;
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    struct arr_elem *s = NULL;
    struct group *g = NULL;
    int gc = 0;
    s = calloc(10000, sizeof(struct arr_elem));
    for (int i = 0; i < strsSize; i++) {
        struct group *tmp = NULL;
        s[i].idx = i;
        for (int j = 0; j < strlen(strs[i]); j++)
            s[i].d.c[strs[i][j] - 'a']++;
        tmp = find_match_group(g, s[i].d);
        if (!tmp)
            append_new_group(&g, &s[i], &gc);
        else {
            tmp->last->next = &s[i];
            tmp->last = &s[i];
        }
    }
    struct group *tmp = g;
    int cg = 0, cw = 0;
    (*returnColumnSizes) = calloc(gc, sizeof(int));
    while (tmp) {
        struct arr_elem *s = tmp->first;
        while (s) {
            (*returnColumnSizes)[cg]++;
            s = s->next;
        }
        cg++;
        tmp = tmp->next;
    }
    *returnSize = gc;
    char ***ret;
    ret = calloc(gc, sizeof(char**));
    for (int i = 0; i < gc; i++) {
        ret[i] = calloc((*returnColumnSizes)[i], sizeof(char*));
    }
    cg = 0;
    tmp = g;
    while (tmp) {
        cw = 0;
        struct arr_elem *s = tmp->first;
        while (s) {
            ret[cg][cw] = strs[s->idx];
            cw++;
            s = s->next;
        }
        cg++;
        tmp = tmp->next;
    }
    return ret;
}
