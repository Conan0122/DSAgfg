// T.C = O(n*m)
// S.C = O(1)
int minRow(int n, int m, vector<vector<int>> a) {
    int minR=INT_MAX, ans=1, count=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (a[i][j] == 1) count++;
        }
        if (count<minR){
            ans = i+1;
            minR = count;
        }
        count=0;
    }
    
    if (minR == INT_MAX) return 1;
    return ans;
}
