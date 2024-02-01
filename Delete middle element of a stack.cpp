// T.C = O(n)
// S.C = O(n)
// Store elements in another stack until our top == mid element, and then we pop top element and push our temp stack's elements back in original stack.
class Solution
{
    public:
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        stack<int>myS;
        int mid = sizeOfStack/2;
        
        while (mid>0){
            int a = s.top();
            s.pop();
            myS.push(a);
            mid--;
        }
        s.pop();
        while (!myS.empty()){
            int a = myS.top();
            myS.pop();
            s.push(a);
        }
    }
};
