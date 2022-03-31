// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int i = n / 2;
    long start = 1, tail = n;
    while (1) {
        if (isBadVersion(i)) {
            // goes to left
            tail = i;
        }
        else {
            // goes to right
            start = i;
        }
        i = (start + tail) / 2;
        if (tail <= start + 1)
            break;
    }
    if (isBadVersion(start))
        return start;
    if (isBadVersion(tail))
        return tail;
    return -1;
}
