// Approach: Using extra space(maps)
// T.C = O(n^2)
// S.C = O(n)
bool findTriplets(vector<int> &arr) {
    unordered_map<int,int>mp;
    int n = arr.size();
    
    for(int i=0; i<n; i++) mp[arr[i]] = i;
    
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            int target = (arr[i]+arr[j]) * -1;
            if (mp.count(target) && mp[target] != i && mp[target] != j){
                return true;
            }
        }
    }
    return false;
}

/////////////////////////////////////////////////////////////////////////
// Approach: Using Two pointer
// T.C = O(n^2 + nlogn)
// S.C = O(1)
// Logic: Sort the array
// Fix first element and for next two element keep two pointer one at fixed element +1 and another at last element.
// Now keep on increasing the first pointer if total of (fixed elem + low pointer + high pointer) is more than 0 ele decrease high pointer.
bool findTriplets(vector<int> &arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    
    for (int i=0; i<n; i++){
        int a = i+1, b = n-1;
        
        while (a < b){
            if (arr[i]+arr[a]+arr[b] == 0) return true;
            else if (arr[i]+arr[a]+arr[b] > 0) b--;
            else a++;
        }
    }
    return false;
}



