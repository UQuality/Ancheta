/** Prime factorization with optimized trial divisions
	Complexity: O(sqrt(N) / log sqrt(N))
	NEEDS SIEVE!! Very important.
*/

typedef long long ll;

ll lcm(ll a, ll b){ return a * (b / __gcd(a,b)); }

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

/** You can modify above function for very purposes
	For example: 

	- If wanna count number of pf, only add an "ans" var.
		and increment for every factor
	- If wanna count number of DIFERENT pf, use again "ans"
		var. but increment using an if before the while
	- If wanna know how many divisors have n, create "ans"
		and "power" vars. for every round in the while, 
		increment power, multiply every (power + 1) and 
		store the answer in "ans".
	- If wanna calculate sum of divisors of n, use the same 
		above idea, but store in ans the multiplication of
		(pf^(power + 1) - 1)/ (pf - 1) instead of (power + 1)
		for every prime factor.
	- If wanna calculate phi(n), initialize ans = n, and 
		for every DIFERENT pf do ans -= (ans / pf)

	REMEMBER HANDLE THE LAST IF IN EVERY CASE!!
*/
