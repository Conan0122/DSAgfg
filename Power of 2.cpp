// T.C = O(logn)
// S.C = O(1)
// Using bit manipulation. The fact that every power of 2 will have 0 at first bit.
// So we just AND 1 with n and if it's 1 then we know it can't be power of 2 so we return false.
// And we keep on dividing current n with 2 using left shift operator.
class Solution{
    public:
    bool isPowerofTwo(long long n){
        long long num=n;
        
        if (n==1) return true;
        
        while(n>1){
            if ((n&1) == 1) return false;
            n = n>>1;
        }
        
        if (n!=0) return true;
        return false;
    }
};
