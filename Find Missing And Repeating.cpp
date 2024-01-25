// T.C = O(n)
// S.C = O(1)
// Using sorting.
// First sort the array by just swapping arr[i] and arr[arr[i]-1].
// Swap only when index doesnt matches. What we wanna achieve is that ever index should have it's proper element.
// For example:- for index 0 element should be 1, for index 3 element should 2 and so on.
// After sorting we will be left with two index which has same element and also the duplicated element is in place of the missing element.
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int repeat=0, missing=0, i=0;
        
        // Sort using index
        while (i<n) {
            if (i == (arr[i]-1)){
                i++;
            }
            else{
                swap(arr[i], arr[arr[i]-1]);
                if (arr[i] == arr[arr[i]-1]) i++;
            }
        }
        
        // Check if any index-1 != arr[i].
        // By this we can find out our missing and repeated element.
        for (int j=0; j<n; j++){
            if (arr[j]!=j+1){
                repeat = arr[j];
                missing = j+1;
            }
        }
        return {repeat,missing};
    }
};

// Another efficient way of solving this problem is by marking every visited element with -ve such that in next traversal we would know which are the missing and repeated elements.
