#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


string f(string s)
{
   string frr;
  stack<char>st;
  for(int i=0;i<s.size();i++)
  {
      if(s[i] == 'C'){
          if(st.size() >= 2){
              char c = st.top();
              if(c == 'B'){
                st.pop();
                char k = st.top();
                if( k == 'A'){
                    st.pop();
                }
                else{
                    st.push(c);
                    st.push(s[i]);
                }
              }
              else st.push(s[i]);
          }
          else st.push(s[i]);
      }
      else st.push(s[i]);
  }

  while(st.size()>0)
  {
      char tp = st.top();
      st.pop();
      frr += tp;
   }
  reverse(frr.begin(),frr.end());
  return frr;
}

void solve()
{
  //  cout<<"yes"<<endl;
  string s;
  cin>>s;

  cout << f(s) << endl;
}

int main()
{
    CherryFrog;
   //int q;cin>>q;while(q--)solve();
  solve();
}

