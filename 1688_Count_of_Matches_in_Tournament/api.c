int numberOfMatches(int n){
    int matches = n/2, teams = n, ret = 0, r = 0;
    while (teams != 1) {
        r = teams % 2;
        matches = teams / 2;
        ret += matches;
        teams = matches + r;
    }
    return ret;
}
