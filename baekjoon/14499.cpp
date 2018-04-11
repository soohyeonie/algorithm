#include <bits/stdc++.h>
using namespace std;

int N,M,x,y,K;
int a[20][20];
int b[1000];
int dice[7];
int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};

int main() {
	scanf("%d %d",&N,&M);
	scanf("%d %d %d",&x,&y,&K);
	for(int i=0;i<N;i++) for(int j=0;j<M;j++) scanf("%d",&a[i][j]);
	for(int i=0;i<K;i++) scanf("%d",&b[i]);
	int t=K;
	for(int i=0;i<K;i++) {
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
			
		}
		else if(b[i]==4) {
			
		}
	}
	return 0;
}
