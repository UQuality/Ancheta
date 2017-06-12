#include <bits/stdc++.h>
#define rep(i,a,n) for(int i = a; i<n; i++)
#define all(v,c) (v.begin(),v.end(),c)
#define sr sort

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
class DisjointSet
{

private :

    vi parent,ran;

public :
    DisjointSet(int n){
        ran.assign(n,0);
        parent.resize(n);
        rep(i,0,n) parent[i] = i;
    }

    int findSet(int i) { return (parent[i] == i) ? i : (parent[i] = findSet(parent[i])); }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    void unionSet(int i, int j){

        if(!isSameSet(i,j)){

            int x = findSet(i), y = findSet(j);

            if(ran[x]>ran[y]) parent[y] = x; 

            else if(ran[x] == ran[y]) ran[y]++;
            
        }

    }
};


vector<edge> graph;

/* Kruskal implementation for MST */
ll kruskal(int n){
	ll ans = ll(0);
	int aux = 0;
	edge cur;
	DisjointSet d = DisjointSet(n);
	sr all(graph,w2s);
	for(int i = 0; aux < (n-1); i++){

        cur=graph[i];

        if(!d.isSameSet(cur.s,cur.t)){
            aux++;
            d.unionSet(cur.s, cur.t);
            ans += ll(cur.w);
        }
    }

    return ans;
}