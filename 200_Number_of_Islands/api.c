void visit_lands(char **grid, int y, int x, int h, int w) {
    if (y < 0 || x < 0 || y >= h || x >= w || grid[y][x] != '1')
        return;
    grid[y][x] = '2';
    
    visit_lands(grid, y, x - 1, h, w);
    visit_lands(grid, y, x + 1, h, w);
    visit_lands(grid, y - 1, x, h, w);
    visit_lands(grid, y + 1, x, h, w);
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int count = 0;
    int w = gridColSize[0];
    for (int y = 0; y < gridSize; y++) {
        for (int x = 0; x < w; x++) {
            if (grid[y][x] == '1') {
                count++;
                visit_lands(grid, y, x, gridSize, w);
            }
        }
    }
    return count;
}
