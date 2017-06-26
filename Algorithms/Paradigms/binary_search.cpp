#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> arr;

/** Find the position of x in the given array
	If x isn't in array, returns -1 */
long binarySearch(ll x){  
    long l=0,r = arr.size();  
    long mid;  
    while(l<r){  
        mid=((l+r)>>1);
        if( x < arr[mid])r=mid;
        else l=mid+1;
    }
    return -1;  
}  

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

/** Find the position of x in the given array
	If x isn't in array, returns the position 
	Under x must be in */

long lower(ll x){  
    long l=0,r=arr.size();  
    long mid;  
    while(l<r){  
        mid=((l+r)>>1);  
        if(x <= arr[mid])r=mid;  
        else l=mid+1;
    }  
    return r;  
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << "Something to print!";
	return 0;
}
