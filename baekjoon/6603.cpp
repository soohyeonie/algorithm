#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int k, S;
bool bln[13];
vector<int> vec;

void func(int num,int cnt) {
	if(num>0&&cnt<6) {
		bln[k-num]=true;
		func(num-1,cnt+1);
		bln[k-num]=false;
		func(num-1,cnt);
	}
	if(cnt==6) {
		for(int i=0;i<k;i++) {
			if(bln[i]) {
				cout<<vec[i]<<" ";
			}
		}
		cout<<endl;
		return;
	}
	if(num==0) {
		return;
	}
}

int main() {
	while(1) {
		cin>>k;
		if(k==0)
			break;
		for(int i=0,a;i<k;i++) {
			cin>>a;
			vec.push_back(a);
		}
		sort(vec.begin(),vec.end());
		func(k,0);
		vec.clear();
		cout<<endl;
	}
	return 0;
}
