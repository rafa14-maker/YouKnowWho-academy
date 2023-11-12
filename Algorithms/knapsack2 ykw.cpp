#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 105;

ll n,k;
ll v[N];
ll wei[N];
map<pair<ll,ll>,int>mp;

ll f(ll pos, ll weight)
{
  //  cout<<pos<<" "<<weight<<endl;
    if(weight >k)return -1e18+7;
    if(pos == n)return 0;

     pair<ll,ll>pk = {pos,weight};
     if(mp.find(pk) != mp.end())
     {
         return mp[pk];
     }

    ll ans = 0;
    ans = max(ans,f(pos+1,weight));
   ans = max(ans,v[pos] + f(pos+1,weight + wei[pos]));
    mp[pk] = ans;
   // cout<<ans<<endl;
    return ans;
}


void solve()
{
  cin>>n>>k;
  for(int i=0;i<n;i++)
  {
      cin>>wei[i]>>v[i];
  }
  mp.clear();
  cout << f(0,0)<<"\n";
}

int main()
{
    CherryFrog;
  // int q;cin>>q;while(q--)solve();
  solve();
}

