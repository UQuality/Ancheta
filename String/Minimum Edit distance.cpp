/**
* DP for minimum edit distance between two strings
*/

void editDistance(string a, string b){
	int m=a.size(),n=b.size(),cnt=1;
	int dp[m+1][n+1];

	for(int i=0; i <=m; i++) dp[i][0]=i;
	for(int j=0; j <=n; j++) dp[0][j]=j;

	for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
        if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]);
        }
    }
	
   printf("%d\n",dp[m][n]);
   int x=m, y=n;

   while(x || y){
       if( a[x-1]==b[y-1]){
       	x--,y--;
       	continue;
       }
        printf("%d ",cnt);
        cnt++;
        if(x && dp[x][y] == dp[x-1][y]+1){
        	printf("Delete %d\n",x);
        	a.erase(x-1,1);
        	x--;
        }else if(y && dp[x][y]== dp[x][y-1]+1){
        	printf("Insert %d,%c\n",x+1,b[y-1]);
        	a.insert(x,1,b[y-1]);
        	y--;
        }else if(x && y){
        	printf("Replace %d,%c\n",x,b[y-1]);
        	a[x-1]=b[y-1];
        	x--,y--;
        }
   }

}