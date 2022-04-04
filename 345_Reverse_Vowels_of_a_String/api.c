char * reverseVowels(char * s){
    int si = 0, start = -1, tail = -1, size = strlen(s), ti = size - 1;
    char tmp = 0;
    while (si < ti) {
        switch (s[si]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                start = si;
                break;
            default:
                si++;
        }
        switch (s[ti]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                tail = ti;
                break;
            default:
                ti--;
        }
        if (start >= 0 && tail >= 0) {
            tmp = s[start];
            s[start] = s[tail];
            s[tail] = tmp;
            start = tail = -1;
            si++;
            ti--;
        }
    }
    return s;
}
