// T.C = O(n)
// S.C = O(n)
// Logic: Just keep on storing prefix sum till i in unordered map.
// Before that make sure to check if sum already exist in map or not, if it exist then we know we got 0 here.
// Keep checking for sum value in each iteration if it gets 0 then store it in ans directly.
// Logic works because we know if x(prefix sum) is appeared again in prefix sum then we know that whole is 0 except that first x.
// 1  0  -4  3  1  0
// 1  1  -3  0  1  <- Prefix sum
// see the last 1 we got, this means that previously when we got 1 after that everything's sum is 0.
// We can clarify that, values after previous one are: 0  -4  3  1  0
// if we add we get 0 only.
int maxLen(vector<int>& arr, int n) {
  unordered_map<int,int> ump;
  int sum=0, ans=INT_MIN;
  
  for (int i=0; i<n; i++){
    sum += arr[i];
    
    if (sum==0) ans = i+1;
    else if (ump.find(sum) != ump.end()){
        ans = max(ans, i-ump[sum]);
    }
    else ump[sum]=i;
  }
  
  return ans==INT_MIN? 0:ans;
}
