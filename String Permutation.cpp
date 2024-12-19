// Approach: Using backtracking with extra space to mark used character.
// Check if current char is already used, if not then add it in temp string(which we will use to save in vector of string).
// If it is already used then just ignore and let it move to next index.
void solve(string &s,string temp, vector<string> &ans, vector<bool> &used, int n){
      if (temp.size() == n){
          ans.push_back(temp);
          return;
      }
      
      for(int i=0; i<n ; i++){
          if (!used[i]){
              temp.push_back(s[i]);
              used[i] = true;
              solve(s, temp, ans, used, n);
              temp.pop_back();
              used[i] = false;
          }
      }
  }
  
  vector<string> permutation(string S)
  {
      int n = S.size();
      vector<string> ans;
      vector<bool> used(n, false);
      
      solve(S, "" ,ans, used, n);
      sort(ans.begin(), ans.end());
      
      return ans;
  }
