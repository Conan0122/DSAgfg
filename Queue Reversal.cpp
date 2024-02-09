// T.C = O(n)
// S.C = O(n)
// Using stack
class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        stack<int> s;
        while (!q.empty()){
            int f = q.front();
            q.pop();
            s.push(f);
        }
        
        while(!s.empty()){
            int t = s.top();
            s.pop();
            q.push(t);
        }
        return q;
    }
};
////////////////////////////////////////////////////////////////
// T.C = O(n)
// S.C = O(n), recursive call stack
// Using recursion
class Solution
{
    void myRev(queue<int> &q){
        if (!q.empty()){
            int ele = q.front();
            q.pop();
            myRev(q);
            q.push(ele);
        }
    }
    
    public:
    queue<int> rev(queue<int> q)
    {
        myRev(q);
        return q;
    }
};
