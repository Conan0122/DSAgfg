// T.C = o(n)
// S.C = O(1)
// First check if first char is "-", if it is then start the loop from 1 index else start from 0(default).
// Now subtract each char with char '0' which basically converts char to int without changing it's value.
class Solution{
  public:
    int atoi(string s) {
        int n = s.size();
        int ans=0, i=0;
        bool isNeg = false;
        if ( s[0]=='-' ) isNeg = true;
        if (isNeg) i=1;
        
        for (; i<n; i++){
            if ( s[i]>='0' && s[i]<='9' ){
                int num = s[i] - '0';
                ans = (ans*10) + num;
            }
            else{
                return -1;
            }
        }
        
        if (isNeg) return (ans*-1);
        return ans;
    }
};
