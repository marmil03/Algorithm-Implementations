//LIS O(n^2)
void Solve(){
  vector<int>tst={10,25,21,23,24,40,25,50};
  int n=8;
  vector<int>lis(n,1);
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      if(tst[i]>tst[j] && lis[i]<lis[j]+1) lis[i]=lis[j]+1;
    }
  }
  cout<<*max_element(lis.begin(),lis.end());
}
