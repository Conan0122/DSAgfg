// T.C = O(n*m)
// S.C = O(1)
// Logic: Just simple appraoch where we first traverse from left to right then top to bottom, then right to left and finally bottom to top.
vector<int> spirallyTraverse(vector<vector<int> > &mat) {
    vector<int> ans;
    int n = mat.size(), m = mat[0].size();
    int top=0, bot=n-1, left=0, right=m-1;
    
    while(top<=bot && left<=right){
        // To traverse from left to right
        for(int i=left; i<=right; i++){
            ans.push_back(mat[top][i]);
        }
        top++;
        
        // To traverse from top to bottom
        for(int i=top; i<=bot; i++){
            ans.push_back(mat[i][right]);
        }
        right--;

        // Make sure to check if condition still satisfies or not.
        // For exmaple: In case of just row or just col matrix we can encounter a situation where we can traverse wither row or col and it will be over with just one traversal,
        // but then we need to make sure other loop don't run or else it will give us unexpected result.
        if (left>right || top > bot) break;
        
        // To traverse from right to left
        for(int i=right; i>=left; i--){
            ans.push_back(mat[bot][i]);
        }
        bot--;
        
        // To traverse from bottom to top
        for(int i=bot; i>=top; i--){
            ans.push_back(mat[i][left]);
        }
        left++;
    }
    return ans;
}
