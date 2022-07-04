enum stm {
    right,
    down,
    left,
    up,
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    enum stm _stm = right;
    int x = -1, y = 0;
    int n = matrixSize, m = matrixColSize[0];
    *returnSize = m * n;
    int *ret = calloc(*returnSize, sizeof(int)), idx = 0, loop = 0, b = 0, moved = 0;
    while (1) {
        switch(_stm) {
            case right:
                if (!moved) {
                    if (x + 1 == (m - loop)){
                        b = 1;
                        break;
                    }
                    x++;
                    moved = 1;
                }
                ret[idx++] = matrix[y][x++];
                if (x == (m - loop)){
                    x--;
                    moved = 0;
                    _stm = down;
                    continue;
                }
                break;
            case down:
                if (!moved) {
                    if (y + 1 == (n - loop)){
                        b = 1;
                        break;
                    }
                    y++;
                    moved = 1;
                }
                ret[idx++] = matrix[y++][x];
                if (y == (n - loop)){
                    y--;
                    moved = 0;
                    _stm = left;
                    continue;
                }
                break;
            case left:
                if (!moved) {
                    if (x - 1 == (loop - 1)){
                        b = 1;
                        break;
                    }
                    x--;
                    moved = 1;
                }
                ret[idx++] = matrix[y][x--];
                if (x == (loop - 1)){
                    x++;
                    moved = 0;
                    _stm = up;
                    continue;
                }
                break;
            case up:
                if (!moved) {
                    if (y - 1 == loop){
                        b = 1;
                        break;
                    }
                    y--;
                    moved = 1;
                }
                ret[idx++] = matrix[y--][x];
                if (y == loop){
                    y++;
                    moved = 0;
                    _stm = right;
                    loop++;
                    continue;
                }
                break;
        }
        if (b)
            break;
    }
    return ret;
}
