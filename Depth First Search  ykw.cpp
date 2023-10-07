#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 105;
vector<int>adj[N];
bool vis[N];
int st[N];
int ft[N];
int cnt;

void dfs(int u)
{
    vis[u] = true;
    st[u] = cnt++;
    for(int i=0;i<adj[u].size();i++)
    {
        int v = adj[u][i];
        if(!vis[v])
        {
            dfs(v);
        }
    }
    ft[u] = cnt++;
}

void solve()
{
  //  cout<<"yes"<<endl;

  int n;
  cin>>n;

  for(int i=1;i<=n;i++)
  {
      int id;
      cin>>id;

      int k;
      cin>>k;

      for(int j=1;j<=k;j++)
      {
          int v;
          cin>>v;
          adj[id].push_back(v);
         //  adj[v].push_back(id);
      }
  }

 // for(int i=1;i<=n;i++)sort(adj[i].begin(),adj[i].end());

  cnt  = 1;

 for(int i=1;i<=n;i++)
 {
     if(!vis[i])dfs(i);
 }

  for(int i=1;i<=n;i++)
  {
      cout << i <<" "<< st[i]<<" "<<ft[i]<<endl;
  }

}

int main()
{
    CherryFrog;
   //int q;cin>>q;while(q--)solve();
  solve();
}

