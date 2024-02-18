// T.C = O(n*n)
// T.C = O(n), where n is recursive call stack
// Using recursion:
void SortedInsert(stack<int> &s, int ele){
    // IF our stack is empty, OR IF our top element in stack is < ele then simply push ele into stack and return.
    if (s.empty() || s.top()<ele){
        s.push(ele);
        return;
    }
    // ELSE do the further recursive call with the ele we want to insert in a sorted position in a stack.
    int t = s.top();
    s.pop();
    SortedInsert(s,ele);
    s.push(t);
}

void mySort(stack<int> &st){
    if (st.empty()) return;
    
    int t = st.top();
    st.pop();
    mySort(st);
    SortedInsert(st, t);
}

void SortedStack :: sort()
{
    mySort(s);
}
