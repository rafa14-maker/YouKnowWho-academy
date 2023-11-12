#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

bool cal(int n)
{
    while(n%3==0)
    {
        n/=3;
    }
    while(n%2==0)
    {
        n/=2;
    }
    while(n%5==0)
    {
        n/=5;
    }
    if(n>1)return false;
}

void solve()
{
  //  cout<<"yes"<<endl;

   vector<ll>v;

   for(int i=1;i<=1e7+5;i++)
   {
      if(cal(i))v.push_back(i);
   }

   //cout << v[1500-1] << endl;

   cout << v.size() << endl;

  // printf("The 1500'th ugly number is %d.\n",v[1500-1]);

}

int main()
{
    CherryFrog;
   //int q;cin>>q;while(q--)solve();
  solve();
}

