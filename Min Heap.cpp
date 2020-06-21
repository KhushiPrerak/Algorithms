class MinHeap {
      vector<int> arr;
      public: 
      MinHeap() {
            arr.clear();
      }
      int size() {
            return arr.size();
      }
      void insertKey(int key){
            arr.push_back(key);
            int currentIndex = arr.size()-1;
            while(currentIndex>0){
                  int parentIndex = (currentIndex-1)/2;
                  if(arr[parentIndex]>arr[currentIndex]) {
                        int temp = arr[currentIndex];
                        arr[currentIndex]=arr[parentIndex];
                        arr[parentIndex]=temp;
                  } else {
                        break;
                  }
                  currentIndex = parentIndex;
            }
      }
      int removeMin(){
            if(arr.size()==0) return INT_MAX; 
            int ans = arr[0];
            arr[0] = arr[arr.size()-1];
            arr.pop_back();
            
            //MinHeapify 
            int parentIndex = 0;
            int leftChild = 2*parentIndex + 1;
            int rightChild = 2*parentIndex + 2;
            
            while(leftChild < arr.size()) {
                  int minIndex = parentIndex ; 
                  if(arr[leftChild]<arr[minIndex]) {
                        minIndex = leftChild;
                  } 
                  if(arr[rightChild]<arr[minIndex]){
                        minIndex = rightChild;
                  }
                  if(minIndex == parentIndex) {
                        break;
                  } 
                  
                  int temp = arr[minIndex];
                  arr[minIndex] = arr[parentIndex];
                  arr[parentIndex] = temp;
                  parentIndex = minIndex;
                  leftChild = 2*parentIndex+1;
                  rightChild = 2*parentIndex+2;
            }
            return ans;
      }
      
      int getMin() {
            if(arr.size() == 0) return INT_MAX;
            return arr[0];
      }
      
      // Decreases value of key at index 'i' to new_val.  
      //It is assumed that new_val is smaller than arr[i]. 
      void decreaseKey(int i, int new_val) {
            if(i<0 && i>arr.size() ) {
                  cout<<"Invalid index!"<<endl;
                  return;
            }
            arr[i] = new_val;
            int parentIndex = (i-1)/2;
            while(i!=0 && arr[parentIndex]>arr[i]){
                  int temp = arr[i];
                  arr[i]=arr[parentIndex];
                  arr[parentIndex]=temp;
                  i = parentIndex;
            }
      }
      
      // This function deletes key at index i. 
      //It first reduced value to -INF and then calls removeMin(). 
      void deleteKey(int i){
            if(i<0 && i>arr.size()) {
                  cout<<"Invalid index!"<<endl;
                  return;
            }
            decreaseKey(i,INT_MIN);
            removeMin();
      }
      
};
