// Approach: Backtracking
void solve(int idx, string &s, string &temp, vector<string> &ans){
    // Store the temp in answer and return when index is out of array range
    if (idx == s.size()){
        ans.push_back(temp);
        return;
    }

    // Logic: We nned two temp, one with space and another with no space.
    // Why? Bacause we want to recurse for left and right tree (left = include space, right = don't include space)
    string space_temp = temp + " " + s[idx];
    // Go for left which includes space first
    solve(idx+1, s, space_temp, ans);

    // Now go for right which doesn't include space hence we will use temp with no space.
    temp += s[idx];
    solve(idx+1,s, temp, ans);
    // Now pop back last insertion of tmep in right tree as we go back
    temp.pop_back();
}

vector<string> permutation(string s) {
    vector<string> ans;
    // We need to include first character as it is since it won't have any spaces before it.
    string temp = "";
    temp += s[0];
    solve(1, s, temp, ans);
    
    return ans;
}
