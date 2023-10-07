#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 1e5+5;
bool vis[N];
int pi[N];
vector<int>adj[N];
vector<int>v;

void bfs(int x)
{
    vis[x]  = true;
    queue<int>q;
    q.push(x);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v  = adj[u][i];
            if(!vis[v])
            {
                vis[v] = true;
                pi[v] = u;
                q.push(v);
            }
        }
    }
}

void fi(int u)
{
    v.push_back(u);
    if(pi[u] == u)return ;
    else fi(pi[u]);
}

void solve()
{
  //  cout<<"yes"<<endl;

  for(int i=1;i<N;i++)pi[i] = i;

  int n,k;
  cin>>n>>k;

  for(int i=1;i<=k;i++)
  {
      int a,b;
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
  }

  bfs(1);

  fi(n);

  if(pi[n] == n)
  {
      cout << "IMPOSSIBLE" << endl;
      return ;
  }

  cout << v.size() << endl;

  for(int i=v.size()-1;i>=0;i--)
  {
      cout << v[i]<<" ";
  }
  cout << endl;

}

int main()
{
    CherryFrog;
   //int q;cin>>q;while(q--)solve();
  solve();
}

