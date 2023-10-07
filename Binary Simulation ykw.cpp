#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 5e5 + 9;
int a[N];
int test;
struct ST {
  #define lc (n << 1)
  #define rc ((n << 1) + 1)
  long long t[4 * N], lazy[4 * N];
  ST() {
    memset(t, 0, sizeof t);
    memset(lazy, 0, sizeof lazy);
  }
  inline void push(int n, int b, int e) { // change this
    if (lazy[n] == 0) return;
   // t[n] = t[n] + lazy[n] * (e - b + 1);

   if(lazy[n] % 2 ==1)t[n] ^= 1;

    if (b != e) {
     lazy[lc] = lazy[lc] + lazy[n];
      lazy[rc] = lazy[rc] + lazy[n];
    }
    lazy[n] = 0;
  }
  inline long long combine(long long a,long long b) { // change this
    return max(a , b);
  }
  inline void pull(int n) { // change this
    t[n] = max(t[lc],t[rc]);
  }
  void build(int n, int b, int e) {
    lazy[n] = 0; // change this
    if (b == e) {
      t[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
  }
  void upd(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (j < b || e < i) return;
    if (i <= b && e <= j) {
      lazy[n]++; //set lazy
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1;
    upd(lc, b, mid, i, j);
    upd(rc, mid + 1, e, i, j);
    pull(n);
  }
  long long query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (i > e || b > j) return 0; //return null
    if (i <= b && e <= j)
    {
       if(lazy[n]%2==1)return t[n]^1;
       else return t[n];
    }
    int mid = (b + e) >> 1;
    return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
  }
}t;

void solve()
{
  //  cout<<"yes"<<endl;

  string s;
  cin>>s;

  int n=s.size();

  for(int i=0;i<s.size();i++)
  {
      if(s[i]=='0')a[i+1] = 0;
      else a[i+1] = 1;
  }

  t.build(1,1,n);

  int q;
  cin>>q;

  cout << "Case "<<++test<<":"<<endl;

  while(q--)
  {
      char c;
      cin>>c;
      if(c == 'I')
      {
          int l,r;
          cin>>l>>r;
          t.upd(1,1,n,l,r);
      }
      else
      {
          int dx;
          cin>>dx;
          cout << t.query(1,1,n,dx,dx)<<endl;
      }
  }
}

int main()
{
    CherryFrog;
   int q;cin>>q;while(q--)solve();
 // solve();
}

