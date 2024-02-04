// T.C = O(n)
// S.C = O(n)
class Solution{
public:
    stack<int> insertAtBottom(stack<int> St,int X){
        stack<int>s;
        
        while (!St.empty()){
            int t = St.top();
            St.pop();
            s.push(t);
        }
        St.push(X);
        
        while (!s.empty()){
            int t = s.top();
            s.pop();
            St.push(t);
        }
        return St;
    }
};
