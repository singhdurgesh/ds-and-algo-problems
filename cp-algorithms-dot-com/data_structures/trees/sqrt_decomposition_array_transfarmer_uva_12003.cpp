// # Problem: Array Transformer UVA - 12003 
// # Problem Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3154

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
const ll N = 300001, B = 601, K = 501;

vector<vector<ll> > blocks;
ll arr[N];

void update(int i, ll val){
   ll temp = arr[i];
   arr[i] = val;
   int j = i/B;

   int ind = lower_bound(blocks[j].begin(), blocks[j].end(), temp) - blocks[j].begin();
   blocks[j][ind] = val;
   sort(blocks[j].begin(), blocks[j].end());
}

int fetch_count(int l, int r, int v){
   int ans = 0;
   // Brute Force
   // for(int i=l; i<=r; i++){
   //    if(arr[i]<v) ans++;
   // }
   // return ans;
   int c_l = l/B, c_r = r/B;

   if(c_l == c_r){
      for(int i=l; i<=r; i++){
         if(arr[i]<v) ans++;
      }
   }else{
      for(int i=l, end = (c_l + 1)*B - 1; i<=end; i++){
         if(arr[i]<v) ans++;
      }

      for(int i=c_l+1; i<=c_r-1; i++){
         int temp = lower_bound(blocks[i].begin(), blocks[i].end(), v) - blocks[i].begin();
         if (temp == blocks[i].size()){
            ans += temp;
         }else if(temp == 0){
            ans += 0;
         }else{
            if(blocks[i][temp] == v){
               temp--;
            }
            ans += temp;
         }
      }

      for(int i=c_r*B; i<=r; i++){
         if(arr[i]<v) ans++;
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
   int n, m, u;
   scanf("%i %i %i", &n, &m, &u);

   blocks.resize(K);
   for(int i=1; i<=n; i++){
      scanf("%Li", &arr[i]);
      blocks[i/B].push_back(arr[i]);
   }

   build_the_table();

   while(m--){
      int l,r,v,p;
      scanf("%i %i %i %i", &l, &r, &v, &p);

      ll k = fetch_count(l,r,v);

      k = (u * k)/(r-l+1);
      update(p, k);
   }

   for(int i=1; i<=n; i++) printf("%Li\n", arr[i]);

   return 0;
}
