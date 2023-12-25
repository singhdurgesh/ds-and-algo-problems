// Problem Link: spoj.com/problems/KQUERY/
// Problem: KQUERY - K-Query
// Algorithm: Segment Tree - Merge Sort Tree
//            Saving the entire subarrays in each vertex

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define N 300001

vector<int> m_tree[4 * N];
int arr[N];

vector<int> combine(vector<int> &left, vector<int> &right){
   vector<int> result;

   int l=0, r=0;
   while(l < left.size() && r < right.size()){
      if(left[l] < right[r]){
         result.pb(left[l]);
         l++;
      }else{
         result.pb(right[r]);
         r++;
      }
   }

   while(l<left.size()){
      result.pb(left[l]);
      l++;
   }

   while(r<right.size()){
      result.pb(right[r]);
      r++;
   }

   return result;
}

void build(int v, int l, int r){
   if(l>r) return;

   if(l==r){
      m_tree[v] = {arr[l]};
      return;
   }

   int mid = (l+r)/2;

   build(2*v,l,mid);
   build(2*v + 1, mid+1,r);

   m_tree[v] = combine(m_tree[2*v], m_tree[2*v+1]);
}

int find_kth(int v, int tl, int tr, int l, int r, int x){
   if(l>r) return 0;

   if(l==r){
      return arr[l] > x;
   }

   if(tl==l && tr==r){
      int ind = upper_bound(m_tree[v].begin(), m_tree[v].end(), x) - m_tree[v].begin();
      if(ind == m_tree[v].size()){
         return 0;
      }else{
         if(m_tree[v][ind] == x){
            return m_tree[v].size() - ind - 1;
         }else{
            return m_tree[v].size() - ind;
         }
      }
   }

   int tm = (tl+tr)/2;

   return find_kth(2*v, tl, tm, l, min(tm, r), x) + find_kth(2*v+1, tm+1, tr, max(l,tm+1), r, x);
}

int main(){
   int n;
   scanf("%d", &n);

   for(int i=0; i<n; i++){
      scanf("%d", &arr[i]);
   }

   build(1, 0, n-1);

   int m;
   scanf("%d", &m);

   while(m--){
      int i, j, k;
      scanf("%d %d %d", &i, &j, &k);
      printf("%d\n", find_kth(1, 0, n-1, i-1, j-1, k));
   }

   return 0;
}
