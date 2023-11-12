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

  if(k>n)
  {
      printf("Case %d: impossible\n",++test);
      return ;
  }

  vector<ll>v;

  ll p = n-k;

  for(int i=1;i<=sqrt(p);i++)
  {
      if(p%i==0)
      {
          v.push_back(i);
          if(p/i != i&& p%(p/i)==0)
          {
              v.push_back(p/i);
          }
      }
  }

  vector<ll>ddx;

  for(int i=0;i<v.size();i++)
  {
      if(n%v[i]==k)ddx.push_back(v[i]);
  }

  sort(ddx.begin(),ddx.end());

  printf("Case %d: ",++test);

  if(ddx.size()==0)
  {
      printf("impossible\n");
      return ;
  }

  for(int i=0;i<ddx.size();i++)printf("%lld ",ddx[i]);
  printf("\n");



}

int main()
{
    CherryFrog;
   int q;cin>>q;while(q--)solve();
 // solve();
}

