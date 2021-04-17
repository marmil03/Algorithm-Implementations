//Time-Complexity
/*
  Best-case:    O(n log n)
  Average-case: O(n log n)
  Worst-case:   O(n log n)
*/
//Memory-Complexity: O(n) total

void Merge(vector<int>&arr,int p,int q,int r){
  int n1=q-p+1;
  int n2=r-q;
  vector<int>L(n1+1),R(n2+1);
  for(int i=0;i<n1;i++) L[i]=arr[p+i];
  for(int i=0;i<n2;i++) R[i]=arr[q+i+1];
  L[n1]=INT_MAX;
  R[n2]=INT_MAX;
  int i=0,j=0;
  for(int k=p;k<=r;k++){
    if(L[i]<=R[j]){
      arr[k]=L[i];
      i++;
    }
    else {
      arr[k]=R[j];
      j++;
    }
  }
 }

void MergeSort(vector<int>&arr,int l,int r){
 if(l<r){
   int mid=l+(r-l)/2;
   MergeSort(arr,l,mid);
   MergeSort(arr,mid+1,r);
   Merge(arr,l,mid,r);
 }
}
