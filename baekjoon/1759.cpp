#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int L,C;
vector<char> vec;
bool bln[15];
char k[15];

void func(int num,int cnt) {
	if(num>0&&cnt<L) {
		bln[C-num]=true;
		func(num-1,cnt+1);
		bln[C-num]=false;
		func(num-1,cnt);
	}
	
	if(cnt==L) {
		int m=0, j=0;
		for(int i=0;i<C;i++) {
			if(bln[i]) {
				k[m+j]=vec[i];
				if(vec[i]=='a'||vec[i]=='e'||vec[i]=='i'||vec[i]=='o'||vec[i]=='u') {
					m++;
				} else {
					j++;
				}
			}
		}
		if(m<1||j<2) return;
		for(int i=0;i<L;i++) {
			cout<<k[i];
		}
		cout<<endl;
		return;
	}
	if(num==0) {
		return;
	}
}

int main() {
	cin>>L>>C;
	char a;
	for(int i=0;i<C;i++) {
		cin>>a;
		vec.push_back(a);
	}
	sort(vec.begin(),vec.end());
	func(C,0);
	return 0;
}
