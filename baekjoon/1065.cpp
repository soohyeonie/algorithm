#include <iostream>
using namespace std;
int N;
int cnt;
int chk[5];

int main() {
	cin>>N;
	for(int i=1;i<=N;i++) {
		int tmp=i;
		int len=0;
		
		while(tmp) {
			len++;
			chk[len]=tmp%10;
			tmp/=10;
		}
		if(len<=2) {
			cnt++;
		} else {
			bool chk2=false;
			for(int j=1;j<len-1;j++) {
				if(chk[j]-chk[j+1]!=chk[j+1]-chk[j+2]) chk2=true;
			}
			if(!chk2) cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
