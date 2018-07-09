#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int R[199];

int main() {
	int cnt=0;
	for(int i=0;i<=9;i++) {
		R[cnt++]=i;
	}
	for(int i=1;i<=9;i++) {
		R[cnt++]=i*10+i;
	}
	for(int i=1;i<=9;i++) {
		for(int j=0;j<=9;j++) {
			R[cnt++]=i*100+j*10+i;
		}
	}
	for(int i=1;i<=9;i++) {
		for(int j=0;j<=9;j++) {
			R[cnt++]=i*1000+j*100+j*10+i;
		}
	}	
	cin>>T;
	for(int t=0,n;t<T;t++) {
		cin>>n;
		int result;
		int minv=4;
		vector<int> vec;
		for(int i=0;i<cnt;i++) {
			for(int j=0;j<cnt;j++) {
				for(int k=0;k<cnt;k++) {
					if(R[i]+R[j]+R[k]==n) {
						result=3;
						if(!R[i]) result--;
						if(!R[j]) result--;
						if(!R[k]) result--;
						
						if(minv>result) {
							minv=result;
							vec.clear();
							if(R[i]) vec.push_back(R[i]);
							if(R[j]) vec.push_back(R[j]);
							if(R[k]) vec.push_back(R[k]);
							sort(vec.begin(),vec.end());
						}
					}
				}
			}
		}
		cout<<"Case #"<<t+1<<endl;
		if(minv==4) {
			cout<<"0"<<endl;
		} else {
			cout<<minv;
			for(int i=vec.size()-1;i>=0;i--) {
				cout<<" "<<vec[i];
			}
			cout<<endl;
		}
	}
}
