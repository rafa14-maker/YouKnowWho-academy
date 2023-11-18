#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve()
{
  //  cout<<"yes"<<endl;
  int n;
  cin>>n;

  ll mx = 0,mn = 1e9+5;

  for(int i=0;i<n;i++)
  {
      ll a;
      cin>>a;
      mx = max(a,mx);
      mn = min(a,mn);
  }

  cout << mx - mn << endl;

}

int main()
{
    CherryFrog;
   int q;cin>>q;while(q--)solve();
 // solve();
}

