#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 105;
vector<int>adj[N];
bool vis[N];
ll cnt[N];
int test;

void cal()
{
    for(int i=0;i<105;i++)
    {
        cnt[i] =0;
        vis[i] = false;
        adj[i].clear();
    }
}

void bfs(int x)
{
    queue<int>q;
    q.push(x);
    cnt[x] = 0;
    vis[x] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i];
            if(!vis[v])
            {
                  vis[v] = true;
                cnt[v] = cnt[u]+1;
                q.push(v);
            }
        }
    }
}

void solve()
{
  //  cout<<"yes"<<endl;

  cal();

  int n;
  cin>>n;

  int m;
  cin>>m;

  for(int i=1;i<=m;i++)
  {
      int a,b;
      cin>>a>>b;
      a++;
      b++;
      adj[a].push_back(b);
      adj[b].push_back(a);
  }

  int s,d;
  cin>>s>>d;

  s++;
  d++;

  bfs(s);

 unordered_map<ll,ll>mp;

  for(int i=1;i<=n;i++)
  {
     mp[i] = cnt[i];
  }

 // for(int i=1;i<=n;i++)cout<<mp[i]<<" ";cout<<endl;

  for(int i=1;i<=n;i++)
  {
      cnt[i] = 0;
      vis[i] = false;
  }

  bfs(d);

  ll cmx = 0;

  for(int i=1;i<=n;i++)
  {
      cmx = max(cmx,mp[i]+cnt[i]);
  }


  // cout<<cnt[s]<<endl;

  cout << "Case "<< ++test << ": ";
  cout << cmx << endl;


}

int main()
{
    CherryFrog;
   int q;cin>>q;while(q--)solve();
 // solve();
}

/*

1
4
5
0 1
0 2
2 3
1 3
0 3
0 2


*/

