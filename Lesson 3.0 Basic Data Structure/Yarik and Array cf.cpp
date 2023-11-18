#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 2e5+5;
ll arr[N];
int n;

void solve()
{
  //  cout<<"yes"<<endl;

  cin>>n;

  ll mx = -1e12;

  for(int i=0;i<n;i++)cin>>arr[i],max(arr[i],mx);


  ll sum = 0;

  for(int i=0;i<n;i++)
  {
      if(i-1 >= 0 && arr[i]%2 != arr[i-1]%2)
      {
          if(sum + arr[i] < 0)
          {
              sum = arr[i];
          }
          else sum += arr[i];
      }
      else
      {
          sum = arr[i];
      }

      mx = max(mx,sum);
  }

  cout << mx << endl;

}

int main()
{
    CherryFrog;
   int q;cin>>q;while(q--)solve();
 // solve();
}

