/** Modular misc. for avoid overflow*/

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
