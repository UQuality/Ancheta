/**
	Segment tree with lazy propagation for range updates
*/

#define lf(n) (n << 1)
const int N = 1e5 + 5;
int a[N], t[1 << 18], s[1 << 18];

void build(int n, int l, int r){
	s[n] = 0;
	if(l == r) t[n] = a[l];
	else{
		int m = (l + r) >> 1;
		build(lf(n), l, m);
		build(lf(n) + 1, m + 1, r);
		t[n] = t[lf(n)] + t[lf(n) + 1];
	}
}

void propagate(int n, int l, int r);

int query(int n, int l, int r, int i, int j){
	if(i > r || j < l) return 0;
	propagate(n,l,r);
	if(i <= l && j >= r) return t[n];
	int m = (l + r) >> 1;
	return query(lf(n), l, m, i, j) + query(lf(n) + 1, m + 1, r, i, j);
}

void update(int n, int l, int r, int i, int j, int v){
	propagate(n,l,r);
	if(i > r || j < l) return;
	if(i <= l && j >= r){
		t[n] += (r - l + 1) * v;
		if(l != r){
			s[lf(n)] += v;
			s[lf(n) + 1] += v;
		}
		else s[n] = 0;
		return;
 	}
	int m = (l + r) >> 1;
	update(lf(n), l, m, i, j, v);
	update(lf(n) + 1, m + 1, r, i, j, v);
	t[n] = t[lf(n)] + t[lf(n) + 1];
}

void propagate(int n, int l, int r){
	if(s[n] == 0) return;
	t[n] += (r - l + 1)*s[n];
	if(l != r){
		s[lf(n)] += s[n];
		s[lf(n) + 1] += s[n];
	}
	s[n] = 0;
}