/**
* Chinese remainder theorem
* Finds x such that solves the congruence sytem:
* x = ai (mod ni)
*/

typedef long long ll;

ll crt(vector<ll> &a, vector<ll> &n) {
  ll x = 0, N = 1, t;
  for (int i = 0; i < n.size(); i++)
    N *= n[i];

  for (int i = 0; i < a.size(); i++) {
    t = (a[i] * (N / n[i])) % N;
    t = (t * mod_inv(N / n[i], n[i])) % N;
    x = (x + t) % N;
  }
  return (x + N) % N;
}