#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 1e6+5;
const int M = 1e3+5;

vector<int>prime;
bool pri[N];
int d[M];
int ddx[N+5];
bool ans[N];
vector<int>v;
int mx ;


void mod_s()
{
    for(int i=0;i<N;i++)ddx[i]=1;
    for(int i=2;i<N;i++)
    {
        if(!pri[i])
        {
            prime.push_back(i);
            for(int j=i*2;j<N;j+=i)
            {
                pri[j] = true;
                int idx = 0;
                int pk = j;
                while(pk%i==0)
                {
                    pk/=i;
                    idx++;
                }
                ddx[j] *= (idx+1);
            }
        }
    }

}

void solve()
{
       int n;
       cin>>n;

       for(int i=0;i<N;i++)
       {
           if(ddx[i]==n)cout<<i<<endl;
       }
}

int main()
{
    CherryFrog;
    mod_s();
 //  int q;cin>>q;while(q--)solve();
  solve();
}

