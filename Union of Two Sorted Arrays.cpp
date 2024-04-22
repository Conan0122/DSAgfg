// T.C = O((n+m)log(n+m)), where n is size of arr1 and m is size of arr2. And inserting in set takes O(logn) and for n insertion it takes nlogn.
// S.C = O(2*(n+m)), since we are using 2 sets for inserting element
// Using Sets: Not a good approach as compared to two pointer approach which is efficient.
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    set<int>s;
    vector<int>ans;
    
    for (int i=0; i<n; i++) s.insert(arr1[i]);
    for (int i=0; i<m; i++) s.insert(arr2[i]);
    for (auto i:s) ans.push_back(i);
    
    return ans;
}
