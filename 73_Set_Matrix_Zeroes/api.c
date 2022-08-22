void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    uint64_t x[4] = {0}, y[4] = {0};
    int w = matrixColSize[0];
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < w; j++) {
            if (matrix[i][j])
                continue;
            x[j / 64] |= (uint64_t)((uint64_t)1 << (j % 64));
            y[i / 64] |= (uint64_t)((uint64_t)1 << (i % 64));
        }
    }
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < w; j++) {
            if ((x[j / 64] & (uint64_t)((uint64_t)1 << (j % 64))) || (y[i / 64] & (uint64_t)((uint64_t)1 << (i % 64)))) {
                matrix[i][j] = 0;
            }
        }
    }
    return;
}
