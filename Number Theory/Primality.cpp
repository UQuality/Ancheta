
#define MAX 10000001

/** Values filled by sieve of Eratosthenes
    After calculate sieve:
    sieveBound = (long long)primes[primes.size() - 1] * 
                (long long)primes[primes.size() - 1];
*/

bitset<10000010> bs;
vector<int> primes;
long long sieveBound;

/** Optimized primality test */

bool isPrime(long long n){

	if(n<MAX) return bs[n]; //O(1) for small numbers

  else if (n>sieveBound) return miller_rabin(n); // O(1) for very large numbers

  else { // O(sqrt(N) / log sqrt(N)) for numbers MAX <= N <= sieveBound

    for (int i = 0; i < (int)primes.size(); i++) 
      if (n % primes[i] == 0) return false; 

    return true;
  }
}
