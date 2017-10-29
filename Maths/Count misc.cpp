/**
* Misc for counting involving problems
* In this section, inv is the multiplicative inverse
*/

#define MAX 10001
#define mod 1000000007

typedef long long ll;

/* fact[i] = i! */
ll fact[MAX];

/* Fast enough mod factorial, fill fact array*/
void fillFact(){
	fact[0] = fact[1] = 1;
	for(int i = 2; i < MAX; i++)
		fact[i] = (i % mod * fact[i-1] % mod ) % mod;
}

/* Fast enough function for nPk % mod */
ll mod_perm(int n, int k){
	return (fact[n] % mod * 
		inv(fact[n-k], mod) % mod ) % mod;
}

/* Fast enough function for nCk % mod */
ll mod_comb(int n, int k){
	return (fact[n] % mod * inv((fact[k] % mod * fact[n-k] % mod) 
		% mod ) % mod) % mod;
}


/* comb[n][k] = nCk % mod */
ll comb[MAX][MAX];

/*	DP manner to calculate nCk, recommended for small MAX */
void fillComb(int n, int k)
{ 

   for(int i = 0; i < MAX; i++)
    {
        comb[i][0] = comb[i][i] = 1;

        for(int k = 1; k < i; k++)
            if(i - 1 < k)
				comb[i][k] = comb[i - 1][k - 1] % mod;
			else
				comb[i][k] = ( (comb[i - 1][k] % mod) + 
						(comb[i - 1][k - 1]%mod) ) % mod;
    }
}
