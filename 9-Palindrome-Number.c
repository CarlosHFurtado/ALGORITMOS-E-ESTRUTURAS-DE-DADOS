bool isPalindrome(int x) {

    char str[20];
    sprintf(str, \%d\, x);

    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }

    int reversed = atoi(str);

    return x == reversed;
}