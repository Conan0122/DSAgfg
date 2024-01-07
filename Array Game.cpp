// T.C = O(n*n)
// S.C = O(1)
class Solution{
    public:
    void RotateArr(vector<int> &arr){
        int n = arr.size();
        int firstele = arr[0];
        
        for (int i=0; i<n-1; i++){
            arr[i] = arr[i+1];
        }
        arr[n-1] = firstele;
    }
    
    int min_operations(int n, vector<int>&arr, vector<int>&brr) {
        int count=0;
	    while (n>0) {
	        // IF current ele in arr is equal to current ele in brr
	        // then increase the count and erase those elements.
	        // Also decrement the arr size as we erase vector size.
	        // ELSE just rotate the array once and increment the count.
	        if (arr[0] == brr[0]){
	            count++;
	            n--;
	            arr.erase(arr.begin());
	            brr.erase(brr.begin());
	        }
	        else{
	            // 
	            RotateArr(arr);
	            count++;
	        }
	        if (arr.size()<=0) return count;
	    }
	    return count;
    }
};
