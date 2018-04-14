#include <bits/stdc++.h>
using namespace std;

int N,M;
char a[11][11];
int ans=11;

//»óÁÂÇÏ¿ì 
int dx[] = {0,-1,0,1}; 
int dy[] = {-1,0,1,0};

void pushmap(int Rx,int Ry,int Bx,int By,int cnt) {
	if(cnt>10) return;	
	int TRx, TRy, TBx, TBy;
	
	for(int i=0;i<4;i++) {
		TRx=Rx; TRy=Ry; TBx=Bx; TBy=By;
		while(1) {
	 		TRx+=dx[i]; TRy+=dy[i]; 
	 		if(TRx<0||TRx>=M||TRy<0||TRy>=N||a[TRy][TRx]=='#') { TRx-=dx[i]; TRy-=dy[i]; break; }
	 		if(a[TRy][TRx]=='O') { break; }
		}
		while(1) {
	 		TBx+=dx[i]; TBy+=dy[i]; 
	 		if(TBx<0||TBx>=M||TBy<0||TBy>=N||a[TBy][TBx]=='#') { TBx-=dx[i]; TBy-=dy[i]; break; }
	 		if(a[TBy][TBx]=='O') { break; }
		}
	//	printf("%d %d %d %d %d\n",TRx,TRy,TBx,TBy,cnt);
		if(TRx==TBx&&TRy==TBy) {
			if(a[TRy][TRx]=='O') { continue; }
			else {
				if(i==0) { if(Ry<By) TBy-=dy[i]; else TRy-=dy[i]; }
				else if(i==1) { if(Rx>Bx) TRx-=dx[i]; else TBx-=dx[i]; }
				else if(i==2) { if(Ry>By) TBy-=dy[i]; else TRy-=dy[i]; }
				else if(i==3) { if(Rx<Bx) TRx-=dx[i]; else TBx-=dx[i]; }
			}
			pushmap(TRx,TRy,TBx,TBy,cnt+1);
		}
		else {
			if(a[TRy][TRx]=='O') { ans = ans > cnt+1 ? cnt+1 : ans; return; }
			if(a[TBy][TBx]=='O') { continue; }
			pushmap(TRx,TRy,TBx,TBy,cnt+1);
		}
	}
}

int main() {
	int Rx,Ry,Bx,By;
	cin>>N>>M;
	for(int i=0;i<N;i++) {
		cin>>a[i];
		for(int j=0;j<M;j++) {
			if(a[i][j]=='R') { a[i][j]=='.'; Ry=i; Rx=j; }
			if(a[i][j]=='B') { a[i][j]=='.'; By=i; Bx=j; }
		}
	}
	pushmap(Rx,Ry,Bx,By,0);
	if(ans>10) cout<<"-1";
	else cout<<ans;
	return 0;
}
