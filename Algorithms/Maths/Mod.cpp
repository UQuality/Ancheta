/**
* Modular arithmetic misc
*/

#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;
typedef long long ll;

/* Calculates x + y % mod*/
ll sum( ll x, ll y )
{
    x = x+y;
    return ( x > MOD ? x-MOD : x );
}

/* Calculates x - y % mod*/
ll sub( ll x, ll y )
{
    x = x-y;
    return ( x < 0 ? x+MOD : x );
}

/* Calculates x * y % mod*/
ll mul( ll a, ll b)
{
    ll x = 0, y = a%mod;
    while( b )
    {
        if( b&1 ) x = ( x+y )%mod;
        y = ( y+y )%mod;
        b >>= 1;
    }
    return x;
}

/* Calculates x ^ y % mod*/
ll mod_pow( ll b, ll e)
{
    ll r = 1;
    ll pow = b % mod;
    while( e )
    {
        if( e&1 ) r = ( r*pow )%mod;
        pow = ( pow*pow )%mod;
        e >>= 1;
    }
    return r;
}

/* Calculates the multiplicative inverse of x % mod
   NOTE: ONLY WORKS IF mod IS PRIME!!
*/

ll inv( ll x )
{
    return mod_pow( x, mod-2 );
}

/* Calculates the multiplicative inverse of a % mod
   NOTE: ONLY WORKS IF gcd(a,mod) = 1!! (See modular inverse)
   Handle the possible case of returns -1
   For extE see:
   github.com/UQuality/Ancheta/blob/master/Algorithms/Number%20Theory/prime-factors.cpp
*/

ll mod_inv( ll a ){
	ll x,y,d;
	extE(a,mod,x,y,d);
	if(d!=1) return -1;
	return (x + mod) % mod; 
}
