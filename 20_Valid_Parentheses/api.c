struct node {
    struct node *next;
    struct node *prev;
    char v;
};
struct node * push(struct node *cur, char c) {
    struct node *new = calloc(1, sizeof(struct node));
    cur->next = new;
    new->prev = cur;
    new->v = c;
    return new;
}
char pop(struct node **cur) {
    char ret = (*cur)->v;
    struct node *tmp = *cur;
    if ((*cur)->prev) {
        *cur = (*cur)->prev;
        (*cur)->next = NULL;
    }
    free(tmp);
    return ret;
}
void dump(struct node *head) {
    struct node *tmp = head;
    while (tmp) {
        printf("%c", tmp->v);
        tmp = tmp->next;
    }
    printf("\n");
}

bool isValid(char * s){
    int i = 0, len = strlen(s);
    struct node *cur = calloc(1, sizeof(struct node));
    struct node *head = cur;
    char r;
    cur->v = 1;
    for (i = 0; i < len; i++) {
        switch (s[i]) {
            case '(':
                cur = push(cur, '(');
                break;
            case '{':
                cur = push(cur, '{');
                break;
            case '[':
                cur = push(cur, '[');
                break;
            case ')':
                r = pop(&cur);
                if (r != '(')
                    return false;
                break;
            case '}':
                r = pop(&cur);
                if (r != '{')
                    return false;
                break;
            case ']':
                r = pop(&cur);
                if (r != '[')
                    return false;
                break;
        }
        //dump(head);
    }
    if (cur->v != 1)
        return false;
    return true;
}
