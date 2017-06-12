/**
* Misc for counting involving problems
* In this section, inv is the multiplicative inverse
* See also Mod misc for more info
*/

#include <bits/stdc++.h>
#define MAX 10001
#define mod 1000000007
#define rep(i,a,n) for(int i = a; i<n; i++)

using namespace std;
typedef long long ll;

/* fact[i] = i! */
ll fact[MAX];

/* Fastest mod factorial, fill fact array*/
void fillFact(){
	fact[0] = fact[1] = 1;
	rep(i,2,MAX)
		fact[i] = (i % mod * fact[i-1] % mod ) % mod;
}

/* Fast enough function for nPk % mod */
ll mod_perm(int n, int k){
	return (fact[n] % mod * inv(fact[n-k]) % mod ) % mod;
}

/* Fast enough function for nCk % mod */
ll mod_comb(int n, int k){
	return (fact[n] % mod * inv((fact[k] % mod * fact[n-k] % mod) % mod ) % mod) % mod;
}


/* comb[n][k] = nCk % mod */
ll comb[MAX][MAX];

/*	DP manner to calculate nCk, recommended for small MAX */
void fillComb(int n, int k)
{ 

   rep(i,0,MAX)
    {
        comb[i][0] = comb[i][i] = 1;

        rep(k,1,i)
            if(i - 1 < k)
				comb[i][k] = comb[i - 1][k - 1] % mod;
			else
				comb[i][k] = ( (comb[i - 1][k] % mod) + (comb[i - 1][k - 1]%mod) ) % mod;
    }
}
