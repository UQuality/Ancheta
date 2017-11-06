/**
    QuickSort sorting algorithm
    Classical implementation
    NOTE: can present "degradation"
    i.e., this implementation have
    worst case complexity O(n^2)
    To reduce, change to random-pivot
*/

int qSort(int a[], int l, int r){
    int piv = a[(l + r)/2];
    int i = l;
    int j = r;
    int c = 0;
    while(i <= j){
        while(a[i] < piv){ i++; c++;}
        while(a[j] > piv){ j--; c++;}
        c += 2;
        if(i <= j){
            swap(a[i],a[j]);
            i++; j--;
        }
    }
    if(l < j) c += qSort(a,l,j);
    if(i < r) c += qSort(a,i,r);
    return c;
}
/**
    BONUS: method to generate the
    worst permutation of n elements
    [1..n] for comparisons in above
    QuickSort implementation
*/
void antiQuick(int a[],int n){
    if(n == 2 || n == 1) return;
    int piv = (n - 1)/2;
    antiQuick(a,n-1);
    swap(a[n-1],a[piv]);
}
