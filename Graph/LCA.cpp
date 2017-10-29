/**
* O(1) per-query lower common ancestor
*/

typedef vector<int> vi;

vector<vi> adj(MAX);
int dp[MAX][40];
vi dfs_num(MAX),tin(MAX),tout(MAX);
int T,bound;

/**
* O(v) DFS precalculation
*/

void dfs(int u, int par) {
  tin[u] = T++;
  dp[u][0] = par;
  int v;
  for(int i  = 1; i < bound+1; i++)
    dp[u][i] = dp[dp[u][i-1]][i-1];
  for(int i = 0; i < adj[u].size(); i++) {
    v = adj[u][i];
    if (v!= par && dfs_num[v] == -1) {
      dfs_num[v] = dfs_num[u] + 1;
      dfs(v,u);
    }
  }
  tout[u] = T++;
}

/**
* Returns if x is ancestor of y
*/

bool anc(int x, int y){
    return ((tin[x]<=tin[y]) && (tout[y]<=tout[x]));
}

/**
* Returns lowes common ancestor of x and y
*/

int lca(int x, int y){
    int s = x;
    if(anc(x,y)) return x;
    if(anc(y,x)) return y;
    for(int j=bound;j>=0;--j)
        if(!anc(dp[x][j], y))
            x=dp[x][j];

    return dp[x][0];
}
