
//Time-Complexity
/*
  Best-case:    O(n)
  Average-case: O(n^2)
  Worst-case:  	O(n^2)
*/
//Memory-Complexity O(n)

void InsertionSort(vector<int>&arr,int length){
  for(int i=1;i<length;i++){
    int key=arr[i];
    int j=i-1;
    while(j>=0 && a[j]>key){
      arr[j+1]=arr[j];
      j--;
    }
    a[j+1]=key;
  }
}
