// T.C = O(n+m) 
// S.C = O(m) , m = length of pattern, n = length of the text.
class Solution
{
    // Function that provides lps of string.
    void getLps(string s, vector<int>&v){
        int i=0, j=1, n=s.size();
        
        while (j<n){
            if (s[i]==s[j]){
                v[j] = i+1;
                i++,j++;
            }
            else{
                if (i==0){
                    v[j]=0;
                    j++;
                }
                else{
                    i = v[i-1];
                }
            }
        }
    }
    
    public:
        vector <int> search(string pat, string txt)
        {
            int first=0, second=0, n=txt.size();
            vector<int>v;
            vector<int>lpsv(pat.size(),0);
            getLps(pat,lpsv);
            
            while (first<n){
                if (pat[second]==txt[first]){
                    first++,second++;
                }
                else{
                    if (second==0){
                        first++;
                    }
                    else{
                        second = lpsv[second-1];
                    }
                }
                // Keep checking for the case when second is equal to pattern string's size.
                // The moment it gets equal push the first-second+1 valu in ans vector and assign second to lps[second-1].
                if (second>=pat.size()){
                    v.push_back(first-second+1);
                    second=lpsv[second-1];
                }
            }
            return v;
        }
};
