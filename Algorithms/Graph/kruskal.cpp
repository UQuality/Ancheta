#include <bits/stdc++.h>
#define rep(i,a,n) for(int i = a; i < n; i++)
#define MAX 200005

using namespace std;
typedef long long ll;
typedef vector<int> vi;

/* Edge for edge list graph representation  */
struct edge{
	int s,t,w;
	edge(int _s,int _t, int _w){
		s = _s, t = _t; w = _w;
	}
	edge(){}
};

/* Way to sort the edges */
bool w2s (edge i,edge j) { return (i.w<j.w); }

/* Disjoint set data structure for kruskal implementation */
vi parent,ran;
void build(int n){
    ran.assign(n,0);
    parent.resize(n);
    rep(i,0,n) parent[i] = i;
}

int find_(int i) { return (parent[i] == i) ? i : (parent[i] = find_(parent[i])); }

bool sameSet(int i, int j) { return find_(i) == find_(j); }

void union_(int i, int j){
    if(!sameSet(i,j)){
        int x = find_(i), y = find_(j);
        if(ran[x]>ran[y]) parent[y] = x;
        else {
            parent[x] = y;
            if(ran[x] == ran[y]) ran[y]++;
        }
    }
}

vector<edge> graph;

/* Kruskal implementation for MST */
ll kruskal(int v){
	ll ans = ll(0);
	int put = 0;
	edge cur;
	build(v);
    sort(graph.begin(),graph.end(),w2s);
	for(int i = 0; put < (v-1); i++){
        cur=graph[i];
        if(!sameSet(cur.s,cur.t)){
            put++;
            union_(cur.s, cur.t);
            ans += ll(cur.w);
        }
    }
    return ans;
}
