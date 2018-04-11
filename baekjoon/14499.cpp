#include <bits/stdc++.h>
using namespace std;

int N,M,x,y,K;
int a[21][21];
int b[1001];
int dice[7];
int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};

int main() {
	scanf("%d %d %d %d %d",&N,&M,&y,&x,&K);
	for(int i=0;i<N;i++) for(int j=0;j<M;j++) scanf("%d",&a[i][j]);
	for(int i=0;i<K;i++) scanf("%d",&b[i]);
	for(int i=0;i<K;i++) {
		if(x+dx[b[i]%4]<0||y+dy[b[i]%4]<0||x+dx[b[i]%4]>=M||y+dy[b[i]%4]>=N) continue;
		int tmp;
		if(b[i]==1) {
			tmp=dice[1];
			dice[1]=dice[4];
			dice[4]=dice[6];
			dice[6]=dice[3];
			dice[3]=tmp;
		}
		else if(b[i]==2) {
			tmp=dice[1];
			dice[1]=dice[3];
			dice[3]=dice[6];
			dice[6]=dice[4];
			dice[4]=tmp;
		}
		else if(b[i]==3) {
			tmp=dice[1];
			dice[1]=dice[5];
			dice[5]=dice[6];
			dice[6]=dice[2];
			dice[2]=tmp;
		}
		else if(b[i]==4) {
			tmp=dice[1];
			dice[1]=dice[2];
			dice[2]=dice[6];
			dice[6]=dice[5];
			dice[5]=tmp;
		}
		x+=dx[b[i]%4];
		y+=dy[b[i]%4];
		if(a[y][x]==0) { a[y][x]=dice[1]; }
		else {
			dice[1]=a[y][x];
			a[y][x]=0;
		}
		printf("%d\n",dice[6]);
	}
	return 0;
}
