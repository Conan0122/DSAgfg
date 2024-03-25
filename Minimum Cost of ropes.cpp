// T.C = O(nlogn)
// S.C = O(n)
// Using priority queue: store elements in priority queue(lowest element to be given highest priority) so that we can always get lowest element first in priority.
// Keep adding top elements and store it in result variable.
long long minCost(long long arr[], long long n) {
    priority_queue<long long, vector<long long>, greater<long long>>pq;
    long long res=0;
    
    for (int i=0; i<n; i++){
        pq.push(arr[i]);
    }
    
    while (pq.size()>1){
        long long sum=0;
        long long n1 = pq.top();
        pq.pop();
        long long n2 = pq.top();
        pq.pop();
        sum = n1+n2;
        res += sum;
        pq.push(sum);
    }
    return res;
}
