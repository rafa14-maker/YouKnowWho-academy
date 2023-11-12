#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 50005;
const ll mod = 1e9+7;

int prime[N];
vector<int>pri;

void seive()
{
    for(int i=2;i<N;i++)
    {
        if(prime[i]==0)
        {
            pri.push_back(i);
            for(int j=i*2;j<N;j+=i)
            {
                prime[j] = 1;
            }
        }
    }
}

void solve()
{
  //  cout<<"yes"<<endl;
   int n;
   cin>>n;

   ll sum =1;

   for(int i=0;pri[i]<=n&&i<pri.size();i++)
   {
       ll idx = 0;
       ll pk = pri[i];

       while(pk<=n)
       {
           idx += n/pk;
           pk *= pri[i];
       }
  //cout<<idx<<endl;
       sum *= (idx+1);
       sum = sum %mod;
   }

   cout << sum <<endl;


}

int main()
{
    CherryFrog;
    seive();
   // for(int i=0;i<10;i++)cout<<pri[i]<<" ";cout<<endl;
   int q;cin>>q;while(q--)solve();
 // solve();
}

