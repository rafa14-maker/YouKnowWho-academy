#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

bool vis[105];
vector<int>adj[105];
int cnt[105];
int ti;

void bfs(int x)
{
    queue<int>q;
    q.push(x);
    vis[x] = true;
    cnt[x] = 0;

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
               q.push(v);
           }
            cnt[v] = min(cnt[v],cnt[u]+1);
       }
    }

}

void solve()
{
  //  cout<<"yes"<<endl;

  for(int i=1;i<=100;i++)cnt[i] = 1e5+5;

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
          int a;
          cin>>a;
        //  adj[a].push_back(id);
          adj[id].push_back(a);
      }
  }

  bfs(1);

  for(int i=1;i<=n;i++)
  {
      cout << i<<" ";
      if(cnt[i] == 1e5+5)cout << -1 <<endl;
      else cout << cnt[i]<<endl;
  }

}

int main()
{
    CherryFrog;
   //int q;cin>>q;while(q--)solve();
  solve();
}

