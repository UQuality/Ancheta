#include<bits/stdc++.h>
using namespace std;
#define INF 1e9


const int N = 1e5 + 10;

int t[N], T[2 * N];

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

int query(int n, int l, int r, int ql, int qr){
	if(ql > r || qr < l){
		return INF;
	}
	if(ql <= l && qr >= r)
		return T[n];
	int m = (l + r) / 2;
	return min(query(n * 2, l, m, ql, qr), query(n * 2 + 1, m + 1, r, ql, qr));
}

int main(){

	int n, q, l, r;
	char o;
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
		cin >> t[i];
	build(1, 1, n);
	while(q--){
		cin >> o >> l >> r;
		if(o == 'q'){
			cout << query(1, 1, n, l,r) << endl;
		}else{
			update(1, 1, n, l, r);
		}
	}
	return 0;

}