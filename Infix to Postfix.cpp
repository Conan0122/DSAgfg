// T.C = O(n)
// S.C = O(n)
// Using stack
int prec(char s){
    if (s == '+' || s== '-') return 1;
    else if (s == '*' || s== '/') return 2;
    else if (s == '^') return 3;
    return -1;
}

// Function to convert an infix expression to a postfix expression.
string infixToPostfix(string s) {
    string ans="";
    stack<char>st;
    
    for (auto i:s){
        // IF i is operand, push it into stack
        if ( (i >= 'a' && i <= 'z') || 
            (i >= 'A' && i <= 'Z') || 
            (i >= '0' && i <= '9') ){
            ans += i;
        }
        // IF i is '(', push it into stack
        else if (i == '('){
            st.push(i);
        }
        // IF i is ')' then add stack's top into answer string untill we get '(',
        // or until stack is empty.
        // Now remove top of stack before moving to next character,
        // to remove '(' from stack.
        else if (i == ')'){
            while (!st.empty() && st.top() != '('){
                int a = st.top();
                ans += a;
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        // If i is an operator then we have to keep on checking for precedence
        // of i with each stack's top until i's precedence is greater.
        // 
        else{
            while (!st.empty() && prec(i) <= prec(st.top())){
                ans += st.top();
                st.pop();
            }
            st.push(i);
        }
    }
    
    while (!st.empty()){
        ans += st.top();
        st.pop();
    }
    
    return ans;
}
