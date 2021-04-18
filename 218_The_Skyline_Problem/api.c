#include <stdio.h>
#include <stdlib.h>
// Implement as heap sort
typedef struct _node {
    int x;
    int y;
    int my_line;
} NODE;

//#define DEBUG

#define IN
#define OUT
#define INOUT

#define UP 1
#define DOWN -1

void print_heap(NODE **nodes, int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        printf("[%d,%d] ", nodes[i]->x, nodes[i]->y);
    }
    printf("\n");
}

void swap(NODE **a, NODE **b) {
    NODE *tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapifyx(NODE **nodes, int nodes_size, int idx) {
    int largest = idx;
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;
    if (l < nodes_size) {
        if (nodes[l]->x > nodes[largest]->x)
            largest = l;
        else if ((nodes[l]->x == nodes[largest]->x) &&
                 (nodes[l]->y < nodes[largest]->y))
            largest = l;
    }
    
    if (r < nodes_size) {
        if (nodes[r]->x > nodes[largest]->x)
            largest = r;
        else if ((nodes[r]->x == nodes[largest]->x) &&
                 (nodes[r]->y < nodes[largest]->y))
            largest = r;
    }

    if (largest != idx) {
        swap(&nodes[largest], &nodes[idx]);
        heapifyx(nodes, nodes_size, largest);
    }
    
}

void heapifyy(NODE **nodes, int nodes_size, int idx) {
    int largest = idx;
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;
    
    if (l < nodes_size) {
        if (nodes[l]->y > nodes[largest]->y)
            largest = l;
        else if ((nodes[l]->y == nodes[largest]->y) &&
                 (nodes[l]->x > nodes[largest]->x))
            largest = l;
    }
    
    if (r < nodes_size) {
        if (nodes[r]->y > nodes[largest]->y)
            largest = r;
        else if ((nodes[r]->y == nodes[largest]->y) &&
                 (nodes[r]->x > nodes[largest]->x))
            largest = r;
    }

    if (largest != idx) {
        swap(&nodes[largest], &nodes[idx]);
        heapifyy(nodes, nodes_size, largest);
    }
    
}

/*
 * OUT int **arr: the array of points
 * OUT int *len: the length of array
 */
void build_four_points_each_building(IN int **buildings, INOUT int buildingsSize,
        OUT NODE ***arr, OUT int *len) {
    int i = 0, idx = 0;
    NODE **larr = NULL;
    *len = buildingsSize * 4;
    larr = (NODE**) calloc(*len, sizeof(NODE*));
    for (i = 0; i < buildingsSize; i++) {
        idx = i * 4;
        larr[idx] = calloc(1, sizeof(NODE));
        larr[idx + 1] = calloc(1, sizeof(NODE));
        larr[idx + 2] = calloc(1, sizeof(NODE));
        larr[idx + 3] = calloc(1, sizeof(NODE));
        
        larr[idx]->x = buildings[i][0];
        larr[idx]->y = buildings[i][2];
        larr[idx + 1]->x = buildings[i][0];
        larr[idx + 1]->y = 0;
        larr[idx + 2]->x = buildings[i][1];
        larr[idx + 2]->y = buildings[i][2];
        larr[idx + 3]->x = buildings[i][1];
        larr[idx + 3]->y = 0;
        
        larr[idx]->my_line = \
            larr[idx + 1]->my_line = \
            larr[idx + 2]->my_line = \
            larr[idx + 3]->my_line = i;
    }
    *arr = larr;
    return;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** getSkyline(int** buildings, int buildingsSize, int* buildingsColSize,
        int* returnSize, int** returnColumnSizes){
    int i = 0, j = 0, dir = 0, len_of_nodes = 0;
    NODE **nodes = NULL, **nodesy = NULL;
#ifdef DEBUG
    printf("start\n");
#endif
    build_four_points_each_building(
            buildings, buildingsSize, &nodes, &len_of_nodes);
#ifdef DEBUG
    //printf("after building\n");
    //print_heap(nodes, len_of_nodes);
#endif
    // heapify by x
    for (i = len_of_nodes / 2; i >= 0; i--) {
        heapifyx(nodes, len_of_nodes, i);
    }
    // sort as min heap by x
    for (i = len_of_nodes - 1; i >= 0; i--) {
        swap(&nodes[0], &nodes[i]);
        heapifyx(nodes, i, 0);
    }

    nodesy = calloc(len_of_nodes, sizeof(NODE*));
    for (i = 0; i < len_of_nodes; i++) {
        nodesy[i] = nodes[i];
    }

    // heapify by y
    for (i = len_of_nodes / 2; i >= 0; i--) {
        heapifyy(nodesy, len_of_nodes, i);
    }
    // sort as min heap by y
    for (i = len_of_nodes - 1; i >= 0; i--) {
        swap(&nodesy[0], &nodesy[i]);
        heapifyy(nodesy, i, 0);
    }
#ifdef DEBUG
    printf("after heapify: x and y\n");
    print_heap(nodes, len_of_nodes);
    print_heap(nodesy, len_of_nodes);
#endif

    NODE **retn = calloc(1, sizeof(NODE*));
    *retn = calloc(1, sizeof(NODE));
    retn[0]->x = nodes[len_of_nodes - 1]->x;
    retn[0]->y = nodes[len_of_nodes - 1]->y;

    int idx = 0, pick_y_h = 0, pick_y_l = 0, max_x = 0, min_x = 0;
    int hit_wall = 0, hit_wall_bot = 0, hit_edge = 0, falling_edge = 0;
    int hit_ceiling = 0, hit_ceiling_edge = 0;
    int curr_x = 0, curr_y = 0, something_left = 0;

    curr_x = retn[0]->x;
    curr_y = retn[0]->y;
    dir = 0;
    while (1) {
        if (dir == 0) {
#ifdef DEBUG
            printf("* dir = 0: curr_x %d, curr_y %d\n", curr_x, curr_y);
#endif
            // find the ceiling
            for (j = 0, pick_y_l = curr_y, hit_ceiling = 0; j < buildingsSize; j++) {
                if (curr_x < buildings[j][1] &&
                    curr_x > buildings[j][0]) {
#ifdef DEBUG
                    printf("find a ceiling %d %d %d\n", buildings[j][0], buildings[j][1], buildings[j][2]);
#endif
                    // only one possible that the buildings-y less than curr_y
                    if (curr_y > buildings[j][2]) {
                        if (pick_y_l == curr_y)
                            pick_y_l =buildings[j][2];
                        else if (pick_y_l < buildings[j][2])
                            pick_y_l = buildings[j][2];
#ifdef DEBUG
                        printf("hit ceiling\n");
#endif
                        hit_ceiling = 1;
                    }
                }
            }
            // find edge
            for (i = len_of_nodes - 1, pick_y_h = curr_y, hit_ceiling_edge = 0;
                 i >= 0 && nodes[i]->x >= curr_x;
                 i--) {
                if (curr_x == nodes[i]->x &&
                    curr_y == nodes[i]->y)
                    continue;
                if (nodes[i]->x == curr_x) {
#ifdef DEBUG
                    printf("hc %d hce %d pyl %d cy %d ny %d\n", hit_ceiling, hit_ceiling_edge, pick_y_l, curr_y, nodes[i]->y);
#endif
                    if (nodes[i]->y > pick_y_h) {
#ifdef DEBUG
                        printf("could go up %d %d\n", nodes[i]->x, nodes[i]->y);
#endif
                        pick_y_h = nodes[i]->y;
                        dir = UP;
                    }
                    else if (!hit_ceiling &&
                             !hit_ceiling_edge) {
                        if (pick_y_l == curr_y ||
                            nodes[i]->y < pick_y_l) {
#ifdef DEBUG
                            printf("found bottom point %d %d\n", nodes[i]->x, nodes[i]->y);   
#endif                     
                            pick_y_l = nodes[i]->y;
                        }
                        else if (nodes[i]->y > pick_y_l &&
                                 buildings[nodes[i]->my_line][0] < curr_x) {
                            hit_ceiling_edge = 1;
#ifdef DEBUG
                            printf("found a hit ceiling edge %d %d\n", nodes[i]->x, nodes[i]->y);         
#endif                                    
                            pick_y_l = nodes[i]->y;
                        }
                    }
                }
            }
            if (dir == UP)
                curr_y = pick_y_h;
            else {
                dir = DOWN;
                curr_y = pick_y_l;
            }
#ifdef DEBUG
            printf("curr_x %d, curr_y %d, dir is %d\n", curr_x, curr_y, dir);
#endif                     
        }
        else if (dir != 0) {
#ifdef DEBUG
            printf("* dir = 1: curr_x %d, curr_y %d\n", curr_x, curr_y);
#endif                     
            something_left = 0;
            // find if a wall if blocking in left side (non-edge case)
            for (j = 0, max_x = curr_x; j < buildingsSize; j++) {
                if (buildings[j][2] > curr_y) {
                    if (buildings[j][1] < curr_x) {
                        if (max_x == curr_x) {
                            max_x = buildings[j][1];
                        }
                        else if (max_x < buildings[j][1]) {
                            max_x = buildings[j][1];
                        }
                        something_left = 1;
                        hit_wall = 1;
#ifdef DEBUG
                        printf("hit_wall %d %d\n", buildings[j][1], buildings[j][2]);
#endif                     
                    }
                }
            }
            for (i = len_of_nodes - 1, min_x = curr_x;
                 i >= 0 && nodesy[i]->y >= curr_y;
                 i--) {
                if (nodesy[i]->y == curr_y) {
                    // if the wall is in left side of cursor
                    if (nodesy[i]->x < curr_x) {
                        something_left = 1;
                        // if this wall blocks skyline (if y = 0 case only)
                        if (buildings[nodesy[i]->my_line][2] > curr_y) {
                            if (max_x == curr_x ||
                                nodesy[i]->x > max_x) {
                                max_x = nodesy[i]->x;
#ifdef DEBUG
                                printf("hit_wall_bot %d %d\n", nodesy[i]->x, nodesy[i]->y);
#endif                     
                                hit_wall_bot = 1;
                            }
                        }
                        // store the result and looking for next
                        else if (buildings[nodesy[i]->my_line][2] = curr_y) {
                            if (min_x == curr_x ||
                                nodesy[i]->x < min_x) {
#ifdef DEBUG
                                printf("hit_edge %d %d\n", nodesy[i]->x, nodesy[i]->y);
#endif                     
                                min_x = nodesy[i]->x;
                                hit_edge = 1;
                                // if next point is not reachable
                                for (j = 0, falling_edge = 1; j < buildingsSize; j++) {
                                    if (buildings[j][2] == curr_y &&
                                        buildings[j][0] < min_x &&
                                        buildings[j][1] >= min_x) {
                                        falling_edge = 0;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
                if (hit_wall_bot || falling_edge)
                    break;
            }
            if (falling_edge && min_x > max_x)
                curr_x = min_x;
            else if (hit_wall_bot || hit_wall)
                curr_x = max_x;
            else if (hit_edge)
                curr_x = min_x;
            if (!something_left)
                break;
            if (hit_wall || hit_edge || hit_wall_bot) {
                falling_edge = 0;
                hit_wall_bot = 0;
                hit_wall = 0;
                hit_edge = 0;
                dir = 0;
                idx++;
                retn = realloc(retn, (idx + 1) * sizeof(NODE*));
                retn[idx] = calloc(1, sizeof(NODE));
                retn[idx]->x = curr_x;
                retn[idx]->y = curr_y;
            }
            else
                printf("BUGON %d, why?\n", __LINE__);
        }
    }
    
    int available_nodes_count = idx + 1;

    // heapify by x
    for (i = available_nodes_count / 2; i >= 0; i--) {
        heapifyx(retn, available_nodes_count, i);
    }
    // sort as min heap by x
    for (i = available_nodes_count - 1; i >= 0; i--) {
        swap(&retn[0], &retn[i]);
        heapifyx(retn, i, 0);
    }
    
#ifdef DEBUG
    printf("available nodes.\n");
    print_heap(retn, available_nodes_count);
#endif
    
    int ret_size = idx + 1;
    *returnSize = ret_size;
    int **ret = calloc(ret_size, sizeof(int*));
    int *col = calloc(ret_size, sizeof(int));
    for (i = 0; i < ret_size; i++) {
        ret[i] = calloc(2, sizeof(int));
        col[i] = 2;
    }
    *returnColumnSizes = col;
    
    for (i = 0; i < ret_size; i++) {
        ret[i][0] = retn[i]->x;
        ret[i][1] = retn[i]->y;
        free(retn[i]);
    }
    free(retn);

    for (i = 0; i < len_of_nodes; i++) {
        free(nodes[i]);
    }
    free(nodes);
    free(nodesy);
    return ret;
}

