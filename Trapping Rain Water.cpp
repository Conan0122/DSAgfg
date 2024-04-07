// T.C = O(n)
// S.C = O(n)
// Using two arrays to store each index's left max and right max.
// First store left and right max of each index i in new arrays.
// Now just subtract the minimum of right max and left max of i index with i building.
// Increment the resultant value in ans variable.
//// WE just need to know what's max building in each side of ith index(for each building), using this we can get the water that can be trapped in there.
long long trappingWater(int arr[], int n){
    int larr[n], rarr[n];
    int lmax=arr[0], rmax=arr[n-1];
    long long ans=0;
    
    for (int i=0; i<n; i++){
        if (arr[i]>lmax){
            lmax = arr[i];
        }
        larr[i]=lmax;
    }
    
    for (int i=n-1; i>=0; i--){
        if (arr[i]>rmax){
            rmax = arr[i];
        }
        rarr[i] = rmax;
    }
    
    for (int i=0; i<n; i++){
        if (larr[i] < rarr[i]){
            ans += larr[i]-arr[i];
        }
        else if (larr[i] >= rarr[i]){
            ans += rarr[i]-arr[i];
        }
    }
    
    return ans;
}
