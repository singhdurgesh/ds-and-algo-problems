// Problem Link: https://codeforces.com/contest/25/problem/D
// Problem: D. Roads not only in Berland
// Tages: DSU

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

vector<int> parent;

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

bool same_parent(int a, int b){
   return find_set(a) == find_set(b);
}

int main(){
   int n,m;
   cin>>n;
   m = n-1;
   vector<pair<int,int> > duplicate_edges, new_edges;

   parent.resize(n+1);
   for(int i=0; i<=n; i++) parent[i] = i;

   int l,r;
   for(int i=0; i<m; i++){
      cin>>l>>r;
      if(!same_parent(l,r)){
         union_set(l,r);
      }else{
         duplicate_edges.push_back(mp(l,r));
      }
   }

   vector<int> parents;
   for(int i=1;i<=n; i++){
      if(parent[i]==i){
         parents.push_back(i);
      }
   }

   for(int i=1; i<parents.size(); i++){
      new_edges.push_back(mp(parents[i-1], parents[i]));
   }

   cout<<duplicate_edges.size()<<endl;
   for(int i=0; i<duplicate_edges.size(); i++){
      cout<<duplicate_edges[i].first<<" "<<duplicate_edges[i].second<<" "<<new_edges[i].first<<" "<<new_edges[i].second<<endl;
   }

   return 0;
}
