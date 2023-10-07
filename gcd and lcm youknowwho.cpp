#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll GCD(ll a, ll b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a < b) swap(a, b);
  return GCD(a % b, b);
}

void solve()
{
  //  cout<<"yes"<<endl;

  ll a,b;
  cin>>a>>b;

   ll g = GCD(a,b);
   ll lc = a*b ;
   lc/=g;

   cout << g <<" "<<lc<<endl;



}

int main()
{
    CherryFrog;
   int q;cin>>q;while(q--)solve();
 // solve();
}

