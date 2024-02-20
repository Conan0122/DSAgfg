// T.C = O(n)
// S.C = O(k)
// Using multiset and sliding window.
// First, insert window sized elements in multiset.
// Now maintain that window and move forward in arr with the same sized window while pushing last ele of multiset into vector as a result.
// We keep on erasing the first element of window and move window forward.
vector <int>n max_of_subarrays(int *arr, int n, int k)
    {
        multiset<int>s;
        vector<int>ans;
        int i=0, j=0;
        // Maintain first k sized window.
        for (; j<k; j++){
            s.insert(arr[j]);
        }
        j--;
        // Now just remove the first element of previous window and insert new element of window in multiset.
        while (j<n){
            ans.push_back(*s.rbegin());
            auto it = s.find(arr[i]);
            s.erase(it);
            i++, j++;
            s.insert(arr[j]);
        }
        return ans;
    }
