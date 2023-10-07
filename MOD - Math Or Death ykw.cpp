#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve()
{
  //  cout<<"yes"<<endl;

  ll n,k;
  cin>>n>>k;

  if(n==k)
  {
      cout<<"infinity"<<endl;
      return ;
  }

    if(n<k)
    {
        cout<<0<<endl;
        return ;
    }

  ll s = n-k;
  ll cnt = 0;

  for(int i=1;i*i<=s;i++)
  {
      if(s%i==0)
      {
           if(n%i==k)cnt++;
           ll ddx = s/i;
           if(ddx!=i&&n%ddx==k)cnt++;
      }
  }
//if(k==0)cnt++;
cout << cnt<<endl;

}

int main()
{
    CherryFrog;
   //int q;cin>>q;while(q--)solve();
  solve();
}

