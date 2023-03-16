#include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin>>n;
   int a[n];
   int sparse_t[26][n];
   for(int i=0; i<n; i++){
      cin>>sparse_t[0][i];
   }

   for (int i=1; i<=25; i++){
      for (int j=0; j + (1<<i) <= n; j++){
         sparse_t[i][j] = min(sparse_t[i-1][j], sparse_t[i-1][j + (1 << (i-1))]);
      }
   }

   int lg[n+1];
   lg[1] = 0;
   for(int i=2; i<=n; i++){
      lg[i] = lg[i/2] + 1;
   }

   int q,l,r,lg_l;
   cin>>q;
   while(q--){
      cin>>l>>r;
      lg_l = lg[r-l+1];
      cout<<min(sparse_t[lg_l][l], sparse_t[lg_l][r-(1<<lg_l)+1])<<endl;
   }
}
