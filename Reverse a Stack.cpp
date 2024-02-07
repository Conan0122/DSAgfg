// T.C = O(n*n)
// S.C = O(1)
// Using revursion
class Solution{
    void InsertAtBot(stack<int> &s, int num){
        // IF stack is empty, push the num to stack.
        // ELSE remove top and call this func recursively.
        if (s.empty()){
            s.push(num);
            return;
        }
        
        int val = s.top();
        s.pop();
        
        InsertAtBot(s,num);
        // Push removed val(which was top element) in stack after returning from recursive func.
        s.push(val);
    }
    
public:
    void Reverse(stack<int> &St){
        if (St.empty()) return;
        
        int t = St.top();
        St.pop();
        // Reverse remaining stack and then insert the top at the bottom of the stack.
        Reverse(St);
        InsertAtBot(St, t);
    }
};
