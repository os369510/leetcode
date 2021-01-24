int get_value(char c) {
    if (c == 'I') return 1;
    else if (c == 'V') return 5;
    else if (c == 'X') return 10;
    else if (c == 'L') return 50;
    else if (c == 'C') return 100;
    else if (c == 'D') return 500;
    else if (c == 'M') return 1000;
    else return -1;
}
bool valid_sub(char curr, char pre) {
    switch (pre) {
        case 'I':
            if (curr == 'V' || curr == 'X') return true;
        case 'X':
            if (curr == 'L' || curr == 'C') return true;
        case 'C':
            if (curr == 'D' || curr == 'M') return true;
    }
    return false;
}

int romanToInt(char * s){
    int len = strlen(s), i = 0, val = 0, ind = 0;
    for (i = 0; i < len; i++){
        ind = get_value(s[i]);
        val += ind;
        if (i >= 1 && valid_sub(s[i], s[i - 1]))
            val -= 2 * get_value(s[i - 1]);
    }
    return val;
}
