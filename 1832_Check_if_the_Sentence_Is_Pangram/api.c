bool checkIfPangram(char * sentence){
    int arr[26] = {0}, i = 0;
    bool ret = true;
    for (i = 0; i < strlen(sentence); i++) {
        arr[sentence[i] - 0x61] = 1;
    }
    for (i = 0; i < 26; i++)
        ret &= arr[i];
    return ret;
}
