// Approach 1: Using prefix and suffix array
// T.C = O(n)
// S.C = O(1)
// Logic:- We simply take prefix and suffix array and get the product of each element in that order.
// How this works?
// Since we are taking product from one end to another we know there will be a moment when either pref or suff will be having max produc,
// so we simply store max result in each iteration.
// Now there will be the case when we may encounter 0 in element, in this case we need to set pref or suff(whichever encountered 0) as 1 so that we can continue.
long long maxProduct(vector<int> &arr) {
    long long pref=1, suff=1, ans=INT_MIN;
    int n = arr.size();
    
    for (int i=0; i<n; i++){
        if (pref == 0) pref = 1;
        if (suff == 0) suff = 1;
        pref *= arr[i];
        suff *= arr[n-i-1];
        
        ans = max(max(pref,suff), ans);
    }
    return ans;
}

///////////////////////////////////////////////////////////
// Approach 2: Using Kadane's Algorithm
