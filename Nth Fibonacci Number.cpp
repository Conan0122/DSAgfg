// Approach: DP- Memoization
// T.C = O(n)
// S.C = O(n)
int fib(int n, vector<int>&dp){
    int mod = 1e9+7;
    if (n<=1) return n;
    
    if (dp[n]!=-1) return dp[n];
    
    dp[n] = (fib(n-1,dp)+fib(n-2,dp)) % mod;
    return dp[n];
}

int nthFibonacci(int n){
    vector<int>dp(n+1,-1);
    return fib(n, dp);
}
