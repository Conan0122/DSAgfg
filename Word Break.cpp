// Appraoch: Using recursion.

bool solve(int idx, int n, string &s, unordered_set<string> &dict){
    if (idx == n){
        return true;
    }
    if (dict.find(s) != dict.end()) return true;
    
    string temp = "";
    for(int i=idx; i<n; i++){
        temp += s[i];
        
        if (dict.find(temp) != dict.end()){
            if (solve(i+1, s.size(), s, dict)) return true;
        }
    }
    return false;
}

int wordBreak(int n, string s, vector<string> &dictionary) {
    unordered_set<string> dict;
    
    for(auto i:dictionary) dict.insert(i);
    
    return solve(0, s.size(), s, dict);
}
