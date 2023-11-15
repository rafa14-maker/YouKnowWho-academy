#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve()
{
  //  cout<<"yes"<<endl;
  int n,k;
  cin>>n>>k;
  int sum = 0;
  for(int i=0;i<n;i++)
  {
      int a;
      cin>>a;
      if(a<=k)sum +=a;
  }
  cout << sum << endl;
}

int main()
{
    CherryFrog;
   //int q;cin>>q;while(q--)solve();
  solve();
}

