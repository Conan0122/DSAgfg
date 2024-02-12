// T.C = O(n*n)
// S.C = O(1)
// Iterative approach
class Solution
{
    public long sequence(int N)
    {
        if (N==1) return 1;
        long mod = 1000000007, ans = 0, curr = 1, lastnum = 1;
        
        for (int i=0; i<N; i++){
            for (int j=0; j<=i; j++){
                curr = (curr*lastnum)%mod;
                lastnum++;
            }
            ans = (ans+curr)%mod;
            curr=1;
        }
        return ans;
    }
}

// T.C = O(n*n)
// S.C = O(n), recursive call stack
// Using recursion.
// We just need a track of n given in input, our iteration "i" after multiplication and the first number we have to perform multiplication with.
class Solution
{
    long helper(int n, int i, int lastnum){
        if (i>n) return 0;
        long curr=1, mod = 1000000007;
        
        for (int j=0; j<i; j++){
            curr = (curr*lastnum)%mod;
            lastnum++;
        }
        
        return (curr+ helper(n, i+1, lastnum)%mod);
    }
    
    public long sequence(int N)
    {
        return helper(N, 1, 1);
    }
}
