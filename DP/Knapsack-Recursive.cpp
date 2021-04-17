#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mk make_pair
#define v_sort(x) sort(x.begin(),x.end())
#define v_gsort(x) sort(x.begin(),x.end(),greater<ll>())
#define v_find(x,num) find(x.begin(),x.end(),num)
#define PI 3.14159265
#define MOD 998244353
#define MOD1 1000000007


using namespace std;

int knapsack(int W,vector<int>&wt,vector<int>&val,int i,vector<vector<int>>&dp){
  if(i<0) return 0;
  if(dp[i][W]!=-1) return dp[i][W];
  if(wt[i]>W){
    dp[i][W]=knapsack(W,wt,val,i-1,dp);
    return dp[i][W];
  }
  else{
    dp[i][W]=max(val[i]+knapsack(W-wt[i],wt,val,i-1,dp),knapsack(W,wt,val,i-1,dp));
    return dp[i][W];
  }
}

void Solve(){
  int n,W;
  cin>>n>>W;
  vector<int>val(n),wt(n);
  for(int i=0;i<n;i++) cin>>val[i];
  for(int i=0;i<n;i++) cin>>wt[i];
  vector<vector<int>>dp(n,vector<int>(W+1,-1));
  cout<<knapsack(W,wt,val,n-1,dp);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t=1;
//  cin>>t;
  while(t--){
    Solve();
  }
  return 0;
}
