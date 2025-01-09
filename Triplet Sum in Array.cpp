// Logic: sort the array and then in first loop fix first element and in nested loop using two pointer keep on checking valid target.
bool hasTripletSum(vector<int> &arr, int target) {
    int n = arr.size();
    
    sort(arr.begin(), arr.end());
    
    for (int i=0; i<n; i++){
        int low = i+1, high = n-1;
        
        while(low<high){
            if (arr[i]+arr[low]+arr[high] == target) return true;
            else if (arr[i]+arr[low]+arr[high] > target) high--;
            else low++;
        }
    }
    return false;
}
