#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 1e6+5;
//ll a[N];

struct ST {
  ll t[4 * N+5];
  static const ll inf = 1e12;
  ST() {
    for(int i=0;i<4*N+5;i++)t[i] = 0;
  }
  void build(int n, int b, int e) {
    if (b == e) {
      t[n] = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    build(l, b, mid);
    build(r, mid + 1, e);
   // t[n] = t[r]+t[l];
   t[n] = (t[r]+t[l]);
  }
  void upd(int n, int b, int e, int i, ll x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      t[n] +=  x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
   // t[n] = t[l]+t[r];
    t[n] = (t[r]+t[l]);
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

 ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int q; cin >> q;
  vector<int> ans(q + 1);
  vector<pair<int, int>> Q[n + 1];
  for (int i = 1; i <= q; i++) {
    int l, r; cin >> l >> r;
    Q[r].push_back({l, i});
  }
  // build a segment tree where every value is 0

  t.build(1,1,N-5);

  map<int, int> last_id;
  for (int i = 1; i <= n; i++) {
    t.upd(1,1,N-5,i, 1); // add 1 to the ith index
    if (last_id.find(a[i]) != last_id.end()) {
      t.upd(1,1,N-5,last_id[a[i]], -1); // add -1 to the last index having value a[i]
    }
    last_id[a[i]] = i;
    for (auto x: Q[i]) {
      int l = x.first, id = x.second;
      ans[id] = t.query(1,1,N-5,l, i); // sum of l to the ith index
    }
  }
  for (int i = 1; i <= q; i++) {
    cout << ans[i] << '\n';
  }


}

int main()
{
    CherryFrog;
 //  int q;cin>>q;while(q--)solve();
  solve();
}

