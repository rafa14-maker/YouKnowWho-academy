#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll r[500];
ll pa[500];

void uf(ll n)
{
   for(int i=0;i<n;i++)r[i]=0;
    for(int i=0;i<n;i++)pa[i]=0;
    for(int i=0;i<n;i++)pa[i]=i;
}

ll findset(ll i)
{
    if(pa[i]==i)return i;
    else return findset(pa[i]);
}

bool isSameset(ll i,ll j)
{
    return findset(i)==findset(j);
}

void unionset(ll i,ll j)
{
    if(!isSameset(i,j))
    {
        ll x=findset(i);
        ll y=findset(j);
        if(r[x]>r[y])
        {
            pa[y]=x;
        }
        else
        {
            pa[x]=y;
            if(r[x]==r[y])r[y]++;
        }
    }
}

void solve()
{
    vector<pair<ll,pair<ll,ll> > >edge;
    ll n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        w = w % k;
        edge.push_back(make_pair(w,make_pair(u,v)));
    }
    sort(edge.begin(),edge.end());

    uf(500);

    ll ans=0;
    for(int i=0;i<m;i++)
    {
        pair<ll,pair<ll,ll> >f;
        f=edge[i];
        if(!isSameset(f.second.first,f.second.second))
        {
            ans+=f.first;
            ans = ans % k;
            unionset(f.second.first,f.second.second);
        }
    }
    cout<<ans<<endl;
}

int main()
{
    solve();
}

/*

5 7
0 1 4
1 2 2
0 2 4
0 3 6
2 3 8
0 4 6
4 3 9


*/
