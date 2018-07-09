#include <iostream>
#include <vector>
using namespace std;
int T,N,M;
int minv;

void func(int n,vector<vector<int> > k) {
	int result=n;
	for(int i=0;i<=N;i++) {
		vector<vector<int> > tmp;
		for(int j=0;j<=N;j++) {
			vector<vector<int> > 
		}

		if(tmp[i].size()==2) {
			for(int j=0;j<tmp[tmp[i][0]].size();j++) {
				if(tmp[tmp[i][0]][j]==tmp[i][1]) {
					for(vector<int>::iterator iter=tmp[tmp[i][0]].begin();iter!=tmp[tmp[i][0]].end();iter++) {
						if(*iter==i) {
							tmp[tmp[i][0]].erase(iter);
						}
					}
					for(vector<int>::iterator iter=tmp[tmp[i][1]].begin();iter!=tmp[tmp[i][1]].end();iter++) {
						if(*iter==i) {
							tmp[tmp[i][1]].erase(iter);
							tmp[i].clear();
						}
					}
					minv = minv > n-1 ? n-1 : minv;
					func(n-1,tmp);
				}
			}
		}
	}
}

int main() {
	cin>>T;
	for(int t=1;t<=T;t++) {
		cin>>N>>M;
		
		int result=0;
		vector<vector<int> > vec(N+1);
		
		for(int i=0,a,b;i<M;i++) {
			cin>>a>>b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		minv=N;
		func(N,vec);
		
		cout<<"Case #"<<t<<endl;
		cout<<minv<<endl;
	}
	return 0;
}
