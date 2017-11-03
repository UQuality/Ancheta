/**
    * Coing change problem: DP for count 
    * Number of ways to exchange n having
    * Having infinite coins of Di denominations
*/

int coinChange( vector<int> D, int n)
{
    int dp[n+1];
    for(int i = 0; i <= n; i++) dp[i] = 0;
    dp[0] = 1;
    for(int i=0; i < D.size(); i++)
        for(int j = D[i]; j <= n; j++)
            dp[j] += dp[j-D[i]];
    return dp[n];
}
