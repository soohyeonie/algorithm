#include <iostream>
#include <vector>
using namespace std;
int X,Y;
int t=1;
int dx[] = {-2 , -1 , 1, 2};
int main() {
	while(t<=10) {
		vector<int> vec;
		int result=0;
		cin>>X;
		for(int i=0,Y;i<X;i++) {
			cin>>Y;
			vec.push_back(Y);
		}
		for(int i=2;i<X-2;i++) {
			int maxv=0;
			for(int j=0;j<4;j++) {
				maxv = maxv > vec[i+dx[j]] ? maxv : vec[i+dx[j]];	
			}
			if(maxv<vec[i]) {
				result+=vec[i]-maxv;
			}
		}
		cout<<"#"<<t<<" "<<result<<endl;
		t++;
	}
	return 0;
}
