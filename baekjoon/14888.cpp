#include <bits/stdc++.h>
using namespace std;

int N;
int a[12];
vector<int> b;

long long ans;
long long ansmax=-1000000001;
long long ansmin=1000000001;

int main() {
	cin>>N;
	for(int i=0;i<N;i++) cin>>a[i];
	for(int i=1,k;i<=4;i++) { cin>>k; while(k--){ b.push_back(i); } }
	do {
		ans=a[0];
		for(int i=0;i<N-1;i++) {
			if(b[i]==1) ans+=a[i+1];
			else if(b[i]==2) ans-=a[i+1];
			else if(b[i]==3) ans*=a[i+1];
			else if(b[i]==4) ans/=a[i+1];
		}
	/*
		cout<<a[0];
		for(int i=0;i<N-1;i++) {
			if(b[i]==1) cout<<"+";
			else if(b[i]==2) cout<<"-";
			else if(b[i]==3) cout<<"*";
			else if(b[i]==4) cout<<"/";
			cout<<a[i+1];
		}
		cout<<endl;
	*/ 
		ansmax = ansmax > ans ? ansmax : ans;
		ansmin = ansmin < ans ? ansmin : ans;
	} while(next_permutation(b.begin(),b.end()));
	
	cout<<ansmax<<endl;
	cout<<ansmin<<endl;
	return 0;
}
