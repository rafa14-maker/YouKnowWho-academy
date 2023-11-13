#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 1e6+5;

ll lpf[N],gpf[N],w[N],pi[N],Nod[N],Sod[N],idx[N];
bool prime[N];

void f(){
     for(int i=1;i<N;i++)
     {
         lpf[i] = N;
         gpf[i] = 1;
         w[i] = 0;
         pi[i] = 0;
         Nod[i] = 1;
         Sod[i] = 1;
         prime[i] = true;
         idx[i] = i;
     }
}

long long  bigmod(long long f,long long b)
{
    if(b==0)
    {
        return 1;
    }
    long long x=bigmod(f,b/2);
    x=(x*x);
    if(b%2==1)x=(x*f);

    return x;
}

void sei()
{
    for(ll i=2;i<N;i++)
    {
        if(prime[i])
        {
            for(ll j=i;j<N;j+=i)
            {
                prime[j] = false;
                lpf[j] = min(lpf[j],i);
                gpf[j] = max(gpf[j],i);
                w[j]++;

                ll fre = 0;

                while(idx[j] % i == 0)
                {
                    idx[j] /= i;
                    fre ++;
                }

               pi[j] += fre;

                Nod[j] *= (fre+1);

                ll kc = bigmod(i,fre+1) -1;
                kc = kc / (i-1);

                Sod[j] *= kc;
            }
        }
    }
}


void solve()
{
  //  cout<<"yes"<<endl;

  ll n;
  cin>>n;

  printf("%lld %lld %lld %lld %lld %lld\n", lpf[n],gpf[n],w[n],pi[n],Nod[n],Sod[n]);

}

int main()
{
    CherryFrog;
    f();
    sei();

   int q;cin>>q;while(q--)solve();
 // solve();
}

