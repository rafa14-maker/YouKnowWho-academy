#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 1e7+5;

bool vis[N];

vector<ll>pri;
map<int,int>mp;

void sei()
{
    for(int i=2;i<N;i++)
    {
        if(!vis[i])
        {
            pri.push_back(i);

            for(int j=i*2;j<N;j+=i)
            {
                vis[j] = true;
            }
        }
    }
}

int f(ll k)
{
    int l = 0;
    int r = pri.size();
    int ans = r-1;

    while(l<=r)
    {
        int mid = (l+r)/2;
        if(pri[mid]>=k)
        {
            ans = mid;
            r = mid-1;
        }
        else l =mid+1;
    }

    return ans;
}


void solve()
{
  //  cout<<"yes"<<endl;

  int n;
  cin>>n;

  for(int i=0;i<n;i++)
  {
      int idx;
      cin>>idx;

      for(int j=0;pri[j]<=idx;j++)
      {
          while(idx % pri[j] == 0)
          {
              mp[pri[j]]++;
              idx /= pri[j];
          }
      }

  }

   /*vector<ll>v;

   for(int i=0;i<pri.size();i++)
   {
       v.push_back(mp[pri[i]]);
   }

   for(int i=1;i<v.size();i++)
   {
       v[i]+=v[i-1];
   }

   int q;
   cin>>q;

   while(q--)
   {
       int l,r;
       cin>>l>>r;

       int a  = f(l);
       int b = f(r);

    //   if(a!=0)cout<<v[b]-v[a-1]<<endl;
     //  else cout<<v[b]<<endl;
   }

  //int arr[n+5];
 // for(int i=0;i<n;i++)cin>>arr[i];*/

}

int main()
{
    CherryFrog;
  //  sei();
   // cout << pri.size() <<endl;
   //int q;cin>>q;while(q--)solve();
  solve();
}

