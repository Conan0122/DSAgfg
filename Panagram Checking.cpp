// T.C = O(n)
// S.C = O(1), as the size of set will always be <= 26(letters in english alphabets).
// Using sets.
// Iterate through string and keep inserting character into set.
class Solution
{
  public:
    bool checkPangram (string s) {
        int n = s.size();
        if (n<26) return false;
        set<char>myS;
        
        for (int i=0; i<n; i++){
            if ( (s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)){
                myS.insert(tolower(s[i]));
            }
        }
        if (myS.size()>=26) return true;
        return false;
    }
};
