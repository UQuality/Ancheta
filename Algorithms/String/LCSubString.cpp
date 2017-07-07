// DP- Longest Common Substring

#include <bits/stdc++.h>
using namespace std;

int LCSubStr(string a,string b){
 int tma=a.size(),tmb=b.size();
 int dp[tma+1][tmb+1];
 int res=0;

 	for(int i=0; i<= tma ; i++){
 		for(int j=0 ; j <= tmb ; j++){
 			if(i==0 || j==0)
 				dp[i][j]=0;
 			else if(a[i-1]==b[j-1]){
 				dp[i][j]=dp[i-1][j-1]+1;
 				res=max(res,dp[i][j]);
 			}else{
 				dp[i][j]=0;
 			}
 		}
 	}
 return res;
}


int main(){
string a,b;
  while(getline(cin,a)&&getline(cin,b)){
       cout << LCSubStr(a,b) << endl;
  }

	return 0;
}