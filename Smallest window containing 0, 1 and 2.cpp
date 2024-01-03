// T.C = O(n)
// S.C = O(1)
class Solution {
  public:
    int smallestSubstring(string S) {
        int n = S.size();
        int i=0, zero=-1, one=-1, two=-1, ans=INT_MAX;
        // If string size is less than 3 then we are sure that we won't get window size containing 0,1 and 2.
        // So return -1.
        if (n < 3) return -1;
        // Now iterate through the characters in a string and keep updating 0,1 and 2 until we get all three of them.
        // The moment we get all three of them, check if their length is min of all the length we received till now.
        // Store the min length substring in ans variable and continue looking for another substring with 0,1 and 2.
        while (i<n){
            if (S[i] == '0'){
                zero = i;
            }
            else if (S[i] == '1'){
                one = i;
            }
            else if (S[i] == '2'){
                two = i;
            }
            
            if (zero>=0 && one>=0 && two>=0){
                int mx = max(zero, max(one, two));
                int mn = min(zero, min(one, two));
                
                ans = min(mx-mn+1, ans);
            }
            i++;
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};
