#include <iostream>
#include <vector>
using namespace std;

int T,N;
int main() {
	cin>>T;
	for(int t=1;t<=T;t++) {
		vector<int> vec;
		long long result=0;
		cin>>N;
		for(int i=0,input;i<N;i++) {
			cin>>input;
			vec.push_back(input);
		}	
		int s=0,e=0;
		while(s<N) {
			int maxv=0;
			for(int i=s;i<N;i++) {
				if(maxv < vec[i]) {
					maxv = vec[i];
					e=i;
				}
			}
			for(int i=s;i<e;i++) {
				if(maxv > vec[i]) {
					result += maxv-vec[i];
				}
			}
			s=e+1;
		}
		cout<<"#"<<t<<" "<<result<<endl;
	}
	return 0;
}
