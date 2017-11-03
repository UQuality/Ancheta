/** Extended euclidean algorithm for 
	Bezout application to solve linear 
	diophantine equations  ax + by = c

	Solutions have form:

	X = (c/d)*x  +  (b/d)*n 
	Y = (c/d)*y  -  (a/d)*n 
*/

typedef long long ll;

void extE(ll a, ll b, ll &x, ll &y, ll &d) { 

	if (b == 0) { 
		x = 1; y = 0; d = a; return; 
	}

	extE(b, a % b, x, y, d);
	ll x1 = y; 
	ll y1 = x - (a / b) * y; 
	x = x1; y = y1;

}