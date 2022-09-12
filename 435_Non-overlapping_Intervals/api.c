int cmp (const void * pa, const void * pb)
{
    const int *a = *(const int **)pa;
    const int *b = *(const int **)pb;
    if(a[0] == b[0])
        return a[1] - b[1];
    else
        return a[0] - b[0];
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    int count = 0, s = 0, e = 0;
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    s = e = intervals[0][0] - 1;
    for (int i = 0; i < intervalsSize; i++) {
        // case 1. [1,2] [1,2]
        if (intervals[i][0] == s && intervals[i][1] == e)
            count++;
        // case 2. [1,2] [1,3]
        else if (intervals[i][0] == s && intervals[i][1] > e)
            count++;
        // case 3. [1,4] [2,3]
        else if (intervals[i][0] > s && intervals[i][0] < e &&
                 intervals[i][1] < e) {
            count++;
            s = intervals[i][0];
            e = intervals[i][1];
        }
        // case 4. [1,4] [2,4]
        else if (intervals[i][0] > s && intervals[i][1] == e) {
            count++;
            s = intervals[i][0];
        }
        // case 5. [1,4] [2,5]
        else if (intervals[i][0] > s && intervals[i][0] < e &&
                 intervals[i][1] > e)
            count++;
        // case 6. [1,4] [4,5]
        // case 7. [1,4] [5,6]
        else {
            s = intervals[i][0];
            e = intervals[i][1];
            continue;
        }
    }
    return count;
}
