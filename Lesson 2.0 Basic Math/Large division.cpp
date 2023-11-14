#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int test;

void solve()
{
  //  cout<<"yes"<<endl;

  string s;
  cin>>s;

  string frr = s;
  reverse(frr.begin(),frr.end());

  ll a;
  cin>>a;
  a = abs(a);

  ll sum = 0;
  int i = 0;
  if(s[0]=='-')i++;

  for(;i<s.size();i++)
  {
      ll r = (ll)s[i]-'0';
        sum *= 10;
        sum += r;
        sum %= a;
  }


  if(sum == 0)printf("Case %d: divisible\n",++test);
  else printf("Case %d: not divisible\n",++test);


}

int main()
{
    CherryFrog;
   int q;cin>>q;while(q--)solve();
 // solve();
}

