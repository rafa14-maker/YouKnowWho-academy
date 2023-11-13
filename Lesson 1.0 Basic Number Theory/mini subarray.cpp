#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define CherryFrog ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int f(vector<int>nums,int target)
{
      vector<long long>num;

        for(int i=0;i<nums.size();i++){
            num.push_back(nums[i]);
        }

       int l = 0 , r = num.size()-1;
       int mn = num.size()-1;

       for(int i=1;i<num.size();i++){
             num[i] += num[i-1];
       }

       //for(int i=0;i<nums.size();i++)cout<< num[i]<<" ";cout<<endl;

       if(num[num.size()-1] < target)return 0;

       while(l<=r)
       {
           int mid = (l+r)/2;

          bool tr = false;

          for(int i=0;i<num.size();i++)
          {
              long long  op = 0;
                 if(i+mid <num.size()){
                         if(i == 0){
                             op = max(op,num[i+mid]);
                         }
                         else{
                             op = max(op,num[i+mid] - num[i-1]);
                         }
                 }
                // cout << op <<" "<<mid<<endl;
               if(op >= target)tr = true;
          }

           if(tr)
           {
             //  cout<< mid<<endl;
                    mn = min(mn, mid+1);
                    r = mid - 1;
           }
           else l = mid+1;
       }
       return mn;
    }


void solve()
{
  //  cout<<"yes"<<endl;
  vector<int>vectors;

  int n;
  cin>>n;

  for(int i=0;i<n;i++)
  {
      int a;
      cin>>a;
      vectors.push_back(a);
  }

  int k;
  cin>>k;

  cout << f(vectors , k) <<endl;

}

int main()
{
    CherryFrog;
   //int q;cin>>q;while(q--)solve();
  solve();
}

/*

6
0 0 2 3 4 0
9


*/

