/** Find the position of the first occurrence
    of x in the given array.
    If x isn't in array, returns -1 */

long fobs(ll x) {
    long l = 0 , r = arr.size() - 1;
    long fo = -1, m;
    while (l <= r) {
        m = l + ((r - l) >> 1);
        if (arr[m] == x) {
            fo = m;
            r = m - 1;
        }
        else if (arr[m] < x) l = m + 1;
        else r = m - 1;
    }
   return fo;
}