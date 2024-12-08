// Just check for start and end of each row and compare it for overlapping conditions.
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        int start = arr[0][0], end = arr[0][1];
        
        for (int i=1; i<n; i++){
            // IF overlapping then add max end among existing end and ith row's end.
            if (arr[i][0] >= start && arr[i][0] <= end){
                if (arr[i][1] > end) end = arr[i][1];
            }
            // ELSE push start and end to ans vector and update start and end pointer.
            else{
                ans.push_back({start, end});
                start= arr[i][0], end= arr[i][1];
            }
        }
        // Insert remaining start and end element into the vector.
        ans.push_back({start, end});
        return ans;
    }
};
