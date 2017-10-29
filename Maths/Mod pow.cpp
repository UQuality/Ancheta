
typedef long long ll;

/* Calculates x ^ y % mod*/
ll mod_pow( ll b, ll e, ll mod)
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