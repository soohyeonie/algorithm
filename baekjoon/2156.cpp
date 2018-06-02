#include <iostream>
#include <vector>
using namespace std;
int N;
int g[10001];
int d[10001];
int main() {
	cin>>N;
	for(int i=0,k;i<N;i++) {
		cin>>g[i];
	}
	d[1]=g[1];
	d[2]=g[1]+g[2];
	for(int i=3;i<=N;i++) {
		int maxv = d[i-2]+g[i] > d[i-3]+g[i-1]+g[i] ? d[i-2]+g[i] : d[i-3]+g[i-1]+g[i];
		maxv = d[i-1] > maxv ? d[i-1] : maxv;
		d[i] = maxv;
	}
	cout<<d[N]<<endl;
	return 0;
}
