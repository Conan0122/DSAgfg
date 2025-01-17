// Approach: Recurison- TLE
int solve(int idx, vector<int> &arr, int n){
    if (idx>=n) return 0;
    
    int left = arr[idx] + solve(idx+2, arr, n);
    int right = solve(idx+1, arr, n);
    return max(left, right);
}

int findMaxSum(vector<int>& arr) {
    int n = arr.size();
    return solve(0, arr, n);
}

////////////////////////////////////////////////////////////
// Approach: DP- Memoization
int solve(int idx, vector<int> &arr, vector<int> &dp, int n){
    if (idx>=n) return 0;
    
    if (dp[idx]!=-1)return dp[idx];
    
    int left = arr[idx] + solve(idx+2, arr, dp, n);
    int right = solve(idx+1, arr, dp, n);
    return dp[idx] = max(left, right);
}

int findMaxSum(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n,-1);
    return solve(0, arr, dp, n);
}
