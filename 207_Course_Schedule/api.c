typedef struct _lesson {
    bool learned;
    char blocked;
    short len;
    short preqc[2000];
} lesson;
lesson lessons[2000];

bool try2learn(int noc, int c) {
    // if learned, then don't learn again
    if (lessons[c].learned) return true;
    // if a lesson is blocked, then deadlock
    if (lessons[c].blocked >= 2) return false;
    // to see if any course is preq
    for (int i = 0; i < lessons[c].len; i++) {
        int prereqc = lessons[c].preqc[i];
        int ret = true;
        lessons[prereqc].blocked++;
        ret = try2learn(noc, prereqc);
        if (!ret) return ret;
        lessons[prereqc].blocked = 0;
    }
    // learned
    lessons[c].learned = true;
    return true;
}
bool canFinish(int numCourses, int** prers, int prerequisitesSize, int* prerequisitesColSize){
    bool ret = true;
    // initialize
    memset(lessons, 0, numCourses * sizeof(lesson));

    // build relationship
    for (int i = 0; i < prerequisitesSize; i++) {
        int c = prers[i][0], prereqc = prers[i][1];
        lessons[c].preqc[lessons[c].len] = prereqc;
        lessons[c].len++;
    }
    // solving
    for (int i = 0; i < numCourses; i++) {
        ret = try2learn(numCourses, i);
        if (!ret) break;
    }
    return ret;
}
