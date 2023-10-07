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

  ll n,m,l,r;

  cin>>n>>m>>l>>r;

  ll g = GCD(n,m);

  ll lc = n*m;

  lc /= g;

  if(l%lc!=0) l = lc - (l%lc)+l;

   if(l>r)cout<<0<<endl;
   else
   {
       cout << (r-l+1)/lc +1<<endl;
   }



}

int main()
{
    CherryFrog;
   //int q;cin>>q;while(q--)solve();
  solve();
}

