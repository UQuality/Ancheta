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
        if( b&1 )
        {
            x = ( x+y )%mod;
        }
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
    while( e > 0 )
    {
        if( e&1 ) r = ( r*pow )%mod;
        pow = ( pow*pow )%mod;
        e >>= 1;
    }
    return r;
}

/* Calculates the multiplicative inverse of x*/
ll inv( ll x )
{
    return mod_pow( x, mod-2 );
}