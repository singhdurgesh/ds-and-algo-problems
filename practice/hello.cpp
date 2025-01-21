#include <bits/stdc++.h>
using namespace std;

int solve(int n, int *arr){
   int minus = 0;
   for(int i=0; i<n; i++){
      if(arr[i]<0) minus++;
      else if(arr[i]==0) return 0;
   }

   return minus%2+1;
}

int main() {
   int t; cin>>t;
   while(t--){
      int n;
      cin>>n;
      int arr[n];
      for(int i=0; i<n; i++) cin>>arr[i];

      int ans = solve(n, arr);
      if(ans==0){
         cout<<'0'<<endl;
      }else if(ans==2){
         cout<<'0'<<endl;
      }else{
         cout<<'1'<<endl;
         cout<<"1 0"<<endl;
      }
   }
}
