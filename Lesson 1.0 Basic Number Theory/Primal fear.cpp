#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 1e6+5;
vector<int>v;
bool prime[N];

bool isPrime(string s)
{
    int x = 0;
    int idx = 1;
    for(int i=0;i<s.size();i++)
    {
        int r = (int)(s[i]-'0') ;
        if(r == 0)return false;
        x += (r*idx);
        idx *= 10;
    }
    return prime[x];
}

bool omit(int x){

  string s;

  while(x > 0){

    int r = x % 10;
    if(r == 0)return false;
    x /= 10;
    s +=(int)'0'+r;
  }

  string frr;

  for(int i=0;i<s.size();i++)
  {
      frr += s[i];
      if(!isPrime(frr))return false;
  }

  return true;
}

void f()
{
    for(int i=2;i<N;i++)prime[i] = true;

    for(int i=2;i<N;i++)
    {
        if(prime[i])
        {
            for(int j=i*2;j<N;j+=i)
            {
                prime[j] = false;
            }
            if(omit(i))v.push_back(i);
        }
    }
}

void solve()
{
  //  cout<<"yes"<<endl;

  int n;
  cin>>n;

  for(int i=0;i<v.size();i++)
  {
      if(v[i] > n)
      {
          cout << i << endl;
          return ;
      }
  }

  cout << v.size() << endl;


 /* int l = 0 , r = v.size()-1;
  int idx = 0;

  while(l<=r)
  {
      int mid = (l+r)/2;
      if(v[mid] <= n){
        idx = mid;
        l = mid+1;
      }
      else{
        r = mid-1;
      }
  }*/

 // cout << idx +1 << endl;

}

int main()
{
    CherryFrog;
    f();
   int q;cin>>q;while(q--)solve();
 // solve();
}

