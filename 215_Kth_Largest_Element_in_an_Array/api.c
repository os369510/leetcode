// Implement as heap sort
void print_arr(int *arr, int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void heapify(int *arr, int arr_size, int root) {
    int largest = root;
    int l = 2 * root + 1;
    int r = 2 * root + 2;
    
    if (l < arr_size && arr[l] > arr[largest])
        largest = l;
    
    if (r < arr_size && arr[r] > arr[largest])
        largest = r;
    
    if (largest != root) {
        swap(&arr[largest], &arr[root]);
        heapify(arr, arr_size, largest);
    }
    
}

int findKthLargest(int* nums, int numsSize, int k){
    int i = 0;
    for (i = numsSize / 2; i >= 0; i--) {
        heapify(nums, numsSize, i);
    }
    
    for (i = numsSize - 1; i >= 0; i--) {
        swap(&nums[0], &nums[i]);
        heapify(nums, i, 0);
    }    
    
    return nums[numsSize - k];
}
