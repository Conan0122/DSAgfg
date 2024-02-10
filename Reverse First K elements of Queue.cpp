// T.C = O(n)
// S.C = O(k)
// Using stack, insert k elements from queue in stack and then push stack element in queue while removing them from queue.
// Now push front of queue in queue itself until our n-k get 0, where n is size of queue initially.
class Solution
{
    public:
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int>s;
        int n = q.size();
        
        for (int i=0; i<k; i++){
            s.push(q.front());
            q.pop();
        }
        
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        
        int size = n-k;
        while(size>0){
            q.push(q.front());
            q.pop();
            size--;
        }
        return q;
    }
};
