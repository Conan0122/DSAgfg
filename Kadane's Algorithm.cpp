// Problem: Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.
// T.C = O(n)
// S.C = O(1)

class Solution{
    public:
    long long maxSubarraySum(int arr[], int n){
        long long maxsum=INT_MIN, currsum=0;
        // Keep current sum in "crrsum" and maxsum we ever get in "maxsum".
        for (int i=0; i<n; i++){
            currsum += arr[i];
            // If current element is greater than current sum then we know that current sum is definitely less and
            // we can assign current element in current sum and start fresh sum from current element.
            if (arr[i] > currsum){
                currsum = arr[i];
            }
            // If current sum is max than maxsum then we got new maximum sum subarray,
            // and we can assign it to maxsum.
            if (currsum > maxsum){
                maxsum = currsum;
            }
        }
        return maxsum;
    }
};
