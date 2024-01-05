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

// Another way of solving this is using bit manipulation.
// T.C = O(n)
// S.C = O(1)
class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        int res=0;
        // Get the sum of every element at eaach bit position.
        // Example: 3,6,3,3 => 3 in binary = 011  and 6 in binary = 110,
        // At first position from right count the set bits in each element. In this case we get following:-
        // 0  1  1
        // 1  1  0
        // 0  1  1
        // 0  1  1
        //---------
        // 1  4  3
        for (int i=0; i<32; i++){
            int sum = 0;
            for (int j=0; j<N; j++){
                // Now to get the if current bit position is set bit or not, we have to AND currrent element with current bit position.
                // We know our current element is arr[j] and current bit position is (1<<i).
                if (arr[j]&(1<<i)){
                    sum++;
                }
            }
            // Now we know that the position with set bits not a multiple of 3 is the set bits of unique number(single number).
            if (sum%3 == 1){
                res = res | (1<<i);
            }
        }
        return res;
    }
};
