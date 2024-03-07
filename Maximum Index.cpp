// T.C = o(n)
// S.C = o(n)
// Using stack: It's a monotonic stack related problem.
// We just need to get the max from right and min from left which has max index difference.
// And to achieve this we can store max value's index in stack from right of array till 0 index.
// Now using another loop we can iterate from left of an array and keep on checking for min element of an array or array index in stack's top.
int maxIndexDiff(int a[], int n) 
    {
        if (n==1) return 0;
        
        int maxdif=INT_MIN, j=0;
        stack<int>st;
        st.push(n-1);
        // Store max elements of arr from right in stack.
        for (int i=n-2; i>=0; i--){
            if (a[st.top()]<a[i]) st.push(i);
        }
        
        while (!st.empty() && j<n){
            // IF stack's top < j then we know it can't have max differnece index as they are same index or lower index.
            if (st.top()<j) st.pop();
            // IF arr element at stack's top index > element at j index then,
            // simply assign maxdif and pop the stack top without incrementing j.
            // We aren't incrementing j in this case because we want to check if current j element is can still produce max index difference by comparing it with next element in stack.
            if (a[st.top()]>=a[j]){
                maxdif = max( maxdif, (st.top()-j) );
                st.pop();
                continue;
            }
            j++;
        }
        
        return maxdif;
    }
