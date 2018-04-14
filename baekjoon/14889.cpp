#include <bits/stdc++.h>
using namespace std;
int N;
int a[21][21];
bool Selected[21];
int c[20];
int d[20];
int ans=1000000;

void func(int n,int cnt) { 
	if(n>N) return;

	for(int i=0;i<2;i++) {
		if(i==0) {
			Selected[n]=false;
			func(n+1,cnt);
		}
		else if(i==1) {
			Selected[n]=true;
			if(cnt+1<N/2) { func(n+1,cnt+1); return; }
			for(int m=n+1;m<=N;m++) Selected[i]=false;
			printf("¸¸Á·\n");
			for(int j=1; j<=N; j++){
				printf("%d ",Selected[j]);
			}
			printf("\n");
			
			int cp=0,dp=0;
			int S=0,L=0;
			memset(c,0,20);
			memset(d,0,20);
			for(int j=1;j<=N;j++) if(Selected[j]) c[cp++]=i; else d[dp++];
			for(int j=0;j<N/2;j++) for(int k=0;k<N/2;k++) S+=a[c[j]][c[k]];
			for(int j=0;j<N/2;j++) for(int k=0;k<N/2;k++) L+=a[d[j]][d[k]];
			ans = ans > S-L? S-L : ans;
			return;
		}
	}
}

int main() {
	scanf("%d",&N);
	for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) scanf("%d",&a[i][j]);
	func(1,0);
	printf("%d",ans);
	return 0;
}
