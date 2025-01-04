// Approach: Backtracking
void solve(int idx, string &s, string &temp, vector<string> &ans){
    if (idx == s.size()){
        ans.push_back(temp);
        return;
    }
    
    string tempp = temp + " " + s[idx];
    
    solve(idx+1, s, tempp, ans);
    temp += s[idx];
    solve(idx+1, s, temp, ans);
    temp.pop_back();
}

vector<string> permutation(string s) {
    vector<string> ans;
    string temp = "";
    temp += s[0];
    solve(1, s, temp, ans);
    
    return ans;
}
