// Problem Link: https://www.codechef.com/problems/MSTICK
// RMQSQ - Matchsticks
#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long sparse_t[26][100001];
long long sparse_m[26][100001];
long long lg[100001];

long long query(long long l, long long r){
  long long lg_l = lg[r-l+1];
  return max(sparse_t[lg_l][l], sparse_t[lg_l][r-(1<<lg_l)+1]);
}

long long query_m(long long l, long long r){
  long long lg_l = lg[r-l+1];
  return min(sparse_m[lg_l][l], sparse_m[lg_l][r-(1<<lg_l)+1]);
}

int main() {
   long long n,q;
   cin>>n;
   
   for(int i=0; i<n; i++){
      cin>>sparse_t[0][i];
      sparse_m[0][i] = sparse_t[0][i];
   }

   for (long long i=1; i<=25; i++){
      for (long long j=0; j + (1<<i) <= n; j++){
         sparse_t[i][j] = max(sparse_t[i-1][j], sparse_t[i-1][j + (1 << (i-1))]);
         sparse_m[i][j] = min(sparse_m[i-1][j], sparse_m[i-1][j + (1 << (i-1))]);
      }
   }

   
   lg[1] = 0;
   for(long long i=2; i<=n; i++){
      lg[i] = lg[i/2] + 1;
   }

   long long l,r,max_val, min_val ,ll, rr;
   cin>>q;
   while(q--){
      ll=0,rr=0;
      cin>>l>>r;
      max_val = query(l,r);
      min_val = query_m(l,r);
      if(l!=0){
          ll = query(0,l-1);
      }
      if(r!=n-1){
          rr = query(r+1,n-1);
      }
      double ss,bb;
      bb = ((double)max_val - (double)min_val)/2;
      ss = (double)max(ll,rr);
      double ans = min_val + max(bb,ss);
      printf("%0.1lf\n", ans);
   }
}
