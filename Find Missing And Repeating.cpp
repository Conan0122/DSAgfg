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
/////////////////////////////////////////////////////////////
// Another efficient way of solving this problem is by marking every visited element with -ve such that in next traversal we would know which are the missing and repeated elements.
// Approach 2: Marking visited element with -ve of it.
// T.C = O(n)
// S.C = O(1)
// Logic:- Use indexes as elements and fill up every visited element with -ve of it.
// For example:- [3, 1, 3]
// iteration 1: [3, 1, -3]
// iteration 2: [-3, 1, -3]
// iteration 3: [-3, 1, -3], in this iteration we encounter -ve element so return that element as a repeating element cuz we know it is -ve since we already visited this element before.
// Also, consider index 0 as element 1 and index 1 as element 2 and so on....
// Now for finding missing element it's easy and simple just traverse the array again and look for element which is non -ve(not visited).
// In our example case:- [-3,1,-3]
// index 1 is still +ve so we know we didn't get element 2 in original array and hence this index isn't changed to -ve.
vector<int> findTwoElement(vector<int>& arr) {
    int n = arr.size();
    int repeat=0, missing=0;
    
    // Find repeating
    for (int i=0; i<n; i++){
        if (arr[abs(arr[i])-1] < 0) repeat = abs(arr[i]);
        else{
            arr[abs(arr[i])-1] *= -1;
        }
    }
    
    // Find missing
    for (int i=0; i<n; i++){
        if (arr[i] > 0){
            missing = i+1;
            break;
        }
    }
    return {repeat, missing};
}
