#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 20005, mod = 1e9;

ll a[N];
struct ST {
  ll t[4 * N];
  ST() {
    memset(t, 0, sizeof t);
  }
  void build(int n, int b, int e) {
    if (b == e) {
      t[n] = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] =(t[l]+ t[r]);
  }
  void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      t[n] = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    t[n] = (t[l]+ t[r]);
  }
  ll query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return t[n];
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    return (query(l, b, mid, i, j)+ query(r, mid + 1, e, i, j));
  }
}t;


void solve()
{
  //  cout<<"yes"<<endl;
  int n,k;
  cin>>n>>k;

  for(int i=1;i<=n;i++)cin>>a[i];

  vector<ll>v;

  for(int i=1;i<=n;i++)v.push_back(1);

  t.build(1,1,n);

  for(int c=0;c<k-1;c++)
  {
      for(int j=0;j<v.size();j++)t.upd(1,1,n,a[j+1],v[j]);
      v.clear();
      for(int i=1;i<=n;i++)
      {
          ll p = t.query(1,1,n,a[i]+1,n);
         cout << p << " ";
          v.push_back(p);
      }
      cout << endl;
  }

   ll sum = 0;

   for(int i=0;i<v.size();i++)
   {
       sum += v[i];
       sum = sum % mod;
   }

  cout << sum <<"\n";
}

int main()
{
    CherryFrog;
   //int q;cin>>q;while(q--)solve();
  solve();
}

/*

5 2
5 4 3 2 1

*/

