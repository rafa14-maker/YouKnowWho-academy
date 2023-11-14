#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int test;

bool f(string arr, string frr){
      ll a = 0 , b =0;

      for(int i=0;i<arr.size();i++)
      {
          a*=10;
          int r = (int)(arr[i]-'0');
          a+=r;
      }

      int idx = 1;

      for(int i = frr.size()-1;i>=0;i--){

        int r = (int)(frr[i]-'0');
        b += idx*r;
        idx *= 2;
      }

     // cout << a <<" "<<b<<endl;

      if(a != b)return false;
      return true;
}

void solve()
{
  //  cout<<"yes"<<endl;
  string arr;
  cin>>arr;
  string frr;
  cin>>frr;

  printf("Case %d: ",++test);

  for(int i=0,j=0;i<arr.size();i++,j++){
    int a = i , b = j;
    string ak,bk;
    while(arr[a] != '.' && a<arr.size())
    {
        ak += arr[a];
        a++;
    }
    while(frr[b] != '.' && b<frr.size())
    {
        bk += frr[b];
        b++;
    }
    i = a;
    j = b;
    if(!f(ak,bk)){
        printf("No\n");
        return ;
    }
  }

  printf("Yes\n");
}

int main()
{
    CherryFrog;
   int q;cin>>q;while(q--)solve();
 // solve();
}

