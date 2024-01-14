// T.C = O(n)
// S.C = O(n)
class Solution {
  public:
    int candyShop(int n, vector<int> &candies) {
        int sum=0;
        
        if (n==1) return candies[0];
        unordered_map<int,int>m;
        
        for (int i=0; i<n; i++){
            if (m[candies[i]]>0){
                continue;
            }
            sum += candies[i];
            m[(candies[i])]++;
        }
        return sum;
    }
};
