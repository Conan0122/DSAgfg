// T.C = O(n)
// S.C = O(1)
// Using XOR: it removes elements which occured twice in an array.
int findSingle(int n, int arr[]){
    int single = 0;
    for (int i=0; i<n; i++){
        single ^= arr[i];
    }
    
    return single;
}
