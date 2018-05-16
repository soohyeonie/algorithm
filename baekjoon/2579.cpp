#include <iostream>
using namespace std;
int N;
int stair[301];
int dp[301];

int main() {
	cin >> N;
	for(int i=0;i<N;i++) {
		cin>>stair[i];
	}
	
	dp[0] = stair[0];
	dp[1] = stair[0] + stair[1];
	dp[2] = stair[0] + stair[2] > stair[1] + stair[2]? stair[0] + stair[2] : stair[1] + stair[2];

	for(int i=3;i<N;i++) {
		dp[i] = dp[i-2]+stair[i] > dp[i-3]+stair[i]+stair[i-1]?dp[i-2]+stair[i] : dp[i-3]+stair[i]+stair[i-1];
	}
	
	cout<<dp[N-1]<<endl;
	return 0;
}
