// Problem Link: https://www.spoj.com/problems/GSS3/
// Problem: 339D - GSS3 - Can you answer these queries III
// Algorithm: Segment Tree - Data Structures

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define N 50001

int arr[N+1];

struct Vertex{
   int sum, prefix, suffix, max;
};

Vertex Tree[4*N];

int sum_big(int a, int b){
   if(a==INT_MIN) return b;
   if(b==INT_MIN) return a;
   return a+b;
}

Vertex combine(Vertex a, Vertex b){
   Vertex node;
   node.sum = sum_big(a.sum, b.sum);
   node.prefix = max(a.prefix, sum_big(a.sum, b.prefix));
   node.suffix = max(b.suffix, sum_big(b.sum, a.suffix));
   node.max = max(max(a.max, b.max), sum_big(a.suffix, b.prefix));
   return node;
}

void build(int v, int l, int r){
   if(l > r) return;

   if(l==r){
      Vertex vec;
      vec.sum = vec.prefix = vec.suffix = vec.max = arr[l];
      Tree[v] = vec;
      return;
   }

   int m = (l+r)/2;
   build(2*v, l, m);
   build(2*v+1, m+1, r);

   Tree[v] = combine(Tree[2*v], Tree[2*v+1]);
}

void update(int v, int tl, int tr, int p, int val){
   if(tl>tr) return;

   if(tl==tr){
      arr[p] = val;
      Vertex vec;
      vec.sum = vec.prefix = vec.suffix = vec.max = val;
      Tree[v] = vec;
      return;
   }

   int m = (tl+tr)/2;
   if(p<=m){
      update(2*v, tl, m, p, val);
   }else{
      update(2*v+1, m+1, tr, p, val);
   }

   Tree[v] = combine(Tree[2*v], Tree[2*v+1]);
}

Vertex find_sum(int v, int tl, int tr, int l, int r){
   if(l>r) {
      Vertex vec;
      vec.sum = INT_MIN;
      vec.prefix = INT_MIN;
      vec.suffix = INT_MIN;
      vec.max = INT_MIN;
      return vec;
   }

   if(tl==l && tr==r){
      return Tree[v];
   }

   int tm = (tl+tr)/2;

   return combine(find_sum(2*v, tl, tm, l, min(r,tm)), find_sum(2*v+1, tm+1, tr, max(l,tm+1), r)); 
}

int main(){
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &arr[i]);

   build(1, 0, n-1);

   int m;
   scanf("%d", &m);

   while(m--){
      int a, x, y;
      scanf("%d %d %d", &a, &x, &y);
      if(a){
         printf("%d\n", find_sum(1,0,n-1,x-1,y-1).max);
      }else{
         update(1,0,n-1,x-1,y);
      }
   }

   return 0;
}
