
typedef long long ll;

/* Calculates the multiplicative inverse of x % mod
   NOTE: ONLY WORKS IF mod IS PRIME!!
*/

ll inv( ll x, ll mod)
{
    return mod_pow( x, mod-2 );
}

/* Calculates the multiplicative inverse of a % mod
   NOTE: ONLY WORKS IF gcd(a,mod) = 1!! (See modular inverse)
   Handle the possible case of returns -1
*/

ll mod_inv( ll a, ll mod ){
	ll x,y,d;
	extE(a,mod,x,y,d);
	if(d!=1) return -1;
	return (x + mod) % mod; 
}
