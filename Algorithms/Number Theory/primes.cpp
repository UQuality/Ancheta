#include <bits/stdc++.h>
#define MAX 10000001

using namespace std;

/** Miller-Rabin Primality test from Ancheta UTP implementation*/
const int rounds = 20;

long long mod_mul(long long a, long long b, long long mod) {
  long long x = 0, y = a % mod;
  while (b > 0) {
    if (b & 1)
      x = (x + y) % mod;
    y = (y * 2) % mod;
    b /= 2;
  }
  return x % mod;
}

long long mod_pow(long long a, long long exp, long long mod) {
  long long ans = 1;
  while (exp > 0) {
    if (exp & 1)
      ans = mod_mul(ans, a, mod);
    a = mod_mul(a, a, mod);
    exp >>= 1;
  }
  return ans;
}

bool witness(long long a, long long n) {
  long long u = n - 1;
  int t = 0;
  while (u % 2 == 0) {
    t++;
    u >>= 1;
  }
  long long next = mod_pow(a, u, n);
  if (next == 1) return false;
  long long last;
  for (int i = 0; i < t; ++i) {
    last = next;
    next = mod_mul(last, last, n);
    if (next == 1) {
      return last != n - 1;
    }
  }
  return next != 1;
}

bool miller_rabin(long long n, int it = rounds) {
  if (n <= 1) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (int i = 0; i < it; ++i) {
    long long a = rand() % (n - 1) + 1;
    if (witness(a, n)) {
      return false;
    }
  }
  return true;
}

/** Values filled by sieve of Eratosthenes
    After calculate sieve:
    sieveBound = (long long)primes[primes.size() - 1] * (long long)primes[primes.size() - 1];
    For sieve, visit: https://github.com/DPUQ/Ancheta/blob/master/Algorithms/Number%20Theory/sieves.cpp
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
