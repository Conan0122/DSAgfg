// T.C = O(n*m)
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

// T.C = O(n+m)
// S.C = O(1)
// Two pointer approach (Accepted)

// This approach simple- Keep one pointer(i) for iterating row and other pointer(j) for coloumn.
// Start i pointer from arr[0][0] till i< n and j pointer from arr[0][m-1] till j <= 0.
// Now keep decrement j untill you get 0 and keep updating i as well. The moment you get 0, increment i and check if it equals to 1.
// Keep incrementing i untill we get another 1.
// return i as the answer.
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int ans=-1, i=0, j=m-1;
	    
	    while (i<n && j>=0){
	        if (arr[i][j] == 1){
	            j--;
	            ans = i;
	        }
	        else {
	            i++;
	        }
	    }
	    return ans;
	}
};
