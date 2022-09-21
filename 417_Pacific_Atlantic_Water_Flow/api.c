#include <sys/queue.h>

struct entry {
    int y;
    int x;
    TAILQ_ENTRY(entry) entries;
};

struct result {
    int preachable;
    int areachable;
};
struct record {
    int visit;
    struct result res;
};

struct record **cache;

struct result BFS(int** heights, int w, int h, int y, int x) {
    struct result res = {0};
    
    if (cache[y][x].visit) return res;
    
    TAILQ_HEAD(tailhead, entry) head;
    TAILQ_INIT(&head);
    
    if (y == 0 || x == 0)
        cache[y][x].res.preachable = 1;
    if (y == h - 1 || x == w - 1)
        cache[y][x].res.areachable = 1;

    // left
    if (x - 1 >= 0 && heights[y][x] >= heights[y][x-1]) {
        if (cache[y][x-1].visit == 1) {
            cache[y][x].res.preachable |= cache[y][x-1].res.preachable;
            cache[y][x].res.areachable |= cache[y][x-1].res.areachable;
        }
        else {
            struct entry *eleml;
            eleml = malloc(sizeof(struct entry));
            eleml->y = y;
            eleml->x = x-1;
            TAILQ_INSERT_TAIL(&head, eleml, entries);
        }
    }
    // down
    if (y + 1 < h && heights[y][x] >= heights[y+1][x]) {
        if (cache[y+1][x].visit == 1) {
            cache[y][x].res.preachable |= cache[y+1][x].res.preachable;
            cache[y][x].res.areachable |= cache[y+1][x].res.areachable;
        }
        else {
            struct entry *elemd;
            elemd = malloc(sizeof(struct entry));
            elemd->y = y+1;
            elemd->x = x;
            TAILQ_INSERT_TAIL(&head, elemd, entries);
        }
    }
    // right
    if (x + 1 < w && heights[y][x] >= heights[y][x+1]) {
        if (cache[y][x+1].visit == 1) {
            cache[y][x].res.preachable |= cache[y][x+1].res.preachable;
            cache[y][x].res.areachable |= cache[y][x+1].res.areachable;
        }
        else {
            struct entry *elemr;
            elemr = malloc(sizeof(struct entry));
            elemr->y = y;
            elemr->x = x+1;
            TAILQ_INSERT_TAIL(&head, elemr, entries);
        }
    }
    // up
    if (y - 1 >= 0 && heights[y][x] >= heights[y-1][x]) {
        if (cache[y-1][x].visit == 1) {
            cache[y][x].res.preachable |= cache[y-1][x].res.preachable;
            cache[y][x].res.areachable |= cache[y-1][x].res.areachable;
        }
        else {
            struct entry *elemu;
            elemu = malloc(sizeof(struct entry));
            elemu->y = y-1;
            elemu->x = x;
            TAILQ_INSERT_TAIL(&head, elemu, entries);
        }
    }
    
    cache[y][x].visit = 1;
    
    // process the queue
    while (!TAILQ_EMPTY(&head)) {
        struct entry *elem;
        struct result tmp_res = {0};
        elem = TAILQ_FIRST(&head);
        tmp_res = BFS(heights, w, h, elem->y, elem->x);
        cache[y][x].res.preachable |= tmp_res.preachable;
        cache[y][x].res.areachable |= tmp_res.areachable;
        TAILQ_REMOVE(&head, elem, entries);
        free(elem);
    }
    
    res.preachable = cache[y][x].res.preachable;
    res.areachable = cache[y][x].res.areachable;
    return res;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes){
    int w = heightsColSize[0];
    int h = heightsSize;
    int count = 0, **ret = NULL;
    // allocate
    cache = calloc(h, sizeof(struct record*));
    ret = calloc(w*h, sizeof(int*));
    *returnColumnSizes = calloc(w*h, sizeof(int*));
    for (int i = 0; i < h; i++)
        cache[i] = calloc(w, sizeof(struct record));
    for (int i = 0; i < w*h; i++) {
        ret[i] = calloc(2, sizeof(int));
        (*returnColumnSizes)[i] = 2;
    }
    
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            /**
            * marked it as not yet visit for a edge case, something like
            *   2,15,18,11,15
            *  17,11, 3,14, 0
            *  17,10,19,17, 6
            *  11,10,19, 3,15
            */
            cache[y][x].visit = 0;
            BFS(heights, w, h, y, x);
        }
    }
    
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (!cache[y][x].res.preachable || !cache[y][x].res.areachable)
                continue;
            ret[count][0] = y;
            ret[count][1] = x;
            count++;
        }
    }
    *returnSize = count;
    
    // free
    for (int i = 0; i < h; i++)
        free(cache[i]);
    free(cache);
    
    return ret;
}
