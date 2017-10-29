/** KMP pattern matching
    finds occurrences of pattern P in text T
    Complexity: O(n + m)
*/

char T[MAX], P[MAX];
int b[MAX], n, m; //n = |T|, m = |P|

void KMP(){
	//Preprocess
	int i = 0, j = -1; b[0] = -1;
	while(i < m){
		while( j>=0 && P[i] != P[j] ) j = b[j];
		i++; j++;
		b[i] = j;
	}
	//Search
	i = 0, j = 0;
	while(i < n){
		while( j>=0 && T[i] != P[j] ) j = b[j];
		i++; j++;
		if(j == m) j = b[j];
	}
}