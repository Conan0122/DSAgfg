// T.C = O(n)
// S.C = O(1)
// Using the concept of gray to binary conversion.
int grayToBinary(int n)
{
    int ans=0;
    while (n){
        ans ^= n;
        n >>= 1;
    }
    return ans;
}
