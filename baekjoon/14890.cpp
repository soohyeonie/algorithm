#include <bits/stdc++.h>
using namespace std;
int N,L;
int a[101][101];
int ans;


void func(int d,int x,int y,int cnt) {
	//가로 
	if(d==0) { if(x>=N-1) { ans+=1; return; } }
	else if(d==1) { if(y>=N-1) { ans+=1; return; } }
	int dx,dy; 
	//가로
	if(d==0) { dx=1,dy=0; }
	else if(d==1) { dx=0,dy=1; }
	
	if(a[y][x]+1==a[y+dy][x+dx]) {
		if(cnt>=L) func(d,x+dx,y+dy,1);
	} else if(a[y][x]==a[y+dy][x+dx]+1) {
		for(int i=2;i<=L;i++)
			if(a[y][x]-1!=a[y+dy*i][x+dx*i]) return;
		func(d,x+dx*L,y+dy*L,0);
	} else if(a[y][x]==a[y+dy][x+dx]) {
		func(d,x+dx,y+dy,cnt+1);
	}
}

int main() {
	cin>>N>>L;
	for(int i=0;i<N;i++) for(int j=0;j<N;j++) cin>>a[i][j];
	for(int i=0;i<N;i++) {
		func(1,i,0,1);
		func(0,0,i,1);
	}
	cout<<ans;
	return 0;
}
