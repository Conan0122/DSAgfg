// T.C = O(n)
// S.C = O(1)
// To be a valid max heap every parent should be greater than their child.
class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        if (n==1) return true;
        
        for (int i=0; i<n; i++){
            int lchild = ((i+1)*2)-1, rchild = ((i+1)*2);
            
            if (arr[i] < arr[lchild]){
                return false;
            }
            else if (rchild<=n){
                if (arr[rchild] > arr[i]) return false;
            }
        }
        return true;
    }
};
