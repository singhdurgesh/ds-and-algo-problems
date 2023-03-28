#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define N 1001

vector<vector<int> > rec;
map<pair<int, int>, int> point_m;

void add(int x, int y){
   // return if the point is already present
   if (point_m.find(mp(x,y)) != point_m.end()){
      return;
   }

   point_m[mp(x,y)]++;

   for(int i=x ;i<N; i = (i | (i+1))){
      for(int j=y; j<N; j = (j | (j+1))){
         rec[i][j]++;
      }
   }
}

int sum(int x, int y){
   int ans = 0;

   for(int i=x; i>=0; i = (i & (i+1)) - 1){
      for(int j=y; j>=0; j = (j & (j+1)) - 1){
         ans += rec[i][j];
      }
   }

   return ans;
}

int result(int x1, int y1, int x2, int y2){
   return sum(x2, y2) + sum(x1-1, y1-1) - sum(x1-1,y2) - sum(x2, y1-1);
}

void main_with_test(){
   rec.clear();
   rec.resize(N, vector<int> (N,0));
   point_m.clear();

   int q;
   cin>>q;
   int action, x, y, a, b;
   while(q--){
      cin>>action;
      switch(action){
         case 0:
            cin>>x>>y;
            add(x,y);
            break;
         case 1:
            cin>>x>>y>>a>>b;
            cout<<result(x,y,a,b)<<endl;
            break;
         default:
            break;
      }
   }
}

int main(){
   int t; cin>>t;
   for(int i=1; i<=t; i++){
      printf("Case %i:\n", i);
      main_with_test();
   }

   return 0;
}
