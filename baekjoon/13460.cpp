#include <bits/stdc++.h>
using namespace std;
int N,M;
char a[12][12];
int rx,ry,bx,by;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool chk[11][11][11][11];
int ans=-1;

struct ABC {
	int cnt;
	int rx;
	int ry;
	int bx;
	int by;
};
queue<ABC> que; 

void BFS(ABC b) {
	que.push(b);
	while(!que.empty()) {
		ABC now = que.front();
		que.pop();
		for(int i=0;i<4;i++) {
			int cb=0,cr=0;
			int nrx = now.rx;
			int nry = now.ry;
			int nbx = now.bx;
			int nby = now.by;
			while(a[nrx+dx[i]][nry+dy[i]]!='#'&&a[nrx][nry]!='O') { nrx+=dx[i]; nry+=dy[i]; cr++; }
			while(a[nbx+dx[i]][nby+dy[i]]!='#'&&a[nbx][nby]!='O') { nbx+=dx[i]; nby+=dy[i]; cb++; }
			
			if(nby==nry&&nbx==nrx) {
				if(a[nbx][nbx]=='O') continue;
				cr < cb ? (nbx-=dx[i],nby-=dy[i]) : (nrx-=dx[i],nry-=dy[i]) ;
			}
			
			if(a[nbx][nby]=='O') continue;;
			if(a[nrx][nry]=='O') {
				ans=now.cnt+1;
				return;
			}
			
			if(chk[nrx][nry][nbx][nby]) continue;
			if(now.cnt<9) {
				chk[nrx][nry][nbx][nby]=true;
				que.push({now.cnt+1,nrx,nry,nbx,nby});
			}
		}
	}
}

int main() {
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++) {
		scanf("%s",a[i]);
		for(int j=0;j<M;j++) {
			if(a[i][j]=='R') rx=i,ry=j;	
			if(a[i][j]=='B') bx=i,by=j;
		}
	}
	chk[rx][ry][bx][by]=1;
	BFS({0,rx,ry,bx,by});
	printf("%d",ans);
	return 0;
}
