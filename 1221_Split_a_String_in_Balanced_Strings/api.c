typedef enum _dir{
    R = 1,
    L,
} DIR;
int balancedStringSplit(char * s){
    int ret = 0, i = 0, r = 0, l = 0;
    DIR d = (s[0] == 'L')? L : R;
    DIR toggle = d;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] == 'L') { // L
            if (d == L) {
                if (r != 0)
                    r--;
                else
                    l++;
            }
            else if (d == R) {
                if (toggle == R)
                    l = 0;
                if (r != 0) {
                    --r;
                    ret++;
                }
                else if (r == 0)
                    l++;
            }
            if (r != 0)
                toggle = L;
            d = L;
        }
        else { // R
            if (d == R) {
                if (l != 0)
                    l--;
                else
                    r++;
            }
            else if (d == L) {
                if (toggle == L)
                    r = 0;
                if (l != 0) {
                    --l;
                    ret++;
                }
                else if (l == 0)
                    r++;
            }
            if (l != 0)
                toggle = R;
            d = R;
        }
    }
    return ret;
}
