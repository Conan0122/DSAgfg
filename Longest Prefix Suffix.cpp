// T.C = O(n)
// S.C = O(n)
// Using KMP algorithm
class Solution{
  public:		
	int lps(string s) {
	    int n=s.size(), i=0,j=1;
	    vector<int>lpsV(n,0);
	    
	    while (j<n){
          // IF string at i and j index are same then put i+1 in lps array at j index and move both i and j.
          // ELSE check
          //    IF i is at 0 index then simply put 0 in lps array at index j and move j forward.
          //    ELSE put element lps[i-1] at i index.
	        if (s[i]==s[j]){
	            lpsV[j] = i+1;
	            i++, j++;
	        }
	        else{
	            if (i==0){
	                lpsV[j]=0;
	                j++;
	            }
	            else{
                    i = lpsV[i-1];
	            }
	        }
	    }
      // Return what's in last index of lps array.
	    return lpsV[n-1];
	}
};
