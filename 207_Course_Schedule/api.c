typedef struct _rs {
    bool *preq;
} rs;
rs *rss;

typedef struct _solver {
    bool *learned;
    int *blocked;
} solver;
solver *s;

bool try2learn(int noc, int c) {   
    bool ret = true;
    // if learned, then don't learn again
    if (s->learned[c]) return true;
    // if a lesson is blocked, then deadlock
    if (s->blocked[c] >= 2) return false;
    // to see if any course is preq
    for (int i = 0; i < noc; i++) {
        if (rss[c].preq[i]) {
            s->blocked[i]++;
            ret = try2learn(noc, i);
            if (!ret) return ret;
            s->blocked[i] = 0;
        }
    }
    // learned
    s->learned[c] = true;
    return true;
}
bool canFinish(int numCourses, int** prers, int prerequisitesSize, int* prerequisitesColSize){
    bool ret = true;
    // initialize
    rss = calloc(numCourses, sizeof(rs));
    for (int i = 0; i < numCourses; i++) {
        rss[i].preq = calloc(numCourses, sizeof(bool));
    }
    s = calloc(1, sizeof(solver));
    s->learned = calloc(numCourses, sizeof(bool));
    s->blocked = calloc(numCourses, sizeof(int));
    
    // build relationship
    for (int i = 0; i < prerequisitesSize; i++) {
        int c = prers[i][0], prec = prers[i][1];
        rss[c].preq[prec] = true;
    }
    // solving
    for (int i = 0; i < numCourses; i++) {
        ret = try2learn(numCourses, i);
        if (!ret) break;
    }
    // free
    free(s->blocked);
    free(s->learned);
    free(s);
    for (int i = 0; i < numCourses; i++) {
        free(rss[i].preq);
    }
    free(rss);

    return ret;
}
