 
/**
    * DP to get the lenght of the longest 
    * increasing subsecuence from a list of values 
*/
int lis( int arr[], int n )
{
    
    int dp[n+1], mx;
    for (i = 0; i < n; i++) dp[i] = 1;
 
    for (i = 1; i < n; i++ ){
        for (j = 0; j < i; j++ ) 
            if ( arr[i] > arr[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        mx = max(mx,dp[i]);
    }
 
    return mx;
}