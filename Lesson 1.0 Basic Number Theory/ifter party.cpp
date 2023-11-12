#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int test;

void solve()
{
  //  cout<<"yes"<<endl;

  ll n,k;
  cin>>n>>k;

  ll r = n-k;

  vector<ll>v;

  for(int i=1;i<=sqrt(r);i++)
  {
      if(r % i == 0){
        v.push_back(i);
        if(i != r/i){
            v.push_back(r/i);
        }
      }
  }

 // cout << v.size() << endl;
  vector<ll>vk;

  for(int i=0;i<v.size();i++)
  {
      if(v[i] > k)vk.push_back(v[i]);
  }

  printf("Case %d: ",++test);

 sort(vk.begin(),vk.end());

 // for(int i=0;i<vk.size();i++)printf("%lld\n",vk[i]);

  if(vk.size() != 0){
    for(int i=0;i<vk.size();i++)printf("%lld ",vk[i]);
    printf("\n");
  }
  else {
      printf("impossible\n");
  }

}

int main()
{
    CherryFrog;
   int q;cin>>q;while(q--)solve();
 // solve();
}

