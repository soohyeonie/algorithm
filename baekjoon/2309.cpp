#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec;
int m[9];
int sum;

int main() {
	for(int i=0;i<9;i++) {
		cin>>m[i];
		sum+=m[i];
	}
	for(int i=0;i<9;i++) {
		for(int j=0;j<9;j++) {
			if(i!=j&&sum-m[i]-m[j]==100) {
				for(int k=0;k<9;k++) {
					if(k!=i&&k!=j)
						vec.push_back(m[k]);
				}
				sort(vec.begin(),vec.end());
				for(int k=0;k<7;k++) {
					cout<<vec[k]<<endl;
				}
				return 0;
			}
		}
	}
	return 0;
}
