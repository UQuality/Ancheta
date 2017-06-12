#include <bits/stdc++.h>
#define MAX 10000001
#define enl "\n"
#define rep(i,a,n) for(int i = a; i<n; i++)

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

/** Typical sieve of Eratosthenes*/

int primes[MAX];

void sieve(){
	rep(i,2,MAX)
		if(primes[i] == 0)
			for(int j = 2*i; j<MAX; j+=i)
				primes[j] = 1;
}

/** Typical O(sqrt(n)) primality test*/

bool isPrime(int n){
	for(int i = 2; i*i <= n; i++)
		if(n%i==0)
			return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int prime = 943589;
	sieve();

	if(isPrime(prime))
		cout << "Is prime: says test!" << enl;
	if(!primes[prime])
		cout << "Is prime: says sieve!" << enl;
	if(miller_rabin(prime))
		cout << "Is prime: says Miller-Rabin!" << enl;

	return 0;
}
