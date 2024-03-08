// T.C = O(n)
// S.C = O(1)
// Using unordred map which will have max of 26 char in it so it's still constant space.
bool sameFreq(string s)
	{
	    unordered_map<char,int>mp;
	    int freqmin=INT_MAX, freqmax=INT_MIN, mincount=0, maxcount=0;
	    // Add freq of occurence of chars in map.
	    for (auto i:s){
	        mp[i]++;
	    }
	    // Store max and min freq.
	    for (auto i:mp){
	        freqmin = min(i.second, freqmin);
	        freqmax = max(i.second, freqmax);
	    }
	    // Count max freq occurence and min freq occurence in map
	    for (auto i:mp){
	        if (i.second == freqmax) maxcount++;
	        if (i.second == freqmin) mincount++;
	    }
      // Now it's IMPORTANT:
      // IF both max and min freq are equal then simply return true cuz we know they have same freq and hence we don't have to remove any char from string to make the freq equal.
      // OR IF difference between max and min freq is of just 1 AND count of max freq occurences in a map is only 1 then return true.
      // E.g: first case= "aababb", second case= "badd" :-in this case max freq will be 2 and min freq will be 1 and max freq count = 1 and min freq count = 2.
	    if (freqmin==freqmax or (freqmax-1 == freqmin and maxcount==1)) return true;
	    // And IF the case is, we have count of min freq as 1 and min freq is 1 so we can remove min freq char to make frequencies equal,
      // and to do this we can check if min freq count and min freq both are 1, also check IF the sum of max freq count and min freq count = size of map.
      // This is because we know the freq counts are of only max and min freq and not the middle frequencies, so we need to check this out.
      // E.g: "ececccddca":- in this case max freq will be 5 and min freq will be 1 and max freq count = 1 and min freq count = 1.
      // We can see that both min and max freq are same but this is not a possible string.
      // And since we are only counting max and min frequencies thus we need to check if total freq are same as the size of map.
      // If there are any other frequencies other than max and min freq then we have to return false cuz we can't equalize the freq of every other char in string,
      // we can only remove at most one char.
      if (mincount==1 and freqmin==1 and maxcount+mincount==mp.size()) return true;
	    
	    return false;
	}
