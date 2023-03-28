// Problem: https://www.spoj.com/problems/MATSUM/
// Problem: Matrix Summation
// Status: TLE

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define N 1025

int mat[N][N];
int org[N][N];

int n;

void add(int x, int y, int a){
   for(int i=x; i<n; i = i | (i+1)){
      for(int j=y; j<n; j = j | (j+1)){
         mat[i][j] += a;
      }
   }
}

int sum(int x, int y){
   int ans = 0;

   for(int i=x; i>=0; i = (i&(i+1)) - 1){
      for(int j=y; j>=0; j = (j&(j+1)) - 1){
         ans += mat[i][j];
      }
   }

   return ans;
}

int sum_range(int x, int y, int a, int b){
   return sum(a,b) + sum(x-1,y-1) - sum(x-1, b) - sum(a, y-1);
}

void main_with_test(){
   scanf("%d", &n);

   memset(org,0,sizeof(org));
   memset(mat,0,sizeof(mat));

   char action[30]; // String with Char Array
   int x,y,a,b;
   while(true){
      scanf("%s", &action); // Char Input
      if(!strcmp(action, "SET")){ // Compare two Char Array Strings
         scanf("%d %d %d", &x, &y, &a);
         add(x,y,-org[x][y] + a);
         org[x][y] = a;
      }else if(!strcmp(action, "SUM")){
         scanf("%d %d %d %d", &x, &y, &a, &b);
         printf("%d\n", sum_range(x,y,a,b));
      }else{
         break;
      }
   }
   cout<<"\n";
}

int main(){
   int t; scanf("%d", &t);
   while(t--){
      main_with_test();
   }
   return 0;
}
