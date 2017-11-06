/**
    Modified Merge Sort algorithm
    For counting inversions in array
*/

long long mer(long a[], int l, int m, int r){
    int i,j,k;
    long long inv;
    int n1 = m - l + 1;
    int n2 = r - m;
    long L[n1], R[n2];

    for(i = 0; i < n1; i++) L[i] = a[l + i];
    for(j = 0; j < n2; j++) R[j] = a[m + 1 + j];

    inv = 0LL; i = j = 0; k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]) a[k] = L[i++];
        else {
            a[k] = R[j++];
            inv += (long long)(1LL*n1 - 1LL*i);
        }
        k++;
    }
    while(i < n1) a[k++] = L[i++];
    while(j < n2) a[k++] = R[j++];
    return inv;
}

long long mergeSort(long a[], int l, int r){
    long long inv = 0LL;
    if(l < r){
        int m = l + (r - l)/2;
        inv = mergeSort(a,l,m);
        inv += mergeSort(a,m+1,r);
        inv += mer(a,l,m,r);
    }
    return inv;
}
