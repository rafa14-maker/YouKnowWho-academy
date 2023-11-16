#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 5e5 + 9;
ll a[N];
const ll mx = 1e10+5;

 struct mintree
  {
      ll value;
      ll fre;
  }t[N];

struct ST {
  #define lc (n << 1)
  #define rc ((n << 1) + 1)

  ST() {
   for(int i=0;i<N;i++)
   {
       t[i].value = mx;
       t[i].fre = 0;
   }
  }
   mintree combine(mintree a,mintree b) {
         mintree c;
         if(a.value < b.value)
         {
             c.value = a.value;
             c.fre = a.fre;
         }
         else if(a.value > b.value)
         {
             c.value = b.value;
             c.fre = b.fre;
         }
         else
         {
             c.value = a.value;
             c.fre = a.fre + b.fre;
         }
         return c;
  }

  inline void pull(int n) {
   // t[n] = t[lc] + t[rc];

   if(t[lc].value < t[rc].value)
   {
        t[n].value = t[lc].value;
       t[n].fre =  t[lc].fre;
   }
   else if(t[lc].value > t[rc].value)
   {
       t[n].value = t[rc].value;
       t[n].fre =  t[rc].fre;
   }
   else
   {
       t[n].value = t[lc].value;
       t[n].fre = t[lc].fre + t[rc].fre;
   }
}

  void build(int n, int b, int e) {
    if (b == e) {
        t[n].value = a[b];
        t[n].fre = 1;
      return;
    }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
  }
  void upd(int n, int b, int e, int idx, long long v) {
    if (idx < b || e < idx) return;
    if (b == idx && e == idx) {
      t[n].value = v;
      t[n].fre = 1;
      return;
    }
    int mid = (b + e) >> 1;
    upd(lc, b, mid, idx, v);
    upd(rc, mid + 1, e, idx, v);
    pull(n);
  }
  mintree query(int n, int b, int e, int i, int j) {
    if (i > e || b > j) {
        mintree k;
        k.value = mx;
        k.fre = 0;
        return k;
    }
    if (i <= b && e <= j) return t[n];
    int mid = (b + e) >> 1;
    return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
  }
}tree;

void solve()
{
  //  cout<<"yes"<<endl;

  int n,q;
  cin>>n>>q;
  for(int i=1;i<=n;i++)cin>>a[i];
  tree.build(1,1,n);
  while(q--)
  {
      int idx;
      cin>>idx;
      if(idx == 1)
      {
          int ddx,v;
          cin>>ddx>>v;
          ddx++;
          tree.upd(1,1,n,ddx,v);
      }
      else
      {
          int l,r;
          cin>>l>>r;

          mintree tk;
          tk = tree.query(1,1,n,l+1,r);
          cout << tk.value <<" "<<tk.fre<<endl;
      }
  }
}

int main()
{
    CherryFrog;
   //int q;cin>>q;while(q--)solve();
 solve();
}
