// T.C = O(n)
// S.C = O(n)
// Using two pointer, one for array a and one for array b.
class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        stack<int>st;
        int i=0, j=0;
        int t = -1;
        
        while (i<N){
            // IF ith element of array a is same as jth element of array b then simple increment both pointer.
            // ELSE if jth element of array b is same as top element of stack then pop the element from stack and increment j.
            // ELSE just push current ith ele from array a and increment i.
            if (A[i]==B[j]){
                i++, j++;
            }
            else if (B[j] == t){
                st.pop();
                j++;
            }
            else{
                st.push(A[i]);
                i++;
            }
            // IF stack isn't empty then store stack's top element in a variable.
            if (!st.empty()) t = st.top();
        }
        // In case when our array a is traversed till the end and we are yet to traverse array b,
        // we will traverse arr b and check each ele with what's in stack's top.
        while (j<N && !st.empty()){
            int tp = st.top();
            if (B[j]!=tp) return 0;
            j++;
            st.pop();
        }
        return 1;
    }
};
