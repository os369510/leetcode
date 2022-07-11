char **record;
bool _exist(char** board, int y, int x, int h, int w, char * word, int wi) {
    bool ret = 0;
    if (record[y][x])
        return false;
    if (board[y][x] != word[wi])
        return false;
    
    record[y][x] = 1;
    wi++;
    if (!word[wi])
        return true;
    
    if (y >= 1 && !ret)
        ret |= _exist(board, y - 1, x, h, w, word, wi);
    if (y + 1 < h && !ret)
        ret |= _exist(board, y + 1, x, h, w, word, wi);
    if (x + 1 < w && !ret)
        ret |= _exist(board, y, x + 1, h, w, word, wi);
    if (x >= 1 && !ret)
        ret |= _exist(board, y, x - 1, h, w, word, wi);
    if (!ret) {
        record[y][x] = 0;
        wi--;
    }
    return ret;
}
bool exist(char** board, int boardSize, int* boardColSize, char * word){
    bool ret;
    record = calloc(boardSize, sizeof(char*));
    // Allocate
    for (int i = 0; i < boardSize; i++)
        record[i] = calloc(boardColSize[0], sizeof(char));
    // DFS
    for (int y = 0; y < boardSize && !ret; y++) {
        for (int x = 0; x < boardColSize[0] && !ret; x++) {
            for (int i = 0; i < boardSize; i++)
                memset(record[i], 0, boardColSize[0]);
            ret = _exist(board, y, x, boardSize, boardColSize[0], word, 0);
        }
    }
    // Free
    for (int i = 0; i < boardSize; i++) {
        free(record[i]);
    }
    free(record);
    return ret;
}
