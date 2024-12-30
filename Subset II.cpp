void solve(int i, vector<int>& nums, set<vector<int>> &st, vector<int> &temp, int n){
    if (i == n){
        st.insert(temp);
        return;
    }
    
    temp.push_back(nums[i]); // insert karo
    solve(i+1, nums, st, temp, n);    // Fir move on kar do
    temp.pop_back();  // Wapas aate time recent wale ko nikal do
    solve(i+1, nums, st, temp, n);  // Ab bina insert kare run karo (Concept of take or not take)
}

vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    set<vector<int>> st;
    vector<int> temp;
    
    solve(0, nums, st, temp, n);
    for (auto i:st) ans.push_back({i});
    
    return ans;
}
