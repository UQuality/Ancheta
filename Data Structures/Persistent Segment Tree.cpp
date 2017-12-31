/**
	Persistent segment tree implementation
	Query complexity: O(log n)
	Update complexity: O(log n)
	Build complexity: O(n)
	Space: O(n log n)
*/

const int N = 1e5 + 5;

// Tree node
struct node{
	int v, l, r; //Value, left and right child indexes
	node(){v = 0; l = r = -1;}
	node(int _v, int _l, int _r){
		v = _v; l = _l; r = _r;
	}
};

//Input array, version-root pointer array and node count
int a[N], rts[N], c;
//Segment tree of size O(n log n)
node t[(1<<18) * 18];

//Build tree, returns current node index in tree
int build(int l, int r){
	int i = c++, il, ir;
	if(l == r) t[i] = node(a[l],0,0);
	else{
		int m = (l + r) >> 1;
		il = build(l, m);
		ir = build(m + 1, r);
		t[i] = node(t[il].v + t[ir].v, il, ir);
	}
	return i;
}

/**	Update and create a new version of the tree.
	For every upgrade, store the index of root of the
	version i in rts[i] = upgrade(...)
*/
int upgrade(int p, int l, int r, int i, ll v){
	int ix = c++;
	t[ix] = t[p];
	if(l == r) t[ix].v = v;
	else{
		int m = (l + r) >> 1;
		if(i >= l && i <= m)
			t[ix].l = upgrade(t[p].l, l, m, i, v);
		else
			t[ix].r = upgrade(t[p].r, m + 1, r, i, v);
		t[ix].v = t[t[ix].l].v + t[t[ix].r].v
	} 
	return ix;
}

//Querying for RSQ in version with root p (initial call)
ll query(int p, int l, int r, int i, int j){
	node n = t[p];
	if(i > r || j < l) return 0;
	if(i <= l && r <= j) return n.v;
	int m = (l + r) >> 1;
	return query(n.l, l, m, i, j) + query(n.r, m + 1, r, i, j);
}
