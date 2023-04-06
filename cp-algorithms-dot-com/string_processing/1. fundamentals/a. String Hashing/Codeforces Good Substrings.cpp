// Problem Link: <Problem Link>
// Problem: 339D - <Problem Desc>
// Algorithm: Segment Tree - Range Updates Lazy Propogration

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define P1 37
#define P2 43
#define M 1000000007
const int N = 1501;

ll pow1[N];
ll pow2[N];

void calculate_pow(int n){
   pow1[0] = 1;
   pow2[0] = 1;

   for(int i=1; i<n; i++){
      pow1[i] = (pow1[i-1] * P1) % M;
      pow2[i] = (pow2[i-1] * P2) % M;
   }
}

pair<ll, ll> compute_hash(ll val, ll ind){
   ll first = (val * pow1[ind])%M;
   ll second = (val * pow2[ind])%M;

   return make_pair(first, second);
}

int main(){
   string s;
   cin>>s;
   int n=s.length();
   calculate_pow(n+1);

   char weight[26];
   scanf("%s", &weight);

   int k;
   scanf("%d", &k);

   set<pair<ll,ll> > st;

   for(int i=0; i<n; i++){
      ll hash1 = 0, hash2 = 0, bad = 0;
      for(int j=i; j<n; j++){
         int ind = s[j] - 'a';
         if(weight[ind]=='0') bad++;
         // printf("%d %d %d %Li %Li\n", i, j, bad, hash1, hash2);
         if(bad==k+1) break;

         pair<ll, ll> hash = compute_hash(ind+1, j-i);

         hash1 = (hash1 + hash.first) % M;
         hash2 = (hash2 + hash.second) % M;

         st.insert(make_pair(hash1, hash2));
      }
   }

   cout<<st.size()<<endl;

   return 0;
}
