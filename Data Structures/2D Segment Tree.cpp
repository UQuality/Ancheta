/**
	2D segment tree implementation
	Query complexity: O(log n * log m)
	Update complexity: O(log n * log m)
	Build complexity: O(n*m)
*/
#include <bits/stdc++.h>
#define lf(n) (n << 1)
#define rt(n) lf(n)|1

using namespace std;

int n = 1010;

const int N = 1010;

int a[N][N], t[(1<<11)][(1<<11)];

bool isValid(int l, int r, int i, int j){
	if(l > r || i > r || j < l) return 0;
	return 1;
}

void build_y(int nx, int lx, int rx, int ny, int ly, int ry){
	if(ly == ry){
		if(lx == rx) t[nx][ny] = a[lx][ly];
		else t[nx][ny] = max(t[lf(nx)][ny],t[rt(nx)][ny]);
	}
	else{
		int my = (ly + ry) >> 1;
		build_y(nx,lx,rx,lf(ny),ly,my);
		build_y(nx,lx,rx,rt(ny),my + 1,ry);
		t[nx][ny] = max(t[nx][lf(ny)], t[nx][rt(ny)]);
	}
}

void build_x(int nx, int lx, int rx){
	if(lx != rx){
		int mx = (lx + rx) >> 1;
		build_x(lf(nx),lx,mx);
		build_x(rt(nx),mx + 1,rx);
	}
	build_y(nx,lx,rx,1,1,n);
}

int query_y(int nx, int ny, int ly, int ry, int iy, int jy){
	if(!isValid(ly,ry,iy,jy)) return -1;
	if(iy <= ly && jy >= ry) return t[nx][ny];
	int my = (ly + ry) >> 1;
	return max(query_y(nx, lf(ny), ly, my, iy, jy), query_y(nx, rt(ny), my + 1, ry, iy, jy));
}

int query_x(int nx, int lx, int rx, int ix, int jx, int iy, int jy){
	if(!isValid(lx,rx,ix,jx)) return -1;
	if(ix <= lx && jx >= rx) return query_y(nx,1,1,n,iy,jy);
	int mx = (lx + rx) >> 1;
	return max(query_x(lf(nx),lx,mx, ix,jx,iy,jy), query_x(rt(nx),mx+1,rx,ix,jx,iy,jy));
}

void update_y(int nx, int lx, int rx, int ny, int ly, int ry, int iy, int v){
	if(ly == ry){
		if(lx == rx) t[nx][ny] = v;
		else t[nx][ny] = max(t[lf(nx)][ny],t[rt(nx)][ny]);
	}else{
		int my = (ly + ry) >> 1;
		if(ly <= iy && iy <= my) update_y(nx,lx,rx,lf(ny),ly,my,iy,v);
		else update_y(nx,lx,rx,rt(ny),my + 1,ry,iy,v);
	}
}

void update_x(int nx, int lx, int rx, int ix, int iy, int v){
	if(lx != rx){
		int mx = (lx + rx) >> 1;
		if(lx <= ix && ix <= mx) update_x(lf(nx),lx, mx, ix, iy, v);
		else update_x(rt(nx), mx + 1, rx, ix, iy, v);
	}
	update_y(nx,lx,rx,1,1,n,iy,v);
}
