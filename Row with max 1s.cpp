// T.C = O(n^2)
// S.C = O(1)

// Brute force approach (Accepted)
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int count=-1, maxcount=-1, ans=-1;
	    
	    for (int i=0; i<n; i++){
	        for (int j=0; j<m; j++){
	            if (arr[i][j] == 1){
	                count = m-j;
	            }
	            
	            if (count > maxcount){
	                ans = i;
	                maxcount = count;
	            }
	        }
	    }   
	    return ans;
	}
};
