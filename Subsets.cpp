// Approach: Backtracking
vector<vector<int>> ans;
void solve(vector<int> &arr, vector<int> &temp, int i, int n){
    if (i==n){
        ans.push_back(temp);
        return;
    }
    // Skip duplicates
    if (i>0 && arr[i] == arr[i-1]){
        solve(arr, temp, i+1, n);
    }
    else{
        temp.push_back(arr[i]);    // Include the current element
        solve(arr, temp, i+1, n);  // Go for the next index
        temp.pop_back();           // Backtrack
        solve(arr, temp, i+1, n);  // Skip the current element
    }
}

vector<vector<int>> subsets(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());  // Sort the array so that we get duplicate elements adjacently and thus making it easy to skip it.
    vector<int> temp;
    solve(arr, temp, 0, n);
    
    sort(ans.begin(), ans.end());
    return ans;
}
