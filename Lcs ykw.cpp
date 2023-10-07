#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 3005;

int dp[N][N];
string arr,frr;
string fk;

int f(int i,int j)
{
    if(i == arr.size()||j == frr.size())return 0;

    if(dp[i][j] != -1)return dp[i][j];

    int ans = 0;
    if(arr[i] == frr[j])
    {
        ans = max(ans,1+f(i+1,j+1));
    }
    ans = max(ans,f(i+1,j));
    ans = max(ans,f(i,j+1));
    return dp[i][j] = ans;
}

void path(int i,int j)
{
   if(i >= arr.size() || j>= frr.size())return ;
   if(arr[i] == frr[j])
   {
       fk += arr[i];
       path(i+1,j+1);
       return ;
   }
   int x = f(i+1,j);
   int y = f(i,j+1);
   if(x>=y)
   {
       path(i+1,j);
   }
   else path(i,j+1);
}

void solve()
{
  //  cout<<"yes"<<endl;
  cin>>arr>>frr;
  memset(dp,-1,sizeof dp);
  int ans = f(0,0);
  path(0,0);
  cout<<fk<<"\n";
}

int main()
{
    CherryFrog;
   //int q;cin>>q;while(q--)solve();
 solve();
}

