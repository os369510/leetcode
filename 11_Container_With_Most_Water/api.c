int maxArea(int* height, int heightSize){
    int m = 0, v = 0;
    int l = 0, r = heightSize - 1;
    
    while (l < r) {
        v = ((height[l] > height[r])? height[r] : height[l]) * (r - l);
        m = (v > m)? v : m;
        if (height[l] > height[r])
            r--;
        else
            l++;
    }
    return m;
}
