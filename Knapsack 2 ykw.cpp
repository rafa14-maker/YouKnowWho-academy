#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 1e5+5;

void solve()
{
  //  cout<<"yes"<<endl;
  int n,w;
  cin>>n>>w;

  ll val[n+5],wei[n+5];
  for(int i=1;i<=n;i++)cin>>wei[i]>>val[i];

 ll dp[N];
  memset(dp,-1,sizeof dp);
  dp[0] = 0;

  for(int j=1;j<=n;j++)
  {
      for(int i=N;i>=1;i--)
      {
          if(i >= val[j] && dp[i-val[j]] != -1)
          {
              if(dp[i] == -1)dp[i] = dp[i-val[j]]+wei[j];
              else dp[i] = min(dp[i],dp[i-val[j]]+wei[j]);
          }
      }
  }

  ll mx = 0;

  for(int i=1;i<N;i++)
  {
      if(dp[i]<=w&&dp[i]!=-1)mx = i;
  }


  cout << mx << endl;

}

int main()
{
    CherryFrog;
   //int q;cin>>q;while(q--)solve();
  solve();
}

