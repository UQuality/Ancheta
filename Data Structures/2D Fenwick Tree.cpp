/**
	2D Fenwick Tree (BIT) implementation
	Query complexity: O(log n*log m)
	Update complexity: O(log n*log m)
	Build complexity: O(n*m*log n*log m)
*/

#define ls(n) (n & (-n))
const int N = 1030;
int a[N][N], t[N][N], ni, nj;

void update(int i, int j, int v){
	for(; i <= ni; i += ls(i)){
		int aj = j;
		for(; aj <= nj; aj += ls(aj)) 
			t[i][aj] += v;
	}
}

void build(){
	for(int i = 1; i <= ni; i++)
		for(int j = 1; j <= nj; j++)
			update(i,j,a[i][j]);
}

int sum(int i, int j){
	int s = 0;
	for(; i ; i -= ls(i)){
		int aj = j;
		for(; aj ; aj -= ls(aj))
			s += t[i][aj];
	}
	return s;
}

int query(int i1, int j1, int i2, int j2){
	if(i1 < i2) swap(i1,i2); if(j1 < j2) swap(j1,j2);
	int n1 = sum(i2, j2);
	int n2 = sum(i1-1, j1-1);
	int n3 = sum(i1 - 1, j2);
	int n4 = sum(i2, j1 - 1);
	return n1 + n2 - n3 - n4;
}