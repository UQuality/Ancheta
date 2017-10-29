/**
	Segment tree implementation for classical RMQ
*/
const int N = 1e5 + 10;

int t[N], T[2 * N];

/**
	Build segment tree
*/
void build(int n, int l, int r){
	if(l == r){
		T[n] = t[l];
	}else{
		int m = (l + r) / 2;
		build(n * 2, l, m);
		build(n * 2 + 1, m + 1, r);
		T[n] = min(T[n * 2], T[n * 2 + 1]);
	}
}

/**
	update segment tree
*/

void update(int n, int l, int r, int idx, int v){
	if(l == r){
		T[n] = v;
	}else{
		int m = (l + r) / 2;
		if(l <= idx && idx <= m)
			update(n * 2, l, m, idx, v);
		else
			update(n * 2 + 1, m + 1, r, idx, v);
		T[n] = min(T[n * 2], T[n * 2 + 1]);
	}
}

/**
	Query on segment tree
*/

int query(int n, int l, int r, int ql, int qr){
	if(ql > r || qr < l){
		return INF;
	}
	if(ql <= l && qr >= r)
		return T[n];
	int m = (l + r) / 2;
	return min(query(n * 2, l, m, ql, qr), query(n * 2 + 1, m + 1, r, ql, qr));
}
