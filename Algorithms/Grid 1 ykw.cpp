#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 1005 , mod = 1e9+7;
ll dp[N][N];
char arr[N][N];
int n,m;

ll f(int i,int j)
{
    if(i == n-1 && j == m-1)return 1;
    if(i >= n || j >= m)return 0;
    if(arr[i][j] != '.')return 0;
    if(dp[i][j] != -1)return dp[i][j];
    ll ans = 0;
    ans += f(i+1,j);
    ans = ans % mod;
    ans += f(i,j+1);
    ans = ans % mod;
    return dp[i][j] = ans;
}

void solve()
{
  //  cout<<"yes"<<endl;
  cin>>n>>m;

  for(int i=0;i<n;i++)
  {
      for(int j=0;j<m;j++)cin>>arr[i][j];
  }
  memset(dp,-1,sizeof dp);
  cout << f(0,0) << "\n";
}

int main()
{
    CherryFrog;
   //int q;cin>>q;while(q--)solve();
  solve();
}

