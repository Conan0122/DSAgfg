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
                // Now to get the current bit position is set bit or not, we have to AND current element with current bit position.
                // We know our current element is arr[j] and current bit position is (1<<i).
                if (arr[j]&(1<<i)){
                    sum++;
                }
            }
            // Now we know that the position with set bits not a multiple of 3 is the set bits of unique number(single number).
            // Whichever bit position's sum is not a multiple of 3 we need to know it's bit position and add it to our result variable.
            if (sum%3 == 1){
                // Initially res will be assigned with 0 so we just have to OR current bit position with res variable to know which bit position has set bit,
                // and bbased on that res gets updated.
                // Example for 1  1  0 :- we know that second position and third position haas set bit,
                // so we just OR it with (1<<i) and check which bit position is set.
                res = res | (1<<i);
            }
        }
        return res;
    }
};
