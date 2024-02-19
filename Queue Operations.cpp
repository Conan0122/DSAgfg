// T.C = O(n*m), because we have to traverse whole queue each time to find a frequency of k.
// S.C = O(n)
// Function to insert element into the queue
    void insert(queue<int> &q, int k){
        q.push(k);
    }
    
    // Function to find frequency of an element
    int findFrequency(queue<int> &q, int k){
        int freq = 0;
        queue<int>myq;
        myq=q;
        
        while (!q.empty()){
            int t = q.front();
            if (t==k){
                freq++;
            }
            q.pop();
        }
        q=myq;
        if (freq==0) return -1;
        return freq;
    }
