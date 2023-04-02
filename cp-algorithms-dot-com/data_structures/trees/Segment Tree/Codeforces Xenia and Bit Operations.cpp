// Problem Link: https://codeforces.com/problemset/problem/339/D
// Problem: 339D - Xenia and Bit Operations
// Algorithm: Standard Segment Tree

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define N 200001

vector< pair<int,int> > m_tree(4 * N);
int arr[N];

pair<int, int> combine(pair<int, int> l,pair<int, int> r){
   return mp(l.second ^ r.second, l.first | r.first);
}

void build(int v, int l, int r){
   if(l>r) return;

   if(l==r){
      m_tree[v] = mp(arr[l], arr[l]);
      return;
   }

   int mid = (l+r)/2;

   build(2*v,l,mid);
   build(2*v + 1, mid+1,r);

   m_tree[v] = combine(m_tree[2*v], m_tree[2*v+1]);
}

void update(int v, int l, int r, int p, int val){
   if(l>r) return;

   if(l==r){
      m_tree[v] = mp(val, val);
      return;
   }

   int m = (l+r)/2;

   if(p<=m){
      update(2*v,l,m,p,val);
   }else{
      update(2*v+1,m+1,r,p,val);
   }

   m_tree[v] = combine(m_tree[2*v], m_tree[2*v+1]);
}

int main(){
   int n, m;
   scanf("%d %d", &n, &m);

   int len = n;
   n = 1 << n;
   for(int i=0; i<n; i++){
      scanf("%d", &arr[i]);
   }

   build(1, 0, n-1);

   while(m--){
      int p,b;
      scanf("%d %d", &p, &b);
      update(1,0,n-1,p-1,b);
      printf("%d\n", (len%2) ? m_tree[1].second : m_tree[1].first);
   }

   return 0;
}
