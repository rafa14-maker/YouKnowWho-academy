#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve()
{
  //  cout<<"yes"<<endl;

  int n;
  cin>>n;

  int sum = 0 ;

  for(int i=0;i<n;i++)
  {
      int a;
      cin>>a;
      while(a>0)
      {
          int r = a%10;
          a/=10;
          sum += r;
      }
  }

  if(sum %3 ==0)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

}

int main()
{
    CherryFrog;
   int q;cin>>q;while(q--)solve();
 // solve();
}

