#include <bits/stdc++.h>
using namespace std;

int N;
int a[1000000];
int B,C;
long long ans;

int main() {
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",&a[i]);
	scanf("%d %d",&B,&C);
	for(int i=0;i<N;i++) {
		a[i]-=B;
		ans++;
		if(a[i]>0) {
			if(a[i]%C==0) ans+=a[i]/C;
			else ans+=a[i]/C+1;
		}
	}
	printf("%lld",ans);
	return 0;
}
