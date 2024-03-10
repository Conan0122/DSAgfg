// T.C = O(n*n)
// S.C = O(1)
// Brute force approach
int celebrity(vector<vector<int> > &M, int n) 
    {
        if (n==1) return 0;
        int ans=-1;
        
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (M[i][j] == 1){
                    break;
                }
                else if (j==n-1){
                    ans = i;
                }
            }
        }
        
        for (int i=0; i<n; i++){
            if (M[i][ans] == 0 && i!=ans){
                return -1;
            }
        }
        return ans;
    }
// ---------------------------------------------------------------------------
// T.C = O(n)
// S.C = O(1)
// Using two pointer approach: first store possible cele. in left variable.
// Then use another loop to check if everyone in that column knows the cele,
// but at the same time also check whether that row person knows anyone or not, IF row person doesn't know anyone but column person knows that person,
// then we know that left is the celebrity.
int celebrity(vector<vector<int> >& M, int n) 
    {
        int left=0, right=n-1;
        
        while (right>0){
            if (M[left][right]==1){
                left++;
            }
            else{
                right--;
            }
        }
        // Now we know left is at possible celebrity's index
        // Iterate in possible celev column and row,
        // and check if every person in row knows no one 
        // but every person in column knows that person.
        for (int j=0; j<n; j++){
            if (left==j) continue;
            if (M[left][j] == 1 || M[j][left] == 0) return -1;
        }
        return left;
    }

// ---------------------------------------------------------------------
// We can also solve this using stack in T.C = O(n) and S.C = O(n)
  
