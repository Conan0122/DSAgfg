// T.C = O(n)
// S.C = O(n)
class Solution
{
    public:
    bool ispar(string x)
    {
        int n = x.size();
        if (n==1) return false;
        stack<char>s;
        for (int i=0; i<n; i++) {
            if ( (x[i]=='[') || (x[i]=='(') || (x[i]=='{') ){
                s.push(x[i]);
            }
            else{
                if (s.empty()) return false;
                if ( (x[i]==')') && (s.top()=='(') ){
                    s.pop();
                }
                else if ( (x[i]=='}') && (s.top()=='{') ){
                    s.pop();
                }
                else if ( (x[i]==']') && (s.top()=='[') ){
                    s.pop();
                }
                else{
                    return false;
                }
            }
        }
        if (s.empty()) return true;
        return false;
    }
};
