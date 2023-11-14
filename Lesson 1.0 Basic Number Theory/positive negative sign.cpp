#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int test;

void solve()
{
  //  cout<<"yes"<<endl;
  ll a,b;
  cin>>a>>b;
  ll r = a/b;
  printf("Case %d: %lld\n",++test,(r/2)*b*b);
}

int main()
{
    CherryFrog;
   int q;cin>>q;while(q--)solve();
 // solve();
}

