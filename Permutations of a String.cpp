// Approach: Using set to return only unique permutations.
void solve(int i, string &s, set<string> &st, int n){
    if (i==n){
        st.insert(s);
        return;
    }
    
    for (int j=i; j<n; j++){
        swap(s[i], s[j]);      // First swao
        solve(i+1, s, st, n);  // Then move to next index and solve it.
        swap(s[i], s[j]);      // Now undo the last swap
        solve(i+1, s, st, n);  // Move to next index and solve it.
    }
}

vector<string> findPermutation(string &s) {
    sort(s.begin(), s.end());
    
    vector<string> ans;
    int n = s.size();
    set<string> st;
    
    solve(0, s, st, n);
    
    for (auto i:st) ans.push_back(i);
    
    return ans;
}
