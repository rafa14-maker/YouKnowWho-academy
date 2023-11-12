#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve()
{
  //  cout<<"yes"<<endl;

  ll n;
  cin>>n;

  ll arr[n+5][5];

  for(int i=1;i<=n;i++)
  {
      cin>>arr[i][1]>>arr[i][2]>>arr[i][3];
  }

  for(int i=2;i<=n;i++)
  {
      arr[i][1] += max(arr[i-1][2],arr[i-1][3]);
      arr[i][2] += max(arr[i-1][1],arr[i-1][3]);
      arr[i][3] += max(arr[i-1][2],arr[i-1][1]);
  }

  cout << max(arr[n][1],max(arr[n][2],arr[n][3]))<<"\n";
}

int main()
{
    CherryFrog;
   //int q;cin>>q;while(q--)solve();
  solve();
}

