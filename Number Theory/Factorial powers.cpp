/** Return power of p in prime factorization of n!*/

int get_powers(int n, int p) {
    int result = 0;
    n /= p;
    do {
        result += n;
        n /= p;
    }while(n > 0);
    return result;
}