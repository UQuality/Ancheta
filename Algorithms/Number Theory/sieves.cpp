#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;

bitset<10000010> bs;
vector<int> primes;
int numPF[MAX], phi[MAX], numDivs[MAX];

/** Typical sieve of Eratosthenes*/
void sieve(){
  bs.set();
  bs[0] = bs[1] = 0;
	for(int i = 2; i <= MAX; i++){
		if(bs[i]){
			for(int j = 2*i; j <= MAX ; j+=i) bs[j] = 0;
			primes.push_back(i);
    	}
    }
}

/** Sieve for number of diferent prime factors of n in */
void numPFSieve(){
	for(int i = 2; i<MAX; i++)
		if(numPF[i] == 0)
			for(int j = 2*i; j <= MAX; j+=i) numPF[j]++;
}

/** Sieve for number of relative primes of n (less than) */
void phiSieve(){
	for(int i = 0; i<MAX; i++) phi[i] = i;
	for(int i = 2; i<MAX; i++)
		if(phi[i] == i)
			for(int j = 2*i; j <= MAX - 1; j+=i) 
				phi[j] = (phi[j] / i) * (i - 1); 
}

int findQ(int n, int f);

/** Sieve for number of divisors of n, set numDivs[i] = 1*/
void numDivsSieve(){
	for (long i = 2; i <= MAX; i++)
        if(numDivs[i] == 1)
            for (long j = i; j <= MAX; j += i) 
                numDivs[j] *= findQ(j,i);
}

/** Count times that a prime f divides number n */
int findQ(int n, int f){
    int q = 0;
    while(n % f == 0){
        n /= f;
        q++;
    }
    return ++q;
}