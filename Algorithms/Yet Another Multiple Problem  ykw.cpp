#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll cal(string s,ll m)
{
    ll ans = 0;
    for(int i=0;i<s.size();i++)
    {
        ans = ((ans*10)+(s[i]-'0'))%m;
    }
    return ans;
}

string con(ll n)
{
    string ans;
    if(!n)return "0";
    while(n>0)
    {
        ans += ((n%10)+'0');
        n/=10;
    }
    return ans;
}

bool sze(string s)
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='0')return false;
    }
    return true;
}

void solve()
{
   ll n,m,test=0;
   while (1) {
      cin>>n>>m;
      map<int,int>mp;
      for(int i=0;i<m;i++)
      {
          int a;
          cin>>a;
          mp[a] = 1;
      }
      ll num = n,f=1;
      while(num>0)
      {
          if(mp[num%10] == 1)
          {
              f=0;
              break;
          }
          num/=10;
      }
      if(f)
      {
          cout<<"Case "<<++test<<": ";
          cout<<n<<"\n";
          continue;
      }
      vector<int>v;
      for(int i=0;i<=9;i++)
      {
          if(!mp[i])v.push_back(i);
      }
      queue<string>q;
      for(int i=0;i<v.size();i++)
      {
          if(v[i])q.push(con(v[i]));
      }

      bool flg = 0;
      string ans = "-1";
      int vis[n+5];
      memset(vis,0,sizeof vis);

      while(!q.empty())
      {
          string str = q.front();
          q.pop();
          ll s = cal(str,n);
          if(!s)
          {
              ans = s;
              break;
          }
          if(!vis[s])
          {
              vis[s] = 1;
              for(int i=0;i<v.size();i++)
              {
                  string str1 = str + con(v[i]);
                  q.push(str1);
              }
          }
      }

      cout<<"Case "<<++test<<": ";
      for(int i=0;i<ans.size();i++)
      {
          if(!i&&ans[i] == '0')
          {
              while(ans[i] == '0')i++;
          }
          cout<<ans[i];
      }
      cout<<"\n";
   }
}

int main()
{
    CherryFrog;
   //int q;cin>>q;while(q--)solve();
  solve();
}

