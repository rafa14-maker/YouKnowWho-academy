#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 1e6+5;
bool vis[N];

vector<ll>pri;
ll mom[N];

void seive()
{
    for(int i=2;i<N;i++)
    {
        if(!vis[i])
        {
           // pri.push_back(i);
           mom[i] = i;
            for(int j=i*2;j<N;j+=i)
            {
                vis[j] = true;
                mom[j] = i;
            }
        }
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

void solve()
{
  //  cout<<"yes"<<endl;

    int n;
    //cin>>n;
    scanf("%d",&n);

    ll lpf =  1e8+7,gpf = 0,w = 0,tot = 0;
    ll nod = 1,sod = 1;

    ll ddx = n;

    while(ddx>1)
    {
        ll x = mom[ddx];
        lpf = min(x,lpf);
        gpf = max(x,gpf);
        w++;

        ll cnt = 0;

        while(ddx%x == 0)
        {
            ddx /=x;
            cnt++;
        }

        tot += cnt;

        nod *= (cnt+1);

        ll pk = pow(x,cnt+1)-1;

        sod *= (pk / (x-1));

    }


  /* for(int i=0;pri[i]<=n;i++)
    {
        if(n%pri[i] == 0)
        {
            lpf = min(lpf,pri[i]);
            gpf = max(gpf,pri[i]);
            w++;

            ll cnt = 0;

            while(n%pri[i]==0)
            {
                n/=pri[i];
                cnt++;
            }

            tot += cnt;

            nod *= (cnt+1);

            ll ck = bigmod(pri[i],cnt+1)-1;
            ck /= (pri[i]-1);

           if(ck>0) sod *= ck;

        }
    }*/

    printf("%lld %lld %lld %lld %lld %lld\n",lpf,gpf,w,tot,nod,sod);

}

int main()
{
    CherryFrog;
    seive();
  int q;scanf("%d",&q);while(q--)solve();




 // solve();
}
