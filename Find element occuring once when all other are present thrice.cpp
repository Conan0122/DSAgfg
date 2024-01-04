// T.C = O(n)
// S.C = O(n)
// Using unordered map
class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        int ans=0;
        unordered_map<int,int>m;
        
        for (int i=0; i<N; i++){
            m[arr[i]]++;
        }
        
        for (auto i:m){
            if (i.second == 1){
                ans = i.first;
            }
        }
        return ans;
    }
};

// Another way of solving this is using bit manipulation
