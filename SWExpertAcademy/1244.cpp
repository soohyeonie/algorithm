#include <iostream>
using namespace std;
int C;
int num[6];
int maxv;
void SWAP(int tmp[],int len, int n) {
	if(n!=0) {
		for(int i=0;i<len;i++) {
			for(int j=i+1;j<len;j++) {
				if(tmp[i]!=tmp[j]) {
					int temp=tmp[i];
					tmp[i]=tmp[j];
					tmp[j]=temp;
					SWAP(tmp,len,n-1);	
				}
			}
		}
	} else {
		int tmpr=0;
		for(int k=len-1;k>=0;k--) {
			int tmpv=tmp[k];
			for(int m=0;m<k;m++) {
				tmpv*=10;
			}
			tmpr+=tmpv;
		}
		maxv = maxv > tmpr ? maxv : tmpr;
	}
}
int main() {
	cin>>C;
	for(int c=1,input,cn,len;c<=C;c++) {
		len=0;
		maxv=0;
		cin>>input>>cn;
		int tmp=input;
		while(tmp>0) {
			num[len++]=tmp%10;
			tmp/=10;
		}
		SWAP(num,len,cn);
		cout<<"#"<<c<<" "<<maxv<<endl;
	}
}
