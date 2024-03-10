// T.C = O(n)
// S.C = O(n)
// Using unordered map to store distinct characters.
string removeDuplicates(string str) {
	    unordered_map<char,int> mp;
	    string ans ="";
	    
	    for (auto i:str){
	        if (mp[i]==0){
	            mp[i]++;
	            ans += i;
	        }
	    }
	    return ans;
	}
