#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

 string Intostr(int x){stringstream ss; ss << x; string str = ss.str(); return str;}
vector<string> Linetostr(string str){string s; vector <string> v ;istringstream is(str); while(is >> s)v.push_back(s);return v;}
int Strtoint(string str){stringstream ss(str);int x = 0;ss >> x ;return x ;}
#define FasterIO     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N = 5e5 + 9;
ll a[N];
struct ST {
  #define lc (n << 1)
  #define rc ((n << 1) + 1)
  ll inf = 1e18+5;
  long long t[4 * N], lazy[4 * N];
  ST() {
    memset(t, 0, sizeof t);
    memset(lazy, 0, sizeof lazy);
  }
  inline void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    t[n] += lazy[n];
    if (b != e) {
      lazy[lc] = lazy[lc] + lazy[n];
      lazy[rc] = lazy[rc] + lazy[n];
    }
    lazy[n] = 0;
  }
  inline long long combine(long long a,long long b) {
    return min(a , b);
  }
  inline void pull(int n) {
    t[n] = min(t[lc] , t[rc]);
  }
  void build(int n, int b, int e) {
    lazy[n] = 0;
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
    push(n, b, e);
    if (j < b || e < i) return;
    if (i <= b && e <= j) {
      lazy[n] += v;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1;
    upd(lc, b, mid, i, j, v);
    upd(rc, mid + 1, e, i, j, v);
    pull(n);
  }
  long long query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (i > e || b > j) return LLONG_MAX;
    if (i <= b && e <= j) return t[n];
    int mid = (b + e) >> 1;
    return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
  }
}t;

void solve()
{
  //  cout<<"yes"<<endl;
  int n;
  cin>>n;

  for(int i=1;i<=n;i++)cin>>a[i];
  t.build(1,1,n);

  int q;
  cin>>q;
  q++;

  while(q--)
  {
       string input;
		vector<int>v;
		getline(cin, input);
		istringstream is(input);
		int num;
		while(is >> num) v.push_back(num);
        if(v.size() == 2)
        {
            int l = v[0];
            int r = v[1];
            l++,r++;
            if(l>r)
            {
                ll a = t.query(1,1,n,l,n);
                ll b = t.query(1,1,n,1,r);
                cout << min(a,b)<<endl;
            }
            else
            {
                cout << t.query(1,1,n,l,r)<<endl;
            }
        }
        else if(v.size() == 3)
        {
           int l = v[0];
            int r = v[1];
            l++,r++;
            int dx = v[2];
            if(l>r)
            {
               t.upd(1,1,n,1,r,dx);
               t.upd(1,1,n,l,n,dx);
            }
            else
            {
                t.upd(1,1,n,l,r,dx);
            }
        }
  }
}

int main()
{
    CherryFrog;
   //int q;cin>>q;while(q--)solve();
  solve();
}

