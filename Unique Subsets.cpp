// Approach: We need to use "take or not take" method and have to store each generated subset in set using which we will store only unique subset in ans vector.
void solve(vector<int> &arr, int idx, vector<int> &temp, set<vector<int>> &st, int n){
    if (idx == n){
        st.insert(temp);
        return;
    }
    
    temp.push_back(arr[idx]);          // Store first element in temp vector.
    solve(arr, idx+1, temp, st, n);    // Now run recursion on next element. (TAKE)
    temp.pop_back();                   // Now remove last pushed element from temp vector.
    solve(arr, idx+1, temp, st, n);    // Now run recursion for next element without pushing current index in temp. (NOT TAKE)
}    

vector<vector<int> > AllSubsets(vector<int> arr, int n)
{
    sort(arr.begin(), arr.end());  // First sort whole vector
    vector<vector<int>> ans;
    vector<int> temp;
    set<vector<int>> st;          // Use set to check unique elment only
    solve(arr, 0, temp,  st, n);
    
    for(auto i:st){ ans.push_back(i); }  // Push back unique vector of int from set to ans vector
    sort(ans.begin(), ans.end());        // Sort the ans to get answer in lexicographical order.
    
    return ans;
}
