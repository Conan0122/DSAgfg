// Approach: Using recursion and quickselect algorithm(finding pivot)
// Find pivot and check if it is the kth element.
// Based on pivot recurse for array with updated low and high.

int pivot(vector<int> &arr, int low, int high){
    int i= low;
    
    while(i<=high){
        if (arr[i] <= arr[high]) swap(arr[low++], arr[i++]);
        else i++;
    }
    return low-1;
}

int find(vector<int> &arr, int low, int high, int k){
    if (low>high){
        return -1;
    }
    
    int ele = pivot(arr, low, high);
    
    if (ele == k-1) return arr[ele];
    else if (ele > k-1) return find(arr, 0, ele-1, k);
    else return find(arr, ele+1, high, k);
}

int kthSmallest(vector<int> &arr, int k) {
    int n = arr.size();
    return find(arr, 0, n-1, k);
}

//////////////////////////////////////////////////////////////////////////////
// Approach: Using Quickselect with simple loop

int pivot(vector<int> &arr, int low, int high){
    int i= low;
    
    while(i<=high){
        if (arr[i] <= arr[high]) swap(arr[low++], arr[i++]);
        else i++;
    }
    return low-1;
}

int kthSmallest(vector<int> &arr, int k) {
    int n = arr.size();
    int low = 0, high = n-1;
    
    while(low <= high){
        int ele = pivot(arr, low, high);
        if (ele == k-1) return arr[ele];
        else if (ele > k-1){
            low = 0;
            high = ele-1;
        }
        else{
            low = ele+1;
        }
    }
    return -1;
