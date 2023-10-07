#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve()
{
  //  cout<<"yes"<<endl;

  int n;
  cin>>n;

  int arr[n+5][n+5];

  for(int i=1;i<=n;i++)
  {
      for(int j=1;j<=n;j++)arr[i][j] =0;
  }

  for(int i=1;i<=n;i++)
  {
      int id;
      cin>>id;
      int d;
      cin>>d;
      for(int j=1;j<=d;j++)
      {
          int k;
          cin>>k;
          arr[id][k]=1;
      }
  }

  for(int i=1;i<=n;i++)
  {
      for(int j=1;j<=n;j++)
      {
          if(j != n)cout << arr[i][j]<<" ";
          else cout<<arr[i][j]<<endl;
      }
  }

}

int main()
{
    CherryFrog;
   //int q;cin>>q;while(q--)solve();
  solve();
}

