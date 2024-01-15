// T.C = O(n)
// S.C = O(1)
// Input:-
//        3
//        aba
// Output:-
//        4
//        Explanation:- Substring with same value as s[0] are: aba,a,ab,a.
// This problem was asked in gfg weekly contest 137.
// We can solve this problem by just counting the number of character in string from a character s[0] which is said to be the value we need to look for in each substring.
// For example: in string "aba" we just have to iterate from first character to last character and look for character which is same as value(which is ASCII of s[0]).
// When we counter any character same as value we count characters from that index to last.
class Solution {
  public:
    int totalCount(int n, string s) {
        int val = int(s[0]), mod=1e9+7;;
        long long count=0;
        
        for (int i=0; i<n; i++){
            if (int(s[i])==val){
                count += (n-i);
            }
        }
        return count%mod;
    }
};
