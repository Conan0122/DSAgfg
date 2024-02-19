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
