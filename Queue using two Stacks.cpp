// T.C = O(n) and O(1) for pop and push respectively.
// S.C = O(1)
// Push is just simple push operation in stack in case of T.C O(n) for pop.
// For pop operation we have to first pop all element until our s1 size is equal to 1 and at the same time keep on storing those popped value in stack2.
// Now pop top element from left in s1 and copy all the elements from s2 to s1 (so that we can perform our pop operation on s1 next time as well.
void StackQueue :: push(int x)
{
    s1.push(x);
}

int StackQueue :: pop()
{
    if (s1.empty()) return -1;
    while (s1.size()!=1){
        s2.push(s1.top());
        s1.pop();
    }
    
    int ans = s1.top();
    s1.pop();
    
    // Copy element from s1 to s2
    while (!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
    return ans;
}
