// Approach: Using Unordered map.
// T.C = O(n)
// S.C = O(n)
string secFrequent (string arr[], int n)
{
    unordered_map<string, int> ump;
    string ans = "";
    
    for (int i=0; i<n; i++) ump[arr[i]]++;
    
    int firstMost=INT_MIN, secMost=0;
    for (auto i:ump){
        if (i.second>firstMost){
            secMost = firstMost;
            firstMost = i.second;
        }
        if (i.second<firstMost && i.second>secMost) secMost = i.second;
    }
    
    for (auto i: ump){
        if (i.second == secMost){
            ans = i.first;
            break;
        }
    }
    return ans;
}
