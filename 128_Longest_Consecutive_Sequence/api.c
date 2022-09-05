struct node {
    int value;
    UT_hash_handle hh;
};
int longestConsecutive(int* nums, int numsSize){
    struct node *map = NULL, *tmp = NULL;
    int max = 0;
    for (int i = 0; i < numsSize; i++) {
        /*
        HASH_FIND_INT(map, &nums[i], tmp);
        if (tmp)
            continue;*/
        tmp = calloc(1, sizeof(struct node));
        tmp->value = nums[i];        
        HASH_ADD_INT(map, value, tmp);
    }
    for (int i = 0; i < numsSize; i++) {
        int lmax = 0, pre = nums[i] - 1, next = nums[i];
        HASH_FIND_INT(map, &pre, tmp);
        if (tmp) continue;
        while (1) {
            HASH_FIND_INT(map, &next, tmp);
            if (!tmp) break;
            lmax++;
            next = tmp->value + 1;
        }
        max = fmax(max, lmax);
    }
    return max;
}

