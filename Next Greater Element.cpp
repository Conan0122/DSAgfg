// T.C = O(n)
// S.C = O(n)
class Solution
{
    public:
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long>ans(n,-1);
        stack<long long>s;
        
        s.push(arr[n-1]);
        int i = n-2;
        
        while (i>=0) {
            if (s.empty()){
                ans[i] = -1;
                s.push(arr[i--]);
                continue;
            }
            
            if (s.top() > arr[i] ){
                ans[i] = s.top();
                s.push(arr[i--]);
            }
            else{
                s.pop();
            }
        }
        return ans;
    }
};
