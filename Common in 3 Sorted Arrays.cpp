// Logic: We can use the fact that all 3 arrays are sorted.
// Just keep one pointer in each arr and keep on comparing elements at index in each array,
// whenever we encounter an element which is less than other array's element we increment that array's pointer.
// We continue this until we reach at the end of any one's array since we know, now no element can be matched.

// Approach 1:
// T.C = O(n)
// S.C = o(1)
// Using bool check to increment i,j,k together whenever the conditions pass.
vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,vector<int> &arr3) {
    vector<int> ans;
    int i=0, j=0, k=0, n1=arr1.size(), n2=arr2.size(), n3=arr3.size();
    
    while (i < n1 && j < n2 && k < n3){
        bool iIncr = false, jIncr = false, kIncr = false;
        if (arr1[i]==arr2[j] && arr1[i]==arr3[k]){
            if (arr1[i-1] != arr1[i]) ans.push_back(arr1[i]);
            i++, j++, k++;
        }
        else{
            if (arr1[i]<arr2[j] || arr1[i]<arr3[k]) iIncr = true;
            if (arr2[j]<arr1[i] || arr2[j]<arr3[k]) jIncr = true;
            if (arr3[k]<arr1[i] || arr3[k]<arr2[j]) kIncr = true;
        }
        if (iIncr) i++;
        if (jIncr) j++;
        if (kIncr) k++;
    }
    return ans;
}
//////////////////////////////////////////////////////////////////////////////
// Approach 2:
// T.C = O(n)
// S.C = o(1)
// Without using bool check to increment i,j,k.
vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,vector<int> &arr3) {
    vector<int> ans;
    int i=0, j=0, k=0, n1=arr1.size(), n2=arr2.size(), n3=arr3.size();
    
    while (i < n1 && j < n2 && k < n3){
        bool iIncr = false, jIncr = false, kIncr = false;
        if (arr1[i]==arr2[j] && arr1[i]==arr3[k]){
            if (arr1[i-1] != arr1[i]) ans.push_back(arr1[i]);
            i++, j++, k++;
        }
        else{
            if (arr1[i] < arr2[j]) i++;
            else if (arr2[j] < arr3[k]) j++;
            else k++;
        }
    }
    return ans;
}
///////////////////////////////////////////////////////////////////////////////
// Approach 3: Using unordered map with O(n) space complexity
