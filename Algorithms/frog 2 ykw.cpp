#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve()
{
  //  cout<<"yes"<<endl;

  int n,k;
  cin>>n>>k;

  ll arr[n+5];
  for(int i=1;i<=n;i++)cin>>arr[i];

  ll dp[n+5];

  for(int i=1;i<=n;i++)dp[i] = 1e18+7;
  dp[1] = 0;

   for(int i=2;i<=n;i++)
   {
      for(int j=1;j<=k;j++)
      {
          if(i-j>=1)
          {
              dp[i] = min(dp[i],dp[i-j]+abs(arr[i]-arr[i-j]));
          }
      }
   }
  cout << dp[n]<<endl;

}

int main()
{
    CherryFrog;
   //int q;cin>>q;while(q--)solve();
  solve();
}

