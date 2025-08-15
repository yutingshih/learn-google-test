int factorial(int n) {
    if (n <= 1) return 1;
    int res = n;
    while (--n) res *= n;
    return res;
}
