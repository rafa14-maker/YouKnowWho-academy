#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve()
{
  //  cout<<"yes"<<endl;

  int n;
  cin>>n;

  ll arr[n+5];
  for(int i=1;i<=n;i++)cin>>arr[i];

  ll dp[n+5];

  for(int i=1;i<=n;i++)dp[i] = 1e18+7;
  dp[1] = 0;

   for(int i=2;i<=n;i++)
   {
       if(i-1>=1)dp[i] = min(dp[i],dp[i-1]+abs(arr[i]-arr[i-1]));
       if(i-2>=1)dp[i] = min(dp[i],dp[i-2]+abs(arr[i]-arr[i-2]));
   }
  cout << dp[n]<<endl;
}

int main()
{
    CherryFrog;
   //int q;cin>>q;while(q--)solve();
  solve();
}

