enum state {
    L = 0,
    M = 1,
    R = 2
};
char * pushDominoes(char * dominoes){
    int idx; // start to modify
    enum state status = M;
    int len = strlen(dominoes), mid = 0, sum = 0, count = 0;
    idx = 0;
    for (int i = 0; i < len; i++) {
        switch (dominoes[i]) {
            case 'L':
                if (status == R) {
                    sum = (idx + i);
                    mid = sum / 2;
                    count = 0;
                    while (idx != mid) {
                        count++;
                        idx++;
                        if (idx == mid && (sum % 2 == 0))
                            break;
                        dominoes[idx] = 'R';
                        dominoes[i - count] = 'L';
                    }
                }
                else // L and .
                    while (idx != i)
                        dominoes[idx++] = 'L';
                status = L;
                idx = i;
                break;
            case 'R':
                if (status == R) {                    
                    while (idx != i)
                        dominoes[idx++] = 'R';
                }
                status = R;
                idx = i;
                break;
            case '.':
                break;
        }
    }
    if (status == R)
        while (idx != len)
            dominoes[idx++] = 'R';
    return dominoes;
}
