#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 6e5 + 9;
int a[N];

int n,k;
int test;
map<int,int>mp;
map<int,int>ans;
vector<pair<int,int> >v;
vector<pair<int,int> >segs;
vector<int>pk;
int arr[N+5];


bool cmp(pair<int,int>a,pair<int,int>b)
{
    if(a.first < b.first)return true;
    if(a.first == b.first && a.second < b.second)return true;
    return false;
}

struct ST {
  #define lc (n << 1)
  #define rc ((n << 1) + 1)
  long long t[4 * N];
  ST() {
    memset(t, 0, sizeof t);
  }

  inline long long combine(long long a,long long b) {
    return a + b;
  }
  inline void pull(int n) {
    t[n] = t[lc] + t[rc];
  }
  void build(int n, int b, int e) {
    if (b == e) {
      t[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
  }
  void upd(int n, int b, int e, int i, int j, long long v) {
    if (j < b || e < i) return;
    if (i <= b && e <= j) {
      t[n] += v;
      return;
    }
    int mid = (b + e) >> 1;
    upd(lc, b, mid, i, j, v);
    upd(rc, mid + 1, e, i, j, v);
    pull(n);
  }
  long long query(int n, int b, int e, int i, int j) {
    if (i > e || b > j) return 0;
    if (i <= b && e <= j) return t[n];
    int mid = (b + e) >> 1;
    return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
  }
}t;

void solve()
{
  //  cout<<"yes"<<endl;

  for(int i=0;i<N;i++)a[i] = 0;
  segs.clear();
  mp.clear();
  ans.clear();
  pk.clear();

  cin>>n>>k;

  for(int i=0;i<n;i++)
  {
      int a,b;
      cin>>a>>b;
      pk.push_back(a);
      pk.push_back(b+1);
      segs.push_back(make_pair(a,1));
      segs.push_back(make_pair(b+1,-1));
  }

  for(int i=0;i<k;i++)cin>>arr[i],pk.push_back(arr[i]),segs.push_back(make_pair(arr[i],2));

  sort(pk.begin(),pk.end());
  sort(segs.begin(),segs.end(),cmp);


  for(int i=0;i<pk.size();i++)
  {
      mp[pk[i]] = i+1;
  }

  int nk = segs.size()+5;

  t.build(1,1,nk);

  printf("Case %d:\n",++test);

  for(int i=0;i<segs.size();i++)
  {
      int idx = segs[i].first;
      int ddx = segs[i].second;
      int id = mp[idx];
      if(ddx == 2)
      {
          ans[id] = t.query(1,1,nk,1,nk);
      }
      else
      {
         t.upd(1,1,nk,id,id,ddx);
      }
  }
 //  cout << mp[0]<<endl;
  for(int i=0;i<k;i++)
  {
      int id = mp[arr[i]];
    //  cout << id<<endl;
      printf("%d\n",ans[id]);
  }

}

int main()
{
    CherryFrog;
   int q;cin>>q;while(q--)solve();
 // solve();
}
/*

1
1 1
0 10
0


*/
