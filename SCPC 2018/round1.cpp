#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int T,N,K;
vector<int> A;

int main() {
	cin>>T;
	for(int t=0;t<T;t++) {
		cin>>N>>K;
		for(int i=0,a;i<N;i++) {
			cin>>a;
			A.push_back(a);
		}
		sort(A.begin(),A.end());
		int maxv=0;

		for(int i=0;i<N;i++) {
			int result=1;
			for(int j=1;j<=K&&i+j<N;j++) {
				if(abs(A[i]-A[i+j])<=K) {
					result++;
				} else {
					break;
				}
			}
			maxv = maxv > result ? maxv : result;
			if(maxv==K+1) {
			    break;
			}
		}
		cout<<"Case #"<<t+1<<endl;
		cout<<maxv<<endl;
		A.clear();
	}
	return 0;
}
