// Problem: https://www.codechef.com/problems/SPREAD
// Problem: Gavel
// Status: TLE (Lazy propogation will be used to implement the solution)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

vector<ll> heap;
ll n,m,c;

ll next_val_index_1(ll n){
   return n + (n&(-n));
}

ll prev_val_index_1(ll n){
   return n - (n&(-n));
}

void add(ll u, ll k){
   for(; u<=n; u += u & (-u)){
      heap[u] += k;
   }
}

ll sum(ll u){
   ll ans = 0;
   for(; u>0; u -= (u&(-u))){
      ans += heap[u];
   }

   return ans + c;
}

void add_range(ll u,ll v, ll k){
   if(u>v){
      swap(u,v);
   }
   add(u,k);
   add(v+1, -k);
}

int main(){
   cin>>n>>m>>c;

   heap.clear();
   heap.resize(n+1);

   char action;
   ll u,v,k;
   while(m--){
      cin>>action;
      switch(action){
         case 'S':
            scanf("%Li %Li %Li", &u, &v, &k);
            add_range(u,v,k);
            break;
         case 'Q':
            cin>>u;
            printf("%Li\n", sum(u));
            break;
      }
   }
   return 0;
}