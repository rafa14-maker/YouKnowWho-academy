#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 1e6+5;
int fre[N];

void f(int x)
{
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            fre[x]++;
            if(x != x/i && (x%(x/i)==0))fre[x/i]++;
        }
    }
}

void solve()
{
  //  cout<<"yes"<<endl;
  int n;
  cin>>n;

  for(int i=0;i<n;i++)
  {
      int x;
      cin>>x;
      f(x);
  }

  for(int i=1;i<=1e6;i++)cout<<fre[i]<<"\n";

}

int main()
{
    CherryFrog;
   //int q;cin>>q;while(q--)solve();
  solve();
}

