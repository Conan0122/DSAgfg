// T.C = O(n)
// S.C = O(1)
// Using sliding window approach.
class Solution
{
    public:
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        int i=0, j=0, sum=arr[0];
        // IF n == 1 and the only element in array is equal to s then we know that subarray would be {1,1}.
        if (n==1 && arr[0]==s) return {1,1};
        while (i<n && j<n) {
            // If sum is equal to given s and i <= j, then we can simply return i+1,j+1.
            if (sum == s && i<=j){
                return {i+1,j+1};
            }
            else if (sum <= s){
                j++;
                sum += arr[j];
            }
            else if (sum > s){
                i++;
                sum -= arr[i-1];
            }
        }
        return {-1};
    }
};
