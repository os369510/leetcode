void get_idx(int point, int l, int *x, int *y) {
    *y = point / l;
    *x = point % l;
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int x, y, pre = 0;
    int idx = matrixSize * matrixColSize[0] / 2;
    int start = 0, tail = matrixSize * matrixColSize[0];
    tail = (tail)? tail - 1 : 0;
    get_idx(start, matrixColSize[0], &x, &y);
    if (matrix[y][x] == target)
        return true;
    get_idx(tail, matrixColSize[0], &x, &y);
    if (matrix[y][x] == target)
        return true;
    while (1) {
        pre = idx;
        get_idx(idx, matrixColSize[0], &x, &y);
        if (matrix[y][x] == target)
            return true;
        else if (matrix[y][x] > target) {
            // goes to left
            tail = idx;
            idx = (start + idx) / 2;
        }
        else {
            // goes to right
            start = idx;
            idx = (idx + tail) / 2;
        }
        if (pre == idx)
            return false;
    }
}
