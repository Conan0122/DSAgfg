// T.C = O(n)
// S.C = O(n)
// Using stack.
// First check if size of string is even or not, if it is even then we procees further else just return -1 cuz we can't balance the string.
// Now IF we encounter open braces push it into stack,
// ELSE IF we counter close braces and stack isn't empty, pop the the ele from stack,
// ELSE push open braces in stack and increment the count.
int countRev (string s)
{
    int n = s.size();
    stack<char>st;
    
    if (n%2!=0) return -1;
    int count=0;
    
    for (int i=0; i<n; i++){
        
        if (s[i] == '{'){
            st.push(s[i]);
        }
        else if (s[i] == '}' && !st.empty()){
            st.pop();
        }
        else{
            s[i]='{';
            st.push('{');
            count++;
        }
    }
    // Now add the half the size of stack in count as we know we need to perform half of stack size to make remaining string a balanced one.
    count += (st.size())/2;
    return count;
}

/////////////////////////////////////////////////////////////////////////
// T.C = O(n)
// S.C = O(1)
// Without using stack.
// Just count the open braces and decrement it whenever we encounter close braces, but if we see close braces when there is no open braces,
// then just increment answer as well as open braces count.
int countRev (string s)
{
    int count=0, ans=0, n = s.size();
    if (n%2!=0) return -1;
    
    for (char i:s){
        if (i=='{'){
            count++;
        }
        else if (i=='}' and count==0){
            count++, ans++;
        }
        else{
            count--;
        }
    }
    // Now just add count/2 in ans because we will have count of extra open braces remaining in string.
    // For e.g: {{{{ and we that know to make it balance we need to change half of the string to close braces.
    ans += count/2;
    return ans;
}
