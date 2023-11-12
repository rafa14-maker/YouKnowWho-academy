#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve()
{
  //  cout<<"yes"<<endl;

  ll n,k;
  cin>>n>>k;

  vector<ll>v;

  for(ll i=1;i<=sqrt(n);i++)
  {
      if(n%i == 0){
        v.push_back(i);
        if( i != n/i){
            v.push_back(n/i);
        }
      }
  }

  sort(v.begin(),v.end());

  if(v.size() < k)cout<<"-1"<<endl;
  else cout<<v[k-1] <<endl;

}

int main()
{
    CherryFrog;
   //int q;cin>>q;while(q--)solve();
  solve();
}

