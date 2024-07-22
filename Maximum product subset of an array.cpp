// T.C = O(n)
// S.C = O(1)
// Logic: Keep count of zero and negatives.
// If num of zeroes are equal to size of array then we know that the 0 is the obvious answer. Ex: [0,0,0,0,0] = 0
// Intuition behind this solution is that we just have to multiply every elements.
// What might change the result is the number of negatives in array.
// If the num of negatives are divisible by 2 then it means that resultant will be in positive,
// Else the resultant will be in negative.
// And as per the problem we need to find max product subset, which means we need it in +ve only.
// To make this -ve result into +ve we can remove max -ve element from resultant ans.
// We can achieve this by tracking max -ve element in array and divide ans by this max negative element.
// For example: arr[] = [-1, -1, -2, 4, 3]
// negMax = -1, zCount = 0, negCount = 3.
// Since the negCount is not divisible by 2 we know that we need to remove one -ve from ans which we got as multiplying every element except 0: -1*-1*-2*4*3 = -24
// We need to remove -ve from element and to remove that we know that one max -ve elements needs to be removed from result.
// Here -1 needs to removed, hence we divide result(-24) from max -ve(-1).
long long int findMaxProduct(vector<int>& arr) {
    long long int ans=1, mod = 1e9+7;
    int i=0, n=arr.size(), zCount=0, negCount=0, negMax=-11;
    
    if (n==1) return arr[0];
    
    for (int i=0; i<n; i++){
        if (arr[i]) ans = (ans*arr[i])%mod;
        
        if (arr[i]==0)zCount++;
        else if (arr[i]<0){
            negCount++;
            negMax = max(negMax, arr[i]);
        }
    }
    // If zeroes are equal to array size OR if zeroes are n-1 and last left element is -ve then we know this results in 0.
    // For e.g, n = 10, zCount = 9, negCount = 1: this results in 0 as it cant produce any max product subset.
    if (zCount==n || (zCount==n-1 && negCount==1)) return 0;
    return negCount%2? ans/negMax : ans;
}
