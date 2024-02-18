// T.C = O(n)
// S.C = O(n)
// Using queue: Push first half in new queue and then keep pushing one ele from main queue and another ele from new queue into the result vector.
class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        vector<int> v;
        queue<int> myq;
        int n= q.size();
        int i=0;
        
        while (!q.empty()){
            if (i<n/2){
                myq.push(q.front());
                q.pop();
                i++;
            }
            else{
                v.push_back(myq.front());
                myq.pop();
                v.push_back(q.front());
                q.pop();
            }
        }
        return v;
    }
};
/////////////////////////////////////////////////////////////////////////////
// T.C = O(n)
// S.C = O(1)
// Without using extra space: First push ele from queue in even index of result vector.
// When index count is > n assign index to 1 and start pushing queue ele to vector again until queue is empty.
// Also keep incrementing index by 2 after every iteration.
class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        int n = q.size();
        vector<int> v(n,-1);
        int index=0;
        
        while (!q.empty()){
            if (index >= n) index = 1;
            v[index] = q.front();
            q.pop();
            index += 2;
        }
        return v;
    }
};
