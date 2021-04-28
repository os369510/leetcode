

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decode(int* encoded, int encodedSize, int first, int* returnSize){
    int *ret = calloc(encodedSize + 1, sizeof(int)), i = 0;
    *returnSize = encodedSize + 1;
    ret[0] = first;
    for (i = 0; i < *returnSize - 1; i++) {
        ret[i + 1] = ret[i] ^ encoded[i];
    }
    return ret;
}
