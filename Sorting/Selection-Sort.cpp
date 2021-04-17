//Time-Complexity
/*
  Best-case:    O(n^2)
  Average-case: O(n^2)
  Worst-case:   O(n^2)
*/
//Memory-Complexity: O(1)-auxiliary

void SelectionSort(vector<int>&arr,int n){
  for(int i=0;i<n;i++){
    int current=arr[i];
    int index=i;
    for(int j=i+1;j<n;j++){
      if(current<arr[j]) current=arr[j],index=j;
    }
    swap(arr[i],arr[index]);
  }
}
