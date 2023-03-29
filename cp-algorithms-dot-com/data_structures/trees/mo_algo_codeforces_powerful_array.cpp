// # Problem: D. Powerful array
// # Problem Link: https://codeforces.com/problemset/problem/86/D

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
const int N = 200001, B = 501, K = 401;
struct Query{
   int l, r, idx;

   bool operator<(Query other) const{
      return mp(l / B, r) < mp(other.l / B, other.r);
   }
};

vector<Query> queries;

ll  result[N];

int arr[N];

int count_map[1000001];

ll current_ans;

void add(int i){
   i = arr[i];

   count_map[i]++;
   ll count = count_map[i];
   current_ans += ((count + count - 1) * (ll)i);
}

void remove(int i){
   i = arr[i];
   ll count = count_map[i];
   current_ans -= ((count + count - 1) * (ll)i);

   count_map[i]--;
}

void solve(){
   sort(queries.begin(), queries.end());

   memset(count_map, 0, sizeof(count_map));
   current_ans = 0;
   int start = 1, end = 0;
   for(int i=0; i<queries.size(); i++){
      int l,r,ind;
      l = queries[i].l;
      r = queries[i].r;
      ind = queries[i].idx;

      while(start>l){
         start--;
         add(start);
      }

      while(end<r){
         end++;
         add(end);
      }

      while(start<l){
         remove(start);
         start++;
      }

      while(end>r){
         remove(end);
         end--;
      }

      result[ind] = current_ans;
   }
}

int main(){
   int n,t;
   scanf("%d %d", &n, &t);

   for(int i=1; i<=n; i++) scanf("%d", &arr[i]);

   for(int i=0; i<t; i++){
      int l,r;
      scanf("%d %d", &l, &r);
      Query query;
      query.l = l;
      query.r = r;
      query.idx = i;
      queries.push_back(query);
   }

   solve();

   for(int i=0; i<t; i++) cout<<result[i]<<"\n";

   return 0;
}
