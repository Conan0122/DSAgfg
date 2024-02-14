// T.C = O(n)
// S.C = O(n)
// Using stack
class Solution
{
    public:
    int evaluatePostfix(string S)
    {
        stack<int>st;
        int num1=0, num2=0, n=S.size(), val=0;
        for (int i=0; i<n; i++){
            if (S[i]>='0' and S[i]<='9'){
                val = S[i]-'0';
                st.push(val);
                continue;
            }
            num1 = st.top();
            st.pop();
            num2 = st.top();
            st.pop();
            
            if(S[i]=='+'){
                val = num2 + num1;
            }
            else if (S[i]=='-'){
                val = num2 - num1;
            }
            else if (S[i]=='*'){
                val = num2 * num1;
            }
            else if (S[i]=='/'){
                val = num2 / num1;
            }
            st.push(val);
        }
        return st.top();
    }
};
