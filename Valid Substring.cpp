// T.C = O(n)
// S.C = O(n)
// Using Stacks: store all the index (which aren't helping in creating valid substring) in index.
// Now we have stack with elements which are not contributing in creating valid substring.
// Get the difference between length of initial string - 1 and stack's top index(cuz we know the difference between length of string and top index will give us the size of valid substring we had in string.
// pop stack's top and assign it as length of string.
// Return max of max substring count or recent length of string which we get after the second loop, because there might be a case that all parenthesis are forming valid substring except the last parenthesis.
// And normally we will get 0 by taking out difference, that's we since we already know all are valid parenthesis before current parenthesis thus,
// we take the ans as length of current string.
int findMaxLen(string s) {
        stack<int> st;
        int n = s.size(), maxS=0;
        // Store index of each opening parenthesis
        for (int i=0; i<n; i++){
            if (s[i] == '('){
                st.push(i);
            }
            else{
                if (!st.empty() and s[st.top()] == '('){
                    st.pop();
                }
                else{
                    st.push(i);
                }
            }
        }
        
        // Now get the difference between each stack element and length of string from that index.
        while(!st.empty()){
            int t = st.top();
            st.pop();
            maxS = max(maxS, n-t-1);
            n = t;
        }
        // Return max of maxS or latest n value.
        return max(maxS, n);
    }
