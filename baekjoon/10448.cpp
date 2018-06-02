#include <iostream>
using namespace std;
int T,K;
bool chk[1001];
int t[46];
int main(){
	cin>>T;
	for(int i=1;i<=45;i++) {
		t[i]=(i*(i+1))/2;
	}
	for(int i=1;i<=45;i++) {
		for(int j=1;j<=45;j++) {
			for(int k=1;k<=45;k++) {
				if(t[i]+t[j]+t[k]<=1000&&!chk[t[i]+t[j]+t[k]]) {
					chk[t[i]+t[j]+t[k]]=true;
				}
			}
		}
	}
	while(T--) {
		cin>>K;
		if(chk[K]) {
			cout<<"1"<<endl;
		} else {
			cout<<"0"<<endl;
		}	
	}
	return 0;
}
