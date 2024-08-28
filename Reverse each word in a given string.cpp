// Approach: Using stack
// T.C = O(n)
// S.C = O(n)
// Logic: First reverse whole string and then store each dot separated string in stack.
// Now keep printing top of stack untill stack gets empty.
string reverseWords (string s)
{
    stack<string> stk;
    string newstr = "";
    reverse(s.begin(), s.end());
    int i=0, j=0, n = s.size();
    // Store strings in stack
    while(i<n && j<n){
        if (s[j] == '.'){
            stk.push(newstr);
            i = j+1;
            newstr = "";
        }
        else newstr += s[j];
        j++;
    }
    stk.push(newstr);  // Store remaining string in stack
    s.clear();  // clear actual string
    // Fill string with new string from stack
    while(!stk.empty()){
        s += stk.top() + '.';
        stk.pop();
    }
    s.pop_back();
    return s;
}
