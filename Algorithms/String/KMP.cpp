# include <bits/stdc++.h>
#define MAX_VALOR 100010
using namespace std;

char T[MAX_VALOR] , P[MAX_VALOR];
int b[MAX_VALOR],n,m;

void KMP(){
// Pre procesamiento
int i=0, j=-1; b[0]=-1;
   while(i < m){
    while( j>=0 && P[i] != P[j] ){
	   j=b[j];
	} 
     i++; j++;
	b[i]=j;
    }
//busqueda
i=0,j=0;
    while( i < n){
     while( j>=0 && T[i] != P[j]){
	j=b[j];
      }
     i++; j++;
      if( j == m){
	 j=b[j];
      }
    }
}




int main(){

    scanf("%[^\n] %[^\n]",T,P);
    n=strlen(T);
    m=strlen(P);
    KMP();

return 0;
}
