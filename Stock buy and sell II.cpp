// T.C = O(n)
// S.C = O(1)

int stockBuyAndSell(int n, vector<int> &prices) {
    int ans=0;
    
    for (int i=1; i<n; i++){
        if (prices[i] - prices[i-1] > 0 ){
            ans += prices[i] - prices[i-1];
        }
    }
    
    return ans;
}
