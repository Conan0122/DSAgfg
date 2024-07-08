// Using recursion: 
// Keep checking for valid path in left, right, up, down from current index.
// Next path is valid only if it contains 1 and not 0.
// After next path validation, check for next valid path from that next path.
// While moving to any path change it to 1 so that we don't move back to same path again from next path.
// When rat has reached destination then after moving back to previous path index change back the path to again 1,
// This is because we might need this path again for other paths.

// So CHANGE current element to 0 first and then go for finding valid path,
// and while coming back keep CHANGING them back to 1 so that we can use that path for other valid paths as well.
void solve(int row, int col, string& pathstr, vector<vector<int>> &m, int n, vector<string>& ans){
  // Base Condition
  if (row<0 || col<0 || row>n-1 || col>n-1 || m[row][col]==0) return;
  if (row==n-1 && col==n-1){
      ans.push_back(pathstr);
      return;
  }
  
  if ( (row>=0 && col <=n-1) && (row<=n-1 && col>=0) ){
      m[row][col] = 0;
      
      // Down
      pathstr.push_back('D');
      solve(row+1, col, pathstr, m, n, ans);
      pathstr.pop_back();
      
      // Right
      pathstr.push_back('R');
      solve(row, col+1, pathstr, m, n, ans);
      pathstr.pop_back();
      
      // left
      pathstr.push_back('L');
      solve(row, col-1, pathstr, m, n, ans);
      pathstr.pop_back();
      
      // Up
      pathstr.push_back('U');
      solve(row-1, col, pathstr, m, n, ans);
      pathstr.pop_back();
      
      m[row][col] = 1;
  }
}

vector<string> findPath(vector<vector<int>> &m, int n) {
  vector<string> ans;
  string pathstr = "";
  
  solve(0, 0, pathstr, m, n, ans);
  
  return ans;
}
