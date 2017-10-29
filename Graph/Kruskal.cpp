/**
    O(|V| Log|E|) Kruskal algorithm for MST
*/
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
