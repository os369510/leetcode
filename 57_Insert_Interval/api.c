/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    int **ret, idx = 0, merged = 0, found = 0, tmp = 0;
    ret = calloc(intervalsSize + 1, sizeof(int*));
    // Handle edge case on the beginning
    if (!intervalsSize) {
        ret[0] = calloc(2, sizeof(int));
        ret[0][0] = newInterval[0];
        ret[0][1] = newInterval[1];
        idx++;
        goto end;
    }
    // Make sure intervals[0] is minimux start
    if (intervals[0][0] > newInterval[0]) {
        // swap
        tmp = intervals[0][0];
        intervals[0][0] = newInterval[0];
        newInterval[0] = tmp;
        
        tmp = intervals[0][1];
        intervals[0][1] = newInterval[1];
        newInterval[1] = tmp;
    }
    // compare and merge
    for (int i = 0; i < intervalsSize; i++) {
        if (!ret[idx]) {
            ret[idx] = calloc(2, sizeof(int));
        }
        if (!found) {
            ret[idx][0] = intervals[i][0];
            ret[idx][1] = intervals[i][1];
            found = 1;
            if (i == intervalsSize - 1)
                idx++;
            continue;
        }
        // merge to ret
        if (newInterval[0] <= ret[idx][1]) {
            // merge
            if (newInterval[1] > ret[idx][1])
                ret[idx][1] = newInterval[1];
            merged = 1;
        }
        /**
          * merge to interval
          * il <-> nl <-> ir <-> nr
          * nl <-> il <-> ir <-> nr
          * nl <-> il <-> nr <-> ir
          * il <-> nl <-> nr <-> ir
          */
        else if (newInterval[0] <= intervals[i][1] && newInterval[1] >=  intervals[i][0]) {
            if (newInterval[0] < intervals[i][0]) {
                intervals[i][0] = newInterval[0];
            }
            if (newInterval[1] > intervals[i][1]) {
                intervals[i][1] = newInterval[1];                
            }
            merged = 1;
        }
        // dont merge but insert (the region between two region)
        else if (newInterval[0] > ret[idx][1] && newInterval[1] < intervals[i][0]) {
            idx++;
            ret[idx] = calloc(2, sizeof(int));
            ret[idx][0] = newInterval[0];
            ret[idx][1] = newInterval[1];
            merged = 1;
        }
        if (intervals[i][0] <= ret[idx][1]) {
            // merge
            if (intervals[i][1] > ret[idx][1])
                ret[idx][1] = intervals[i][1];
            if (i == intervalsSize - 1)
                idx++;
        }
        else {
            idx++;
            i--;
            found = 0;
        }
    }
    // if the region after last intervals
    if (!merged) {        
        if (newInterval[0] <= ret[idx - 1][1]) {
            // merge
            if (newInterval[1] > ret[idx - 1][1])
                ret[idx - 1][1] = newInterval[1];
            merged = 1;
        }
        else {
            ret[idx] = calloc(2, sizeof(int));
            ret[idx][0] = newInterval[0];
            ret[idx][1] = newInterval[1];
            idx++;
        }
    }
end:
    *returnSize = idx;
    *returnColumnSizes = calloc(idx, sizeof(int));
    for (int i = 0; i < idx; i++)
        (*returnColumnSizes)[i] = 2;
    return ret;
}
