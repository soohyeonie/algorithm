//14891 rotate(), include <bits/stdc++.h>, recursive 
#include <bits/stdc++.h>
using namespace std;

int wheel[4][8];
bool isRotated[4];

int main() {
   for(int i=0;i<4;i++) {
      for(int j=0;j<8;j++) {
         scanf("%1d",&wheel[i][j])
      }
   }
   
   int k; cin>>k;
   while(k--) {
      int idx,direction;
      cin>>idx>>direction;
      memset(isRotated,false,sizeof(isRotated));
      go(idx-1,direction);
   }
   
   int ans=0;
   for(int i=0;i<4;i++) {
      ans+=wheel[i][0]*(1<<i);
   }
   
   cout<<ans<<endl;
   return 0;
}
