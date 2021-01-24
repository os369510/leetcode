char * intToRoman(int num){
    int th = num / 1000;
    int h = (num / 100) % 10;
    int te = (num / 10) % 10;
    int d = num % 10;
    int i = 0, len = 0;
    char *s = malloc(sizeof(char)); // '\0'

    if (th) {
        for (i = 0; i < th; i++) {
            len++;
            s = realloc(s, (len + 1) * sizeof(char));
            s[len - 1] = 'M';
        }
    }
    if (h) {        
        if (h == 9) {
            len += 2;
            s = realloc(s, (len + 1) * sizeof(char));
            s[len - 2] = 'C';
            s[len - 1] = 'M';
        }
        else if (h >= 5) {
            for (i = 5; i <= h; i++) {
                len++;
                s = realloc(s, (len + 1) * sizeof(char));
                if (i == 5)
                    s[len - 1] = 'D';
                else
                    s[len - 1] = 'C';
            }
        }
        else if (h == 4) {
            len += 2;
            s = realloc(s, (len + 1) * sizeof(char));
            s[len - 2] = 'C';
            s[len - 1] = 'D';
        }
        else { // < 4
            for (i = 1; i <= h; i++) {
                len++;
                s = realloc(s, (len + 1) * sizeof(char));
                s[len - 1] = 'C';
            }            
        }
    }
    if (te) {        
        if (te == 9) {
            len += 2;
            s = realloc(s, (len + 1) * sizeof(char));
            s[len - 2] = 'X';
            s[len - 1] = 'C';
        }
        else if (te >= 5) {
            for (i = 5; i <= te; i++) {
                len++;
                s = realloc(s, (len + 1) * sizeof(char));
                if (i == 5)
                    s[len - 1] = 'L';
                else
                    s[len - 1] = 'X';
            }
        }
        else if (te == 4) {
            len += 2;
            s = realloc(s, (len + 1) * sizeof(char));
            s[len - 2] = 'X';
            s[len - 1] = 'L';
        }
        else { // < 4
            for (i = 1; i <= te; i++) {
                len++;
                s = realloc(s, (len + 1) * sizeof(char));
                s[len - 1] = 'X';
            }            
        }
    }    
    if (d) {
        if (d == 9) {
            len += 2;
            s = realloc(s, (len + 1) * sizeof(char));
            s[len - 2] = 'I';
            s[len - 1] = 'X';
        }
        else if (d >= 5) {
            for (i = 5; i <= d; i++) {
                len++;
                s = realloc(s, (len + 1) * sizeof(char));
                if (i == 5)
                    s[len - 1] = 'V';
                else
                    s[len - 1] = 'I';
            }
        }
        else if (d == 4) {
            len += 2;
            s = realloc(s, (len + 1) * sizeof(char));
            s[len - 2] = 'I';
            s[len - 1] = 'V';
        }
        else { // < 4
            for (i = 1; i <= d; i++) {
                len++;
                s = realloc(s, (len + 1) * sizeof(char));
                s[len - 1] = 'I';
            }            
        }
    }
    s[len] = '\0';
    return s;
}
