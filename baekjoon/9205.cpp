#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int T,n;

int sx,sy;
int ex,ey;
struct conv{
	int x;
	int y;
	bool visited;
};
int flag;

void DFS(vector<conv> v,int nx,int ny) {
	if(flag) {
		return;
	}
	if(abs(ex-nx)+abs(ey-ny)<=1000) {
		flag=1;
		return;
	}
	vector<int> tv;
	for(int i=0;i<v.size();i++) {
		if(abs(v[i].x-nx)+abs(v[i].y-ny)<=1000&&!v[i].visited) {
			v[i].visited = true;
			tv.push_back(i);
		}
	}
	for(int i=0;i<tv.size();i++) {
		DFS(v,v[tv[i]].x,v[tv[i]].y);
	}
}

int main() {
	cin>>T;
	for(int t=0,x,y;t<T;t++) {
		flag = 0;
		cin>>n;
		cin>>sx>>sy;
		vector<conv> vec;
		for(int i=0;i<n;i++) {
			cin>>x>>y;
			vec.push_back({x,y,false});
		}
		cin>>ex>>ey;
		
		DFS(vec,sx,sy); 
		if(flag==1) {
			cout<<"happy"<<endl;
		} else {
			cout<<"sad"<<endl;
		}
	}
	return 0;
}
