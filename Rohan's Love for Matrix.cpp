// T.C = O(n)
// S.C = O(1)
// We need to find a[0][1] after power n times matrix multiplication.
// a = {[1 1],[1 0]};
// a^2 = {[2 1],[1 2]};
// a^3 = {[3 2],[2 1]};
// a^4 = {[5 3],[3 2]};
// a is a matrix and here we can see that at every a[0][1] position the pattern is of fibonacci series.
// So just perform fibonacci series n-2 times(n-2 since we know one operation is already performed in problem itself and next 2 is performed will result in 1 only),
// in simple words fibo series goes like this: 0 1 1 2 3 5 8 13......
// Here we can see first 2 numbers are 1 only so we skip those 2 times cuz we will get 2 in next matrix multiplication which is 4rd num in fibo.
int firstElement(int n) {
    if (n==1 || n==2) return 1;
    int ans=1, prev=1, a=1, mod = 1e9+7;
    
    for (int i=0; i<n-2; i++){
        a = ans;
        ans = (ans+prev)%mod;
        prev = a;
    }
    return ans;
}
