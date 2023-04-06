// Problem Link: https://codeforces.com/problemset/problem/154/C
// Problem: 154C - Double Profiles
// Algorithm: String Hashing

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define P1 1000003
#define P2 1000007
#define M 1000000007
const int N = 1000001;

vector<int> v[N];
pair<long long, long long> w[N];

ll pow1[P1], pow2[P2];

void calculate_pow(int n){
   pow1[0] = pow2[0] = 1;

   for(int i=1; i<n+1; i++){
      pow1[i] = (pow1[i-1] * P1) % M;      
   }

   for(int i=1; i<n+1; i++){
      pow2[i] = (pow2[i-1] * P2) % M;
   }
}

void compute_hash(int x){
   long long hash1 = 0, hash2 = 0;

   int n=v[x].size();
   for(int i=0; i<n; i++){
      hash1 += (v[x][i] * pow1[v[x][i]]) % M;
      hash2 += (v[x][i] * pow2[v[x][i]]) % M;
   }

   w[x] = mp(hash1, hash2);
}

// Won't work
pair<ll, ll> get_hash(int ind, int exc){
   pair<ll, ll> result = w[ind];

   ll first = (w[ind].first + M - (exc * pow1[exc]) % M) % M;
   ll second = (w[ind].second + M - (exc * pow2[exc]) % M) % M;
   // printf("%d %d %d %d\n", ind, exc, (int)first, (int)second);
   return mp(first, second);
}

int main(){
   int n,m;
   scanf("%d %d", &n, &m);

   calculate_pow(n);

   int x, y;
   pair<int, int> qu[m];
   for(int i=0; i<m; i++){
      scanf("%d %d", &x, &y);
      v[x].pb(y);
      v[y].pb(x);
      qu[i] = mp(x,y);
   }

   ll ans = 0, cnt=0;
   map<pair<ll, ll> , int> mp;

   for(int i=1; i<=n; i++){
      sort(v[i].begin(), v[i].end());
      compute_hash(i);

      if(mp.find(w[i])!=mp.end()){
         ans += mp[w[i]];
      }

      mp[w[i]]++;
   }

   for(int i=0; i<m; i++){
      x = qu[i].first;
      y = qu[i].second;
      pair<ll, ll> t1 = get_hash(x, y);
      pair<ll, ll> t2 = get_hash(y, x);

      if(t1.first == t2.first && t1.second == t2.second) {
         // printf("%d %d\n", x, y);
         ans++;
      }
   }

   cout<<ans<<endl;

   return 0;
}
