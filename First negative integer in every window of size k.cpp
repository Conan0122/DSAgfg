// T.C = O(n)
// S.C = O(k)
// Using sliding window and queue.
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    int i=0, j=0;
    vector<long long>ans;
    queue<int>q;
    // Maintain first k sized window.
    for (; j<K; j++){
        if (A[j]<0) q.push(A[j]);
    }
    j--;
    // Continue along with k sized window and keep storing any -ve int in queue.
    // IF queue is empty then we know we don't have -ve element and thus we need to push 0 in result vector.
    // ELSE IF queue is not empty then push front of queue in result vector.
    // Now check if current ith element is -ve or not,
    // IF it's -ve then pop element from queue.
    // Increment both i and j by 1 and check if new jth element is -ve,
    // IF it's -ve then push it in queue.
    while (j<N){
        if (q.empty()) ans.push_back(0);
        else if (!q.empty()) ans.push_back(q.front());
        
        if (A[i]<0) q.pop();
        i++, j++;
        if (A[j]<0) q.push(A[j]);
    }
    return ans;
}
