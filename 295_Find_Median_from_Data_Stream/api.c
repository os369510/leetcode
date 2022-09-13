typedef struct _node {
    int val;
    struct _node *prev;
    struct _node *next;
} NODE;
typedef struct {
    NODE *mid;
    int count;
    NODE *head;
} MedianFinder;


MedianFinder* medianFinderCreate() {
    return calloc(1, sizeof(MedianFinder));
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    NODE *new = calloc(1, sizeof(NODE)), *tmp = obj->head, *prev = NULL;
    bool found_mid = false;
    new->val = num;
    obj->count++;
    if (!tmp) {
        obj->head = new;
        obj->mid = new;
        return;
    }
    if (num > obj->mid->val)
        tmp = obj->mid;
    prev = tmp;
    while (tmp) {
        if (obj->mid == tmp)
            found_mid = true;
        if (tmp->val > new->val) {
            if (obj->mid == tmp)
                found_mid = false;
            new->next = tmp;
            tmp->prev = new;
            if (tmp == obj->head)// the first element
                obj->head = new;
            else {
                prev->next = new;
                new->prev = prev;
            }
            goto exit;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    prev->next = new;
    new->prev = prev;
exit:
    if (!found_mid) { // left
        if (obj->count % 2 == 0)
            obj->mid = obj->mid->prev;
    }
    else { // right
        if (obj->count % 2)
            obj->mid = obj->mid->next;
    }
    return;
}

double medianFinderFindMedian(MedianFinder* obj) {
    double ret = 0;
    bool even = false;
    if (obj->count % 2 == 0)
        even = true;
    ret = obj->mid->val;
    if (even) {
        ret += obj->mid->next->val;
        ret /= 2;
    }
    return ret;
}

void medianFinderFree(MedianFinder* obj) {
    NODE *tmp = obj->head, *next = NULL;;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(obj);
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);
 
 * double param_2 = medianFinderFindMedian(obj);
 
 * medianFinderFree(obj);
*/
