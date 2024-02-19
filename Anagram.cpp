// T.C = O(n)
// S.C = O(n)
// Using unordered map.
bool isAnagram(string a, string b){
        int na = a.size(), nb = b.size();
        
        if (na!=nb) return false;
        unordered_map<char,int>ump;
        
        for (auto i:b){
            ump[i]++;
        }
        
        int index=0;
        for (auto i:a){
            if (ump[a[index]] == 0){
                return false;
            }
            ump[a[index]]--;
            index++;
        }
        
        return true;
    }

///////////////////////////////////////////////////////////////
// T.C = O(n)
// S.C = O(1)
// With the help of ascii values.
// Create an array of size 26(english alphabets) with 0 in each index.
// IF both strings aren't of same size then return false.
bool isAnagram(string a, string b){
        vector<int> v(26,0);
        if (a.size() != b.size()) return false;
        // Now first increment the element in a[i]-'a' index.
        // if a[i] = 'g' then we increment the index 'g' - 'a' which will be (ascii of 'g')-(ascii of 'a') i.e. 103-97 = 6.
        // So we increment index 6 by one.
        // At the same time we will decrement the element of b[i]-'a' index.
        for (int i=0; i<a.size(); i++){
            v[a[i] - 'a']++;
            v[b[i] - 'a']--;
        }
        // Now check all the index of an array,
        // IF we see any element either -ve or +ve (other than 0) then we know the strings weren't anagram.
        for (int i=0; i<26; i++){
            if (v[i]!=0) return false;
        }
        return true;
}
