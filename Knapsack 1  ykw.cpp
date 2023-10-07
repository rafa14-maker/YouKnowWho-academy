#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 1e5+5;

int n,weight;
ll wei[105],val[105];
ll dp[105][N];

ll f(int pos,int w)
{
    //cout<<w<<endl;
    if(w > weight)return -(1e8+7);
    if(w == weight)return 0;
    if(pos ==n)return 0;
    if(dp[pos][w] != -1)return dp[pos][w];
    ll ans = 0;
    ans = max(ans,f(pos+1,w));
    ans = max(ans,val[pos]+f(pos+1,w+wei[pos]));
    return dp[pos][w] = ans;
}

void solve()
{
  //  cout<<"yes"<<endl;
  cin>>n>>weight;

  for(int i=0;i<n;i++)cin>>wei[i]>>val[i];

  memset(dp,-1,sizeof dp);

  cout <<f(0,0)<<"\n";
}

int main()
{
    CherryFrog;
   //int q;cin>>q;while(q--)solve();
  solve();
}

