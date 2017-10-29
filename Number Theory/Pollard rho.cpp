/** Pollard rho integer factorization 
	Very fast, use only for big numbers
	Too long :(
	NEEDS MILLER-RABIN!! Very important.
*/

typedef long long ll;
typedef unsigned long long ull;

ll pollard_rho(ll n)
{
   ll x,y,i=1,k=2,d;

    x = y = rand()%n;

    while(1)
    {
        ++i;
        x=mod_mul(x,x,n);
        x+=2;
        if( x >= n) x-=n;
        if(x==y) return 1;

        d=gcd(abs(x-y),n);
        if(d!=1) return d;
        if(i==k)
        {
            y=x;
            k*=2;
        }
    }
    return 1;
}

vector<ll> factorize(ll n)
{
    vector<ll > ans;
    if(n==1) return ans;

    if(miller_rabin(n)) ans.push_back(n);

    else
    {
       ull d = 1ULL;
        while(d == 1ULL) d=pollard_rho(n);
        vector<ll> dd = factorize(d);
        ans=factorize(n / d);
        for(int i=0; i< dd.size(); i++)
            ans.push_back(dd[i]);
    }

    return ans;
}