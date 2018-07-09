#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m[9][9];
vector<int> vec;

int main() {
	for(int i=0;i<9;i++) {
		for(int j=0;j<9;j++) {
			cin>>m[i][j];
			if(m[i][j]==0) vec.push_back(i*10+j);
		}
	}

	for(int i=0;i<vec.size();i++) {
		int cnt=0,sum=0,chk=0;
		for(int j=0;j<9;j++) {
			if(m[vec[i]/10][j]==0) {
				cnt++;
			}
			sum+=m[vec[i]/10][j];
		}
		if(cnt==1) {
			for(int j=0;j<9;j++) {
					if(m[vec[i]/10][j]==0) {
						m[vec[i]/10][j]=45-sum;
						vec.erase(vec.begin()+i);
						chk=1;
						break;
					}
				}
				if(chk) {
					i--;
					continue;
				}
			}
			cnt=0,sum=0,chk=0;
			for(int j=0;j<9;j++) {
				if(m[j][vec[i]%10]==0) {
					cnt++;
				}
				sum+=m[j][vec[i]%10];
			}
			if(cnt==1) {
				for(int j=0;j<9;j++) {
					if(m[j][vec[i]%10]==0) {
						m[j][vec[i]%10]=45-sum;
						vec.erase(vec.begin()+i);
						chk=1;
						break;
					}
				}
				if(chk) {
					i--;
					continue;
				}
			}
		}

	for(int i=0;i<9;i++) {
		for(int j=0;j<9;j++) {
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
}
