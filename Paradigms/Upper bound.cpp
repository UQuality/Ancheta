/** Find the position of x in the given array
    If x isn't in array, returns the position
    Over x should be in */

long upper(ll x){
    long l=0,r=arr.size();
    long mid;
    while(l<r){
        mid=((l+r)>>1);
        if( x < arr[mid])r=mid;
        else l=mid+1;
    }
    return r;
}
