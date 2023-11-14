#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int test;

void solve()
{
  //  cout<<"yes"<<endl;
  ll n;
  cin>>n;

  printf("Case %d: ",++test);

  ll a = 1, b = 0;

  while(n%2 == 0){
    n/=2;
    a*=2;
  }

  b = n;

 if(a == 1) printf("Impossible\n");
 else printf("%lld %lld\n",b,a);

}

int main()
{
    CherryFrog;
   int q;cin>>q;while(q--)solve();
 // solve();
}

