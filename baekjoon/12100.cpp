#include <bits/stdc++.h>
using namespace std;

int N;
int maxv;
int a[6][20][20];
int b[20][20];
int c[20];

void Init(int cnt) {
	for(int i=0;i<N;i++) for(int j=0;j<N;j++) a[cnt][i][j]=a[cnt-1][i][j];
}

void Push(int cnt,int d) {
	for(int i=0;i<N;i++) for(int j=0;j<N;j++) b[i][j]=a[cnt][i][j];
	if(d==1) for(int i=0;i<N;i++) for(int j=0;j<N;j++) a[cnt][i][j]=b[N-j-1][i];
	if(d==2) for(int i=0;i<N;i++) for(int j=0;j<N;j++) a[cnt][i][j]=b[N-i-1][N-j-1];
	if(d==3) for(int i=0;i<N;i++) for(int j=0;j<N;j++) a[cnt][i][j]=b[j][N-i-1];
	
	for(int j=0;j<N;j++) {
		int k=0;
		int p=0;
		for(int i=0;i<N;i++) c[i]=0;
		for(int i=0;i<N;i++) {
			if(a[cnt][i][j]!=0) {
				if(k==0) {
					k=a[cnt][i][j];
				}
				else if(k!=0&&k==a[cnt][i][j]) {
					k+=k;
					c[p++]=k;
					k=0;
				}
				else if(k!=0&&k!=a[cnt][i][j]) {
					c[p++]=k;
					k=a[cnt][i][j];
				}
			}
			if(k!=0&&i+1==N) c[p++]=k;
		}
		for(int i=0;i<N;i++) {
			a[cnt][i][j]=c[i];
		}
	}
}

void func(int cnt) {
	for(int i=0;i<4;i++) {
		Init(cnt);
		Push(cnt,i);
		if(cnt+1<=5) func(cnt+1);
		if(cnt==5) for(int m=0;m<N;m++) for(int n=0;n<N;n++) maxv = maxv > a[cnt][m][n]? maxv : a[cnt][m][n];
	/*
		if(cnt==1)
			for(int m=0;m<N;m++) {
				for(int n=0;n<N;n++) printf("%3d",a[cnt][m][n]);
				cout<<endl;
			}
	*/
	}
}

int main() {
	scanf("%d",&N);
	for(int i=0;i<N;i++) for(int j=0;j<N;j++) scanf("%d",&a[0][i][j]);
	func(1);
	cout<<maxv;
	return 0;
}
