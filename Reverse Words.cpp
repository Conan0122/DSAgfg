// T.C = O(n)
// S.C = O(n)
// Using stack
// Just keep on storing words in stack until we reach at ".".
// After all words are pushed into stack we can use stack's reverse property which allows us to reverse to store in a ans string.
// Return the answer string after removing first character from it since we know first character is "." and we dont need that at the start of ans.
string reverseWords(string S) 
{ 
    stack<string>stk;
    string ans="";
    int n = S.size();
    string temp = "";
    for (auto s: S){
        if (s=='.'){
            stk.push(temp);
            temp="";
        }
        else temp+=s;
    }
    stk.push(temp);
    while(!stk.empty()){
        ans += "." + stk.top();
        stk.pop();
    }
    return ans.substr(1, ans.size());
} 

//////////////////////////////////////////////////////////////////////
// Approach 2: Can be solved using two pointers.
// First reverse whole string.
// Now reverse just the words. Using two pointer track word's start and end.
