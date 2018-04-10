#include <bits/stdc++.h>
using namespace std;

int a[101][101];
int N,K,L;
struct turn {
	int x;
	char D;
};
turn b[101];
int tc;
int ans;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int hd,td;
int hx=1,hy=1,tx=1,ty=1;
int hi,ti;

bool chk(int x,int y) {
	if(x<1||x>N||y<1||y>N||a[y][x]==2) return false;
	return true;
}

int main() {
	scanf("%d %d",&N,&K);
	for(int i=0,x,y;i<K;i++) { scanf("%d%d",&y,&x); a[y][x]=1; }
	scanf("%d",&L);
	for(int i=0;i<L;i++) { scanf("%d %c",&b[i].x,&b[i].D); }
	b[L].x==20000;
	a[hy][hx]=2;
	while(++ans) {
		hx+=dx[hd]; hy+=dy[hd];
		if(!chk(hx,hy)) return ~printf("%d",ans);
		if(a[hy][hx]==0) { a[ty][tx]=0; tx+=dx[td]; ty+=dy[td]; tc++; }
		a[hy][hx]=2;
		if(ans==b[hi].x) {
			if(b[hi].D=='D') hd = (hd+1)%4;
			if(b[hi].D=='L') hd = (hd==0)? 3: hd-1;
			hi++;
		}
		if(tc==b[ti].x) {
			if(b[ti].D=='D') td = (td+1)%4;
			if(b[ti].D=='L') td = (td==0)? 3: td-1;
			ti++;			
		}
	}
	return 0;
}
