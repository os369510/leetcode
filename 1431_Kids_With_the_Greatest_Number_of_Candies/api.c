/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize){
    int i = 0, max = candies[0];
    bool *ret = calloc(candiesSize, sizeof(bool));
    *returnSize = candiesSize;
    for (i = 1; i < candiesSize; i++) {
        if (candies[i] > max)
            max = candies[i];
    }
    for (i = 0; i < candiesSize; i++) {
        if (extraCandies >= max - candies[i])
            ret[i] = true;
    }
    return ret;
}
