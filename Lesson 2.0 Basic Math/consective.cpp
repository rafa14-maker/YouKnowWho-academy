#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve()
{
  //  cout<<"yes"<<endl;
  int n,q;
  cin>>n>>q;
  string s;
  cin>>s;
  int arr[n+5];
  for(int i=0;i<n;i++)arr[i]=0;
  for(int i=1;i<s.size();i++)
  {
      if(s[i-1] == s[i])arr[i] = 1;
  }
  for(int i=1;i<n;i++)arr[i] += arr[i-1];
  while(q--)
  {
      int l,r;
      cin>>l>>r;
      l--;
      r--;
      if(l != 0)
      {
          if(s[l] == s[l-1])cout<<arr[r] - arr[l-1] -1<<endl;
          else cout<<arr[r] -arr[l-1]<<endl;
      }
      else cout << arr[r]<<endl;
  }
}

int main()
{
    CherryFrog;
   //int q;cin>>q;while(q--)solve();
  solve();
}

