#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/**
* O(log n) algorithm to calculate nth fibonacci number Fn
*/

/**
* 2x2 square matrix multiplication
*/
void mult(ll m1[2][2], ll m2[2][2] , ll m)
{
  ll x =  ((m1[0][0] % m * m2[0][0] % m ) % m + (m1[0][1] % m * m2[1][0] % m) % m) % m;
  ll y =  ((m1[0][0] % m * m2[0][1] % m ) % m + (m1[0][1] % m * m2[1][1] % m) % m) % m;
  ll z =  ((m1[1][0] % m * m2[0][0] % m ) % m + (m1[1][1] % m * m2[1][0] % m) % m) % m;
  ll w =  ((m1[1][0] % m * m2[0][1] % m ) % m + (m1[1][1] % m * m2[1][1] % m) % m) % m;

  m1[0][0] = x;
  m1[0][1] = y;
  m1[1][0] = z;
  m1[1][1] = w;
}

/**
* Fast matrix power
*/
void pow(ll fibo[2][2], ll n , ll m)
{
  ll base[2][2] = {{1LL,1LL},{1LL,0LL}};

  while( n ){
    if( n & 1 ) mult(fibo, base, m);
    mult(base, base, m);
    n >>= 1;
  }
}

/**
* fib(n,m) = Fn mod m
*/
ll fib(ll n, ll m)
{
  ll fibo[2][2] = {{1LL,1LL},{1LL,0LL}};
  if (n == 0)
    return 0;
  pow(fibo, n - 1 , m);
  return fibo[1][0];
}
