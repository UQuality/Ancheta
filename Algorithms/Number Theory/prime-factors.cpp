#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

/** EXTRA: gcd & lcm */

ll gcd(ll a, ll b){	return b == 0? a : gcd(b,a%b); }
ll lcm(ll a, ll b){ return a * (b / gcd(a,b)); }

/** Pollard rho integer factorization 
	Very fast, use only for big numbers
	Too long :(
	NEEDS MILLER-RABIN!! Very important. For miller_rabin:
	See https://github.com/DPUQ/Ancheta/blob/master/Algorithms/Number%20Theory/primes.cpp
*/

long long pollard_rho(ll n)
{
   ll x,y,i=1,k=2,d;

    x=y=rand()%n;

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
    if(n==1)
    {
        return ans;
    }
    if(miller_rabin(n))
    {
        ans.push_back(n);
    }
    else
    {
       ull d=1ull;

        while(d==1)
            d=pollard_rho(n);
        vector<ll> dd= factorize(d);
        ans=factorize(n / d);
        for(int i=0; i< dd.size(); i++)
            ans.push_back(dd[i]);

    }

    return ans;
}

/** ENDS POLLARD-RHO */

/** Prime factorization with optimized trial divisions
	Complexity: O(sqrt(N) / log sqrt(N))
	NEEDS SIEVE!! Very important. For sieve:
	See https://github.com/DPUQ/Ancheta/blob/master/Algorithms/Number%20Theory/primes.cpp 
*/

vector<int> primes; //Primes. Populated by sieve

vector<ll> primeFactors(ll n){
	vector<ll> factors;
	int index = 0, factor = primes[index]; 
	while(factor*factor <= n){
		while(n % factor == 0){ n /= factor; factors.push_back(factor);}
		factor = primes[++index];
	}

	if(n != 1) factors.push_back(n);

	return factors;
}

/** Now, some interesting fuctions involving prime factors
	Only modifying above code, same complexity
*/

int countPF(ll n){
	int index = 0, factor = primes[index], ans = 0; 
	while(factor*factor <= n){
		while(n % factor == 0){ n /= factor; ans++; } //If need only diferents, increment
													  // before while cycle with an if.
													  //If need sum of prime factos, ans += factor
		factor = primes[++index];
	}

	if(n != 1) ans++; // If need sum of prime factors, ans += n

	return ans;
}

/** Now, some functions related with divisors, using prime factors
	We will modify above factorization for it, but if you have
	Prime factors, you can only compute the formula!
*/


/** Num divs formula: if n = p1^a * p2^b * ... * pk ^ e, 
	The number of positive divisors of n D = (a+1)*(b+1)*...*(e+1)
*/
ll numDivs(ll n){
	int index = 0, factor = primes[index], ans = 1;
	ll power; 
	while(factor*factor <= n){
		power = 0;
		while(n % factor == 0){ n /= factor; power++;}
		ans *= (power + 1);
		factor = primes[++index];
	}

	if(n != 1) ans *= 2;

	return ans;
}

/** Sum divs formula: if n = p1^a * p2^b * ... * pk ^ e, 
	The sum of positive divisors of n 
	S = (( p1^(a+1) - 1 )/ (p1 - 1) )*(( p2^(b+1) - 1 )/ (p2 - 1) )*...*(( pk^(e+1) - 1 )/ (pk - 1) )
*/
ll sumDivs(ll n){
	int index = 0, factor = primes[index], ans = 1;
	ll power; 
	while(factor*factor <= n){
		power = 0;
		while(n % factor == 0){ n /= factor; power++;}
		ans *= ((ll)pow((double)factor, power + 1.0) - 1) / (factor - 1);
		factor = primes[++index];
	}

	if(n != 1) ans *= ((ll)pow((double)n, 2.0) - 1) / (n - 1);

	return ans;
}

/** Euler phi: if n = p1^a * p2^b * ... * pk ^ e, 
	The number of relative primes of n (less than)
	phi(n) = n * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pk)
*/
ll eulerPhi(ll n){
	int index = 0, factor = primes[index], ans = n;
	ll power; 
	while(factor*factor <= n){
		if (n % factor == 0) ans -= ans / factor;
		while(n % factor == 0) n /= factor;
		factor = primes[++index];
	}

	if(n != 1) ans -= ans / n;

	return ans;
}
