// Problem Link: https://lightoj.com/problem/curious-robin-hood
// Problem: Curious Robin Hood

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

vector<ll> sack;
vector<ll> fsack;
ll num;

void add(ll r, ll val){
   for(; r < sack.size(); r = (r | (r+1))){
      sack[r]+=val;
   }
}

ll sum(ll i){
   ll ans = 0;

   for(; i >= 0; i = (i&(i+1)) - 1){
      ans += sack[i];
   }

   return ans;
}

ll sum_range(ll l, ll r){
   return sum(r) - sum(l - 1);
}

void main_with_test(ll case_num){
   ll n,q,val;
   cin>>n>>q;
   num = n;
   sack.clear();
   fsack.clear();
   sack.resize(n,0);
   fsack.resize(n,0);
   for(ll i=0; i<n; i++){
      cin>>fsack[i];
      add(i, fsack[i]);
   }

   cout<<"Case "<<case_num<<":"<<endl;
   ll action,input1,input2;
   while(q--){
      cin>>action;
      if(action==1){
         cin>>input1;
         val = fsack[input1];
         fsack[input1] = 0;
         add(input1,-val);
         cout<<val<<endl;
      }else if(action==2){
         cin>>input1>>input2;
         fsack[input1] += input2;
         add(input1,input2);
      }else{
         cin>>input1>>input2;
         cout<<sum_range(input1,input2)<<endl;
      }
   }
}

int main(){
   ll t; cin>>t;
   for(ll i=1; i<=t; i++){
      main_with_test(i);
   }

   return 0;
}
