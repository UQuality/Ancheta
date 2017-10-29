/** Calculate the "cumulative sum of divisors"
 function CSOD = sum(sumDivs(1..n)) */

typedef long long ll;

ll csod(ll n) {
  ll ans = ll(0) , j;
  for (ll i = 2LL; i * i <= n; i++) {
    j = n / i;
    ans += ((i + j) * (j - i + 1) / 2LL);
    ans += i * (j - i);
  }
  return ans;
}
