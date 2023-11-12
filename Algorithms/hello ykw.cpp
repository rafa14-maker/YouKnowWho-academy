#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 1e5+5;
const int M = 1e7+5;

bool vis[M];
int check[M];

vector<ll>pri;
map<ll,ll>mp;
vector<pair<ll,ll> >v;

void sei()
{
    for(int i=2;i<M;i++)
    {
        if(!vis[i])
        {
            pri.push_back(i);
            if(check[i])mp[i]+=check[i];
           // v.push_back(0);
            for(int j=i*2;j<M;j+=i)
            {
                if(check[j])mp[i]+=check[j];
                vis[j] = true;
            }
        }
    }
}

int f(ll k)
{
    int l = 0;
    int r = v.size()-1;
    int ans = 0;

    while(l<=r)
    {
        int mid = (l+r)/2;
        if(v[mid].first<=k)
        {
            ans = max(ans,mid);
           l=mid+1;
        }
        else r = mid-1;
    }

    return ans;
}

int fk(ll k)
{
    int l = 0;
    int r = v.size()-1;
    int ans = r;

    while(l<=r)
    {
        int mid = (l+r)/2;
        if(v[mid].first>=k)
        {
            ans = min(mid,ans);
           r = mid-1;
        }
        else l=mid+1;
    }

    return ans;
}


void solve()
{
  //  cout<<"yes"<<endl;

  int n;
  cin>>n;
  mp.clear();

  for(int i=0;i<n;i++)
  {
      ll idx;
      cin>>idx;
      check[idx]++;
  }

  sei();

   for(auto it = mp.begin();it != mp.end();it++)
   {
       //cout<<it->first<<" " << it->second<<endl;
       v.push_back(make_pair(it->first,it->second));
   }

   for(int i=1;i<v.size();i++)v[i].second += v[i-1].second;

   int q;
   cin>>q;

   while(q--)
   {
       ll l,r;
       cin>>l>>r;

       int a = fk(l);
       int b = f(r);

      if(v[a].first>r||v[b].first<l)
      {
          cout<<0<<endl;
          continue;
      }


      if(a>0) cout << v[b].second - v[a-1].second << endl;
     else cout<<v[b].second<<endl;
     //  cout << sum <<endl;

      // cout<<v[b].second-v[a-1].second<<endl;

   }

  //int arr[n+5];
 // for(int i=0;i<n;i++)cin>>arr[i];

}

int main()
{
    CherryFrog;
  //  sei();
    //for(int i=0;i<12;i++)cout<<pri[i]<<endl;
   // cout << pri.size() <<endl;
   //int q;cin>>q;while(q--)solve();
  solve();
}
