

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minOperations(char * boxes, int* returnSize){
    int i = 0, len = strlen(boxes);
    int *ret = calloc(len, sizeof(int)), j = 0;
    for (i = 0; i < len; i++) {
        for (j = 0; j < len; j++) {
            if (i == j || boxes[j] == '0')
                continue;
            ret[i] += abs(j - i);
        }
    }
    *returnSize = len;
    return ret;
}
