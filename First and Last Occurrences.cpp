// T.C = O(logn)
// S.C = O(1)
// Logic: Using modified binary search to find first and last occurences separately.
vector<int> find(int arr[], int n , int x )
{
    int start=0, end=n-1;
    int startOcc=-1, endOcc=-1;
    
    // First Occ
    while (start<=end){
        int mid = start+(end-start)/2;
        
        if (arr[mid]==x){
            startOcc = mid;
            end = mid-1;
        }
        else if (arr[mid] < x) start = mid+1;
        else end = mid-1;
    }
    
    start=0;
    end=n-1;
    
    // Last Occ
    while (start<=end){
        int mid = start+(end-start)/2;
        
        if (arr[mid]==x){
            endOcc = mid;
            start = mid+1;
        }
        else if (arr[mid] < x) start = mid+1;
        else end = mid-1;
    }
    
    return {startOcc, endOcc};
}
