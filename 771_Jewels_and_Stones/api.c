int numJewelsInStones(char * J, char * S){
    char array[52] = {0};
    int i = 0, sum = 0;
    for (i = 0; i < strlen(S); i++){
        if (S[i] <= 'Z')
            array[S[i] - 'A']++;
        else
            array[S[i] - 'a' + 26]++;
    }
    for (i = 0; i < strlen(J); i++){
        if (J[i] <= 'Z')
            sum += array[J[i] - 'A'];
        else
            sum += array[J[i] - 'a' + 26];
    }
    return sum;
}

