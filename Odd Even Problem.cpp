// T.C = O(n), where n is size of string.
// S.C = O(1), since at max 26 characters will be stored in map which is still constant.
// Using unordered map.
string oddEven(string s) {
    int eChar=0,oChar=0;
    unordered_map<int,char> mp;
    
    for (auto i:s) mp[i]++;
    
    for (auto i:mp){
        if (i.first%2 == 0 && i.second%2 == 0) eChar++;
        else if (i.first%2 !=0 && i.second%2 !=0) oChar++;
    }
    
    int total = eChar+oChar;
    return ((total%2==0)? "EVEN" : "ODD");
    
}
