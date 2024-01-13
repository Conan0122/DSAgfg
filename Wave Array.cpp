// T.C = O(n)
// S.C = O(1)
class Solution{
    public:
    void convertToWave(int n, vector<int>& arr){
        int i=0, j=1;
        if (n==1) return;
        
        while (j<n){
            if (arr[j]>arr[i]){
                swap(arr[i++],arr[j++]);
            }
            if (arr[j]<arr[i] && j<n){
                swap(arr[i],arr[j]);
            }
            i++,j++;
        }
    }
};
