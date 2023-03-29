// # Problem: SPOJ: Give Away
// # Problem Link: https://www.spoj.com/problems/GIVEAWAY/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
const int N = 500001, B = 801, K = 701;

vector<vector<ll> > blocks;
ll arr[N];

void update(int i, ll val){
   int j = i/B;

   int ind = lower_bound(blocks[j].begin(), blocks[j].end(), arr[i]) - blocks[j].begin();
   blocks[j][ind] = val;
   arr[i] = val;
   sort(blocks[j].begin(), blocks[j].end());
}

int fetch_count(int l, int r, int v){
   int ans = 0;
   int c_l = l/B, c_r = r/B;

   if(c_l == c_r){
      for(int i=l; i<=r; i++){
         if(arr[i]>=v) ans++;
      }
   }else{
      for(int i=l, end = (c_l + 1)*B - 1; i<=end; i++){
         if(arr[i]>=v) ans++;
      }

      for(int i=c_l+1; i<=c_r-1; i++){
         int temp = lower_bound(blocks[i].begin(), blocks[i].end(), v) - blocks[i].begin();
         int size = blocks[i].size();

         if(temp<size){
            if(blocks[i][temp] == v){
               ans += (size - temp + 1);
            }else{
               ans += (size - temp);
            }
         }
      }

      for(int i=c_r*B; i<=r; i++){
         if(arr[i]>=v) ans++;
      }
   }

   return ans;
}

void build_the_table(){
   for(int i=0; i<K; i++){
      sort(blocks[i].begin(), blocks[i].end());
   }
}

int main(){
   int n;
   scanf("%i", &n);

   blocks.resize(K);
   for(int i=1; i<=n; i++){
      scanf("%Li", &arr[i]);
      blocks[i/B].push_back(arr[i]);
   }

   build_the_table();

   int q; cin>>q;

   while(q--){
      int action;
      scanf("%i", &action);

      if(action == 0){
         int a,b,c;
         scanf("%i %i %i", &a, &b, &c);

         cout<<fetch_count(a,b,c)<<"\n";
      }else{
         int a, b;
         scanf("%i %i", &a, &b);
         update(a,b);
      }
   }

   return 0;
}
