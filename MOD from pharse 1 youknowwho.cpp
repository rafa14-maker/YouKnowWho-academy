#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

long long binmul(long long a, long long b, long long m) {
    long long res = 0LL;
    a = a % m;
    while (b > 0) {
        if (b & 1) res = (res + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return res;
}

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1LL;
    while (b > 0) {
        if (b & 1) res = binmul(res , a, m);
        a = binmul(a, a, m);
        b >>= 1;
    }
    return res;
}

void solve()
{
  //  cout<<"yes"<<endl;

  ll a,b,p;
  cin>>a>>b>>p;

  ll ak = binpow(a,b,p);

  ll bk = binmul(a,b,p);

  ll ck = binmul(a,binpow(b,p-2,p),p);

  cout <<ak<<endl;
  cout<< bk<<endl;
  cout<<ck<<endl;

}

int main()
{
    CherryFrog;
   //int q;cin>>q;while(q--)solve();
 solve();
}

