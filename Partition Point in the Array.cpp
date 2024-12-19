// Approach: Using prefix max and suffix min.
// Store left max in one array and store right min in another array.
// Now compare each ith element except first and last element since we need a case where pre[i-1] < arr[i] < suf[i+1]
int FindElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> pre(n), suf(n);

    pre[0] = INT_MIN;
    suf[n-1] = INT_MAX;

    for (int i=1; i<n; i++){
        pre[i] = max(pre[i-1], arr[i-1]);
        suf[n-i-1] = min(suf[n-i], arr[n-i]);
    }
    
    for (int i=0; i<n; i++){
        if(pre[i] < arr[i] && arr[i] < suf[i]){
            return arr[i];
        }
    }
    return -1;
}
