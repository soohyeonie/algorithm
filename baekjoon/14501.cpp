#include <bits/stdc++.h>
using namespace std;

int N;
int T[16];
int P[16];

int func(int t) {
	if(t+T[t]-1<=N&&t+1<=N) return func(t+1) > P[t]+func(t+T[t])? func(t+1) : P[t]+func(t+T[t]);
	if(t+T[t]-1>N&&t+1<=N) return func(t+1);
	if(t+T[t]-1<=N&&t+1>N) return P[t]+func(t+1);
	if(t+T[t]-1>N&&t+1>N) return 0;
}

int main() {
	cin>>N;
	for(int i=1;i<=N;i++) { cin>>T[i]>>P[i]; }
	cout<<func(1);
	return 0;
}
