#include <bits/stdc++.h>
using namespace std;

int N,M,r,c,d;
int Map[50][50];
int visited[50][50];
int ans;
int dy[] = {-1,0,1,0};
int dx[] = {0,-1,0,1};

bool check(int ax,int ay) {
	if(ax>=1&&ax<=M&&ay>=1&&ay<=N)
		return true;
	else
		return false;
}

void BFS(int r,int c,int d) {
	if(!visited[c][r]) {
		ans++;
		visited[c][r]=1;
	}
	for(int cnt=0;cnt!=4;) {
		int ad = (d+1)%4;
		int ax = r+dx[ad], ay = c+dy[ad];
		if(!check(ax,ay)||visited[ay][ax]||Map[ay][ax]) {
			ad = (ad+1)%4;
			cnt++;
			continue;
		}
		BFS(ax,ay,ad);
		return;
	}
	int ad = (d+2)%4;
	int ax = r+dx[ad], ay = c+dy[ad];
	if(!check(ax,ay)&&!Map[ay][ax])
		BFS(ax,ay,ad);
	return;
}

int main() {
	cin>>N>>M;
	cin>>r>>c>>d;
	for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin>>Map[i][j];
	BFS(r,c,d);
	cout<<ans<<endl;
	return 0;
}
