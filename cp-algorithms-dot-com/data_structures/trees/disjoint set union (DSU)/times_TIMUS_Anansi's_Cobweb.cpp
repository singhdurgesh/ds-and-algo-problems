// Problem: 1671. Anansi's Cobweb
// Problem Link: https://acm.timus.ru/problem.aspx?space=1&num=1671
// DSU

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

vector<int> parent;
int current_count;

int find_set(int a){
   if(parent[a] == a){
      return a;
   }
   return parent[a] = find_set(parent[a]);
}

void union_set(int a, int b){
   int parent_a = find_set(a);
   int parent_b = find_set(b);

   if(parent_a != parent_b){
      current_count--;
      parent[parent_a] = parent_b;
   }
}

void build_initial_set(vector<pair<int,int> > &edges, vector<int> &sorted_a, int n){
   for(int i=0; i<edges.size(); i++){
      if(!binary_search(sorted_a.begin(), sorted_a.end(), i+1)){
         union_set(edges[i].first, edges[i].second);
      }
   }
}

void process_output(vector<int> &q, vector<pair<int,int>> &edges){
   vector<int> ans;
   for(int i=q.size()-1; i>=0; i--){
      int ind=q[i]-1;
      ans.push_back(current_count);
      union_set(edges[ind].first, edges[ind].second);
   }

   reverse(ans.begin(), ans.end());
   for(int i=0; i<ans.size(); i++){
      cout<<ans[i]<<" ";
   }
}

int main(){
   int n,m;
   cin>>n>>m;

   vector<pair<int,int> > input;
   parent.resize(n+1);
   for(int i=0; i<=n; i++) parent[i] = i;
   current_count = n;

   int l,r;
   for(int i=0; i<m; i++){
      cin>>l>>r;
      input.push_back(mp(l,r));
   }

   int q;cin>>q;
   vector<int> query(q), sorted_query(q);
   for(int i=0; i<q; i++) {
      cin>>query[i];
      sorted_query[i] = query[i];
   }

   sort(sorted_query.begin(), sorted_query.end());

   build_initial_set(input, sorted_query, n);

   process_output(query, input);
}
